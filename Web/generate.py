import os
import json
import re
import requests
import urllib.parse

# ---------------- CONFIGURATION ----------------
DIRECTORIES = ["Solutions", "Gyms", "Groups"]  # স্ক্যান করার ফোল্ডার
WEB_DIR = "Web"
EXTENSIONS = {".cpp", ".c", ".py", ".java", ".js"}
CF_API_URL = "https://codeforces.com/api/problemset.problems"
REPO_URL = "https://github.com/mhdnazrul/CodeChef" # আপনার রিপোর লিংক এখানে দিন

# ডেটা স্টোরেজ
seen_files = set()       # ডুপ্লিকেট চেক করার জন্য
problems_data = []       # সব প্রবলেমের ডেটা লিস্ট
stats = {"total": 0, "by_rating": {}, "by_tag": {}}
cf_problems_cache = {}   # API ডেটা ক্যাশ

# ---------------- HELPER FUNCTIONS ----------------

def get_cf_problems():
    """Codeforces API থেকে সব পাবলিক প্রবলেম লোড করে"""
    try:
        print("📡 Fetching Codeforces problemset from API...")
        resp = requests.get(CF_API_URL, timeout=10).json()
        if resp["status"] == "OK":
            for p in resp["result"]["problems"]:
                # ID format: 4A, 1200B etc.
                pid = f"{p.get('contestId')}{p.get('index')}"
                cf_problems_cache[pid] = p
        print(f"✅ Loaded {len(cf_problems_cache)} problems from API.")
    except Exception as e:
        print(f"⚠️ API Error: {e}. Using offline mode for metadata.")

def sanitize_filename(filename):
    """ফাইলের নাম ক্লিন করে snake_case এ কনভার্ট করে"""
    name, ext = os.path.splitext(filename)
    # স্পেস এবং বিশেষ ক্যারেক্টার রিমুভ করে আন্ডারস্কোর দেওয়া
    new_name = re.sub(r'[^a-zA-Z0-9]', '_', name)
    new_name = re.sub(r'_+', '_', new_name).strip('_')
    return f"{new_name}{ext}"

def detect_problem_link(content, filename):
    """
    ফাইলের কমেন্ট থেকে লিংক খুঁজে বের করে।
    এটি Gym, Group, Contest, Problemset সব ফরম্যাট সাপোর্ট করে।
    """
    # ১. ফাইলের ভিতরে লিংক খোঁজা (Regex দিয়ে)
    # Patterns:
    # - codeforces.com/contest/123/problem/A
    # - codeforces.com/problemset/problem/123/A
    # - codeforces.com/gym/102938/problem/A
    # - codeforces.com/group/AbCdEf/contest/123/problem/A
    
    patterns = [
        r'(https?://codeforces\.com/group/[^/]+/contest/(\d+)/problem/(\w+))',
        r'(https?://codeforces\.com/gym/(\d+)/problem/(\w+))',
        r'(https?://codeforces\.com/contest/(\d+)/problem/(\w+))',
        r'(https?://codeforces\.com/problemset/problem/(\d+)/(\w+))'
    ]
    
    for pattern in patterns:
        match = re.search(pattern, content)
        if match:
            full_link = match.group(1)
            contest_id = match.group(2)
            index = match.group(3)
            return full_link, contest_id, index

    # ২. লিংক না পেলে ফাইলের নাম থেকে আইডি বের করার চেষ্টা (e.g. 4A_Watermelon.cpp)
    name_match = re.match(r'^(\d+)([A-Z][0-9]?)_', filename, re.IGNORECASE)
    if name_match:
        cid = name_match.group(1)
        idx = name_match.group(2)
        # ডিফল্ট লিংক জেনারেট করা
        return f"https://codeforces.com/contest/{cid}/problem/{idx}", cid, idx
        
    return None, None, None

def update_stats(rating):
    """স্ট্যাটিসটিকস আপডেট করে"""
    stats["total"] += 1
    
    # রেটিং গ্রুপিং (আপনার ছবির মতো)
    if rating == 0: return # রেটিং না থাকলে কাউন্ট করব না
    
    r_key = rating
    stats["by_rating"][r_key] = stats["by_rating"].get(r_key, 0) + 1

# ---------------- MAIN PROCESS ----------------

