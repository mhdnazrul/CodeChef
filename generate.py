import os
import json
import re
import requests
import urllib.parse

# ---------------- CONFIGURATION ----------------
DIRECTORIES = ["Solutions", "Gyms", "Groups"]
WEB_DIR = "Web"
# সব ধরণের সোর্স ফাইল এক্সটেনশন
EXTENSIONS = {".cpp", ".c", ".py", ".java", ".js", ".kt", ".cs"}
CF_API_URL = "https://codeforces.com/api/problemset.problems"
REPO_URL = "https://github.com/mhdnazrul/CodeChef" # আপনার সঠিক ইউজারনেম ও রিপো নাম দিন

# ডেটা স্টোরেজ
seen_files = set()
problems_data = []
stats = {"total": 0, "by_rating": {}, "by_tag": {}}
cf_problems_cache = {}

# ---------------- HELPER FUNCTIONS ----------------

def get_cf_problems():
    """Codeforces API থেকে সব পাবলিক প্রবলেম লোড করে"""
    try:
        print("📡 Fetching Codeforces problemset from API...")
        resp = requests.get(CF_API_URL, timeout=15).json()
        if resp["status"] == "OK":
            for p in resp["result"]["problems"]:
                # ID format: 4A, 1200B etc.
                pid = f"{p.get('contestId')}{p.get('index')}"
                cf_problems_cache[pid] = p
        print(f"✅ Loaded {len(cf_problems_cache)} problems from API.")
    except Exception as e:
        print(f"⚠️ API Error: {e}. Using offline mode.")

def sanitize_filename(filename):
    """ফাইলের নাম ক্লিন করে snake_case এ কনভার্ট করে"""
    name, ext = os.path.splitext(filename)
    new_name = re.sub(r'[^a-zA-Z0-9]', '_', name)
    new_name = re.sub(r'_+', '_', new_name).strip('_')
    return f"{new_name}{ext}"

def get_fallback_rating(folder, index):
    """
    আপনার লজিক অনুযায়ী ডিফল্ট রেটিং নির্ধারণ:
    1. Gyms ফোল্ডার অথবা I-Z ইনডেক্স -> 900
    2. Groups/Solutions এবং A-H ইনডেক্স -> 800
    """
    # ১. যদি ইনডেক্স I থেকে Z এর মধ্যে হয় (যেকোনো ফোল্ডারে)
    if index and index.upper() >= 'I' and index.upper() <= 'Z':
        return 900
    
    # ২. যদি Gyms ফোল্ডারে থাকে
    if folder == "Gyms":
        return 900
        
    # ৩. বাকি সব ক্ষেত্রে (Groups, Solutions A-H)
    return 800

def detect_metadata(content, filename, folder_name):
    """
    লিংক ডিটেকশন এবং মেটাডেটা এক্সট্রাকশন (সব ফরম্যাটের জন্য)
    """
    link = None
    contest_id = None
    index = None

    # ১. ফাইলের কন্টেন্ট থেকে লিংক খোঁজা (Advanced Regex)
    patterns = [
        # Group Link: codeforces.com/group/ID/contest/123/problem/A
        r'(https?://codeforces\.com/group/[^/]+/contest/(\d+)/problem/(\w+))',
        # Gym Link: codeforces.com/gym/102938/problem/A
        r'(https?://codeforces\.com/gym/(\d+)/problem/(\w+))',
        # Standard Contest: codeforces.com/contest/123/problem/A
        r'(https?://codeforces\.com/contest/(\d+)/problem/(\w+))',
        # Problemset: codeforces.com/problemset/problem/123/A
        r'(https?://codeforces\.com/problemset/problem/(\d+)/(\w+))'
    ]

    for pattern in patterns:
        match = re.search(pattern, content)
        if match:
            link = match.group(1)
            contest_id = match.group(2)
            index = match.group(3)
            break

    # ২. যদি ফাইলে লিংক না থাকে, ফাইলের নাম থেকে বের করা (e.g., 1234A_Name.cpp)
    if not contest_id:
        # প্যাটার্ন: ১ বা একাধিক ডিজিট + ১ বা একাধিক লেটার + _
        name_match = re.match(r'^(\d+)([A-Z]+[0-9]?)_', filename, re.IGNORECASE)
        if name_match:
            contest_id = name_match.group(1)
            index = name_match.group(2).upper()
            
            # লিংক জেনারেট করা (ফোল্ডার অনুযায়ী)
            if folder_name == "Gyms":
                link = f"https://codeforces.com/gym/{contest_id}/problem/{index}"
            else:
                link = f"https://codeforces.com/contest/{contest_id}/problem/{index}"

    return link, contest_id, index

# ---------------- MAIN PROCESS ----------------

