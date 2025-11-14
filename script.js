let allProblems = [];
let currentSort = { key: 'id', order: 'desc' }; // ডিফল্ট সর্টিং
let ratingChart = null;

document.addEventListener('DOMContentLoaded', () => {
    fetch('solutions.json')
        .then(res => res.json())
        .then(data => {
            // ডেটা ক্লিন করা (যাতে rating স্ট্রিং থাকলে নাম্বার হয়)
            allProblems = data.map(p => ({
                ...p,
                rating: p.rating ? parseInt(p.rating) : 0
            }));
            
            // প্রথমে সর্ট এবং রেন্ডার
            sortData('id', false); 
            updateStats(allProblems);
            renderChart(allProblems);
        });

    // সার্চ ফিল্টার লিসেনার
    document.getElementById('searchInput').addEventListener('input', filterData);
    document.getElementById('difficultyFilter').addEventListener('change', filterData);
});

// --- 1. Rendering Function ---
function renderTable(data) {
    const tbody = document.getElementById('table-body');
    tbody.innerHTML = '';

    if (data.length === 0) {
        document.getElementById('no-results').style.display = 'block';
        return;
    }
    document.getElementById('no-results').style.display = 'none';

    data.forEach(p => {
        // কালার লজিক
        let colorClass = 'diff-gray';
        if (p.rating >= 1200) colorClass = 'diff-green';
        if (p.rating >= 1400) colorClass = 'diff-cyan';
        if (p.rating >= 1600) colorClass = 'diff-blue';
        if (p.rating >= 1900) colorClass = 'diff-violet';

        const tagsHtml = p.tags.slice(0, 2).map(t => `<span class="tag-badge">${t}</span>`).join('');
        const moreTags = p.tags.length > 2 ? `<span class="tag-badge">+${p.tags.length - 2}</span>` : '';

        const row = document.createElement('tr');
        row.innerHTML = `
            <td><strong>${p.id}</strong></td>
            <td>${p.name}</td>
            <td><span class="difficulty-badge ${colorClass}">${p.rating || '-'}</span></td>
            <td>${tagsHtml}${moreTags}</td>
            <td>
                <a href="${p.q_link}" target="_blank" class="btn-icon" title="Question"><i class="fas fa-external-link-alt"></i></a>
                <a href="${p.sol_path}" target="_blank" class="btn-code" title="Solution"><i class="fas fa-code"></i> Code</a>
            </td>
        `;
        tbody.appendChild(row);
    });
}

// --- 2. Sorting Logic ---
function sortTable(key) {
    // টগল অর্ডার: যদি একই কিতে ক্লিক করে, অর্ডার উল্টে যাবে
    if (currentSort.key === key) {
        currentSort.order = currentSort.order === 'asc' ? 'desc' : 'asc';
    } else {
        currentSort.key = key;
        currentSort.order = 'asc'; // নতুন কলামে ক্লিক করলে ডিফল্ট asc
    }
    
    sortData(key);
}

function sortData(key, render = true) {
    const orderMult = currentSort.order === 'asc' ? 1 : -1;

    allProblems.sort((a, b) => {
        let valA = a[key];
        let valB = b[key];

        // ID সর্টিং (Example: 4A vs 10B handling)
        if (key === 'id') {
             return a.id.localeCompare(b.id, undefined, { numeric: true, sensitivity: 'base' }) * orderMult;
        }
        
        // স্ট্রিং সর্টিং (Name)
        if (typeof valA === 'string') {
            return valA.localeCompare(valB) * orderMult;
        }
        
        // নাম্বার সর্টিং (Rating)
        return (valA - valB) * orderMult;
    });

    if (render) filterData(); // সর্টিং এর পর বর্তমান ফিল্টার অনুযায়ী রেন্ডার
}

// --- 3. Filter Logic ---
function filterData() {
    const term = document.getElementById('searchInput').value.toLowerCase();
    const diff = document.getElementById('difficultyFilter').value;

    const filtered = allProblems.filter(p => {
        const matchesSearch = p.name.toLowerCase().includes(term) || p.id.toLowerCase().includes(term);
        let matchesDiff = true;
        
        if (diff !== 'all') {
            const target = parseInt(diff);
            // রেঞ্জ লজিক: 800 সিলেক্ট করলে 800-999 দেখাবে
            if (target === 1800) matchesDiff = p.rating >= 1800;
            else matchesDiff = p.rating >= target && p.rating < target + 200;
        }
        return matchesSearch && matchesDiff;
    });

    renderTable(filtered);
}

// --- 4. Statistics & Chart ---
function updateStats(data) {
    document.getElementById('total-solved').innerText = data.length;
    const rated = data.filter(p => p.rating > 0);
    if (rated.length) {
        const avg = Math.round(rated.reduce((a, b) => a + b.rating, 0) / rated.length);
        document.getElementById('avg-rating').innerText = avg;
        document.getElementById('max-rating').innerText = Math.max(...rated.map(p => p.rating));
    }
}

function renderChart(data) {
    const ctx = document.getElementById('ratingChart').getContext('2d');
    
    // রেটিং কাউন্ট করা
    const ratingCounts = {};
    data.forEach(p => {
        if (p.rating > 0) {
            ratingCounts[p.rating] = (ratingCounts[p.rating] || 0) + 1;
        }
    });

    // অবজেক্ট কি (keys) সর্ট করা
    const labels = Object.keys(ratingCounts).sort((a, b) => a - b);
    const values = labels.map(r => ratingCounts[r]);

    if (ratingChart) ratingChart.destroy(); // আগের চার্ট থাকলে ডিলিট

    ratingChart = new Chart(ctx, {
        type: 'bar',
        data: {
            labels: labels,
            datasets: [{
                label: 'Solved by Rating',
                data: values,
                backgroundColor: '#3498db',
                borderRadius: 4,
                hoverBackgroundColor: '#1abc9c'
            }]
        },
        options: {
            responsive: true,
            maintainAspectRatio: false,
            plugins: {
                legend: { display: false },
                title: { display: true, text: 'Solved Distribution' }
            },
            scales: {
                y: { beginAtZero: true, ticks: { stepSize: 1 } },
                x: { grid: { display: false } }
            }
        }
    });
}