def process_files():
    get_cf_problems()
    
    if not os.path.exists(WEB_DIR):
        os.makedirs(WEB_DIR)

    for folder in DIRECTORIES:
        if not os.path.exists(folder):
            print(f"⚠️ Folder not found: {folder}")
            continue
            
        for root, _, files in os.walk(folder):
            for file in files:
                if not any(file.endswith(ext) for ext in EXTENSIONS):
                    continue

                original_path = os.path.join(root, file)
                
                # ১. অটোমেটিক রিনেমিং (Automatic Renaming)
                new_filename = sanitize_filename(file)
                new_path = os.path.join(root, new_filename)
                
                if original_path != new_path:
                    print(f"🔄 Renaming: {file} -> {new_filename}")
                    os.rename(original_path, new_path)
                    file = new_filename # আপডেট নাম

                # ২. ডুপ্লিকেট রিমুভাল (Duplicate Removal)
                # আমরা ফাইলের নাম দিয়ে চেক করছি (চাইলে কনটেন্ট হ্যাশ ব্যবহার করা যায়)
                file_key = file.lower()
                if file_key in seen_files:
                    print(f"🗑️ Duplicate removed: {new_path}")
                    os.remove(new_path)
                    continue
                seen_files.add(file_key)

                # ৩. মেটাডেটা ও লিংক ডিটেকশন
                try:
                    with open(new_path, 'r', encoding='utf-8', errors='ignore') as f:
                        content = f.read(1000) # প্রথম ১০০০ ক্যারেক্টার পড়লেই যথেষ্ট
                except:
                    content = ""

                link, contest_id, index = detect_problem_link(content, file)
                
                # API থেকে ডেটা ম্যাচিং
                p_name = new_filename.split('.')[0].replace('_', ' ') # ডিফল্ট নাম
                p_rating = 0
                p_tags = []
                
                full_id = f"{contest_id}{index}"
                
                if full_id in cf_problems_cache:
                    data = cf_problems_cache[full_id]
                    p_name = data.get("name", p_name)
                    p_rating = data.get("rating", 0)
                    p_tags = data.get("tags", [])
                
                # ওয়েবসাইটের জন্য ডেটা তৈরি
                # GitHub রিলেটিভ পাথ ঠিক করা (উইন্ডোজ ও লিনাক্স উভয়ের জন্য)
                rel_path = os.path.join(folder, file).replace("\\", "/")
                
                prob_entry = {
                    "id": full_id if contest_id else "N/A",
                    "name": p_name,
                    "rating": p_rating,
                    "tags": p_tags,
                    "q_link": link if link else "#",
                    "sol_path": rel_path,
                    "filename": file
                }
                problems_data.append(prob_entry)
                update_stats(p_rating)

    # JSON সেভ করা (ওয়েবসাইটের জন্য)
    with open(os.path.join(WEB_DIR, "solutions.json"), "w", encoding='utf-8') as f:
        json.dump(problems_data, f, indent=2)
    
    print("✅ solutions.json generated.")
    generate_readme()

# ---------------- README GENERATOR ----------------

def generate_readme():
    print("📝 Generating README.md...")
    
    # সর্টিং: প্রথমে রেটিং (কঠিন আগে), তারপর আইডি
    sorted_probs = sorted(problems_data, key=lambda x: (x['rating'], x['id']), reverse=True)
    
    # Markdown কন্টেন্ট শুরু
    # HTML ট্যাগ ব্যবহার করছি সেন্টারিং এর জন্য
    md = f"""
<h1 align="center">Codeforces Solution Archive</h1>

<p align="center">
    <img src="https://img.shields.io/badge/Language-C++%20%7C%20Python-blue?style=for-the-badge&logo=python" alt="Language">
    <img src="https://img.shields.io/badge/Total%20Solved-{stats['total']}-00b894?style=for-the-badge&logo=codeforces" alt="Total">
    <img src="https://img.shields.io/badge/Updated-Automatically-orange?style=for-the-badge" alt="Update">
</p>

<p align="center">
    Welcome to my organized archive of Competitive Programming solutions. <br>
    The repository is automatically updated and formatted using Python scripts and GitHub Actions.
</p>

<p align="center">
    <b>🚀 Find me on: </b> 
    <a href="https://codeforces.com/">Codeforces</a> | 
    <a href="https://github.com/">GitHub</a>
</p>

---

## 📊 Statistics

**Total Problems Solved:** {stats['total']}

<details>
<summary><b>Click to view breakdown by Rating</b></summary>

| Difficulty | Count |
| :--- | :--- |
"""
    
    # স্ট্যাটিসটিকস টেবিল (সর্টেড)
    for r in sorted(stats['by_rating'].keys()):
        md += f"| {r} | {stats['by_rating'][r]} |\n"
        
    md += """
</details>

---

<h2 align="center">📋 Solution Index</h2>

| ID | Problem Name | Difficulty | Tags | Question | Solution |
| :---: | :--- | :---: | :--- | :---: | :---: |
"""

    # মেইন টেবিল লুপ
    for p in sorted_probs:
        # ট্যাগ ফরম্যাটিং (২ টার বেশি হলে '...' দেখাবে)
        tags_display = ", ".join([f"`{t}`" for t in p['tags'][:2]])
        if len(p['tags']) > 2:
            tags_display += ", ..."
            
        # রেটিং না থাকলে '-'
        rating_display = p['rating'] if p['rating'] > 0 else "-"
        
        # সলিউশন লিংক (GitHub এর ফাইল ভিউ লিংক)
        # স্পেস থাকলে %20 দিয়ে রিপ্লেস করা হয়, যদিও আমাদের কোড আগেই নাম ক্লিন করে নিয়েছে
        sol_link = f"{REPO_URL}/{p['sol_path']}"
        
        row = f"| {p['id']} | {p['name']} | {rating_display} | {tags_display} | [Link]({p['q_link']}) | [Code]({p['sol_path']}) |\n"
        md += row

    md += """
<br>

<p align="center">
    <i>Auto-generated by <a href="Web/generate.py">generate.py</a></i>
</p>
"""

    with open("README.md", "w", encoding="utf-8") as f:
        f.write(md)
    print("✅ README.md updated successfully!")

if __name__ == "__main__":
    process_files()