def process_files():
    get_cf_problems()
    
    if not os.path.exists(WEB_DIR):
        os.makedirs(WEB_DIR)

    for folder in DIRECTORIES:
        if not os.path.exists(folder):
            continue
            
        for root, _, files in os.walk(folder):
            for file in files:
                if not any(file.endswith(ext) for ext in EXTENSIONS):
                    continue

                original_path = os.path.join(root, file)
                
                # --- A. Rename Logic ---
                new_filename = sanitize_filename(file)
                new_path = os.path.join(root, new_filename)
                
                if original_path != new_path:
                    print(f"🔄 Renaming: {file} -> {new_filename}")
                    os.rename(original_path, new_path)
                    file = new_filename

                # --- B. Duplicate Check ---
                file_key = file.lower()
                if file_key in seen_files:
                    print(f"🗑️ Duplicate removed: {new_path}")
                    os.remove(new_path)
                    continue
                seen_files.add(file_key)

                # --- C. Metadata Extraction ---
                try:
                    with open(new_path, 'r', encoding='utf-8', errors='ignore') as f:
                        content = f.read(2000) # প্রথম ২০০০ ক্যারেক্টার চেক করবে
                except:
                    content = ""

                # ফোল্ডার নেম পাস করছি যাতে সঠিক লিংক জেনারেট হয়
                q_link, cid, idx = detect_metadata(content, file, folder)
                
                # ডিফল্ট নাম (ফাইলের নাম থেকে _ বাদ দিয়ে)
                p_name = new_filename.split('.')[0].replace('_', ' ')
                # ইনডেক্স এবং আইডি ক্লিন করা (e.g. 4A_ -> 4A)
                if cid and idx:
                    p_name_match = p_name.replace(f"{cid}{idx} ", "").replace(f"{cid}{idx}", "")
                    if p_name_match.strip(): p_name = p_name_match.strip()

                p_rating = 0
                p_tags = []
                full_id = f"{cid}{idx}" if cid else "N/A"

                # --- D. API থেকে ডেটা আনা ---
                if full_id in cf_problems_cache:
                    data = cf_problems_cache[full_id]
                    p_name = data.get("name", p_name)
                    p_rating = data.get("rating", 0)
                    p_tags = data.get("tags", [])
                
                # --- E. Fallback Rating Logic (Your Requirement) ---
                # যদি API রেটিং না দেয় বা ০ থাকে
                if p_rating == 0:
                    p_rating = get_fallback_rating(folder, idx)
                    # যদি ট্যাগ না থাকে, ডিফল্ট ট্যাগ
                    if not p_tags:
                        p_tags = ["implementation"]

                # --- F. Solution Path ---
                # উইন্ডোজের ব্যাকস্ল্যাশ (\) কে স্ল্যাশ (/) এ পরিবর্তন
                rel_path = os.path.join(folder, file).replace("\\", "/")
                
                prob_entry = {
                    "id": full_id,
                    "name": p_name,
                    "rating": p_rating,
                    "tags": p_tags,
                    "q_link": q_link if q_link else "#", # Question Link
                    "sol_path": rel_path,                # Solution Link (Local File)
                    "filename": file
                }
                problems_data.append(prob_entry)
                
                # Stats Update
                stats["total"] += 1
                if p_rating > 0:
                    stats["by_rating"][p_rating] = stats["by_rating"].get(p_rating, 0) + 1

    # JSON Save
    with open(os.path.join(WEB_DIR, "solutions.json"), "w", encoding='utf-8') as f:
        json.dump(problems_data, f, indent=2)
    
    print("✅ solutions.json generated.")
    generate_readme()

# ---------------- README GENERATOR ----------------

def generate_readme():
    print("📝 Generating README.md...")
    
    # সর্টিং: রেটিং (descending), তারপর ID
    sorted_probs = sorted(problems_data, key=lambda x: (x['rating'], x['id']), reverse=True)
    
    md = f"""
<h1 align="center">Codeforces Solution Archive</h1>

<p align="center">
    <a href="https://{os.getenv('GITHUB_REPOSITORY_OWNER', 'YourUser')}.github.io/{os.getenv('GITHUB_REPOSITORY', 'Codeforces-Solutions').split('/')[-1]}/">
        <img src="https://img.shields.io/badge/View_Website-Click_Here-2ecc71?style=for-the-badge&logo=google-chrome&logoColor=white" alt="Website">
    </a>
</p>

<p align="center">
    <img src="https://img.shields.io/badge/Language-C++%20%7C%20Python-blue?style=for-the-badge&logo=c%2B%2B" alt="Language">
    <img src="https://img.shields.io/badge/Total%20Solved-{stats['total']}-00b894?style=for-the-badge&logo=codeforces" alt="Total">
</p>

<p align="center">
    <b>🚀 Find me on: </b>
    <a href="https://github.com/">GitHub</a> | 
    <a href="https://codeforces.com/">Codeforces</a> | 
    <a href="https://codeforces.com/">Codechef</a> |
    <a href="https://codeforces.com/">Linkedin </a> | 
    <a href="https://github.com/">Facebook</a>
</p>

---

## 📊 Statistics

**Total Problems Solved:** {stats['total']}

<details>
<summary><b>Click to view breakdown by Difficulty</b></summary>

| Difficulty | Count |
| :--- | :--- |
"""
    for r in sorted(stats['by_rating'].keys()):
        md += f"| {r} | {stats['by_rating'][r]} |\n"
        
    md += """
</details>

---

<h2 align="center">📋 Solution Index</h2>

| Problem ID | Problem Name | Difficulty ⇅ | Tags | Question | Solution |
| :---: | :--- | :---: | :--- | :---: | :---: |
"""

    # টেবিলে লিংক যুক্ত করা (REPO_URL ব্যবহার করে)
    # যাতে README থেকে ক্লিক করলে ফাইল ওপেন হয়
    for p in sorted_probs:
        tags_display = ", ".join([f"`{t}`" for t in p['tags'][:2]])
        if len(p['tags']) > 2: tags_display += ", ..."
        
        rating_display = p['rating'] if p['rating'] > 0 else "-"
        
        # Solution link (repo link)
        sol_full_link = f"{REPO_URL}/{p['sol_path']}"
        
        row = f"| {p['id']} | {p['name']} | {rating_display} | {tags_display} | [View]({p['q_link']}) | [Code]({p['sol_full_link'] if 'http' in p['sol_path'] else sol_full_link}) |\n"
        md += row

    md += """
<br>
<p align="center"><i>Auto-generated by <a href="Web/generate.py">generate.py</a></i></p>
"""

    with open("README.md", "w", encoding="utf-8") as f:
        f.write(md)
    print("✅ README.md updated successfully!")

if __name__ == "__main__":
    process_files()