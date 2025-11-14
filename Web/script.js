document.addEventListener('DOMContentLoaded', () => {
    const tableBody = document.getElementById('table-body');
    const searchInput = document.getElementById('searchInput');
    const difficultyFilter = document.getElementById('difficultyFilter');
    const noResults = document.getElementById('no-results');

    let allProblems = [];

    // 1. Load Data
    fetch('solutions.json')
        .then(res => res.json())
        .then(data => {
            allProblems = data;
            renderTable(data);
            calculateStats(data);
        })
        .catch(err => console.error('Error loading solutions:', err));

    // 2. Render Table Function
    function renderTable(data) {
        tableBody.innerHTML = '';

        if (data.length === 0) {
            noResults.style.display = 'block';
            return;
        } else {
            noResults.style.display = 'none';
        }

        data.forEach(p => {
            const row = document.createElement('tr');
            
            // Rating color logic
            let ratingClass = 'rating-gray';
            if (p.rating >= 1200) ratingClass = 'rating-green';
            if (p.rating >= 1400) ratingClass = 'rating-cyan';
            if (p.rating >= 1600) ratingClass = 'rating-blue';
            if (p.rating >= 1900) ratingClass = 'rating-violet';
            if (p.rating >= 2100) ratingClass = 'rating-orange';

            // Tags HTML
            const tagsHtml = p.tags.slice(0, 3).map(t => 
                `<span class="tag-badge">${t}</span>`
            ).join('');

            row.innerHTML = `
                <td><strong>${p.id}</strong></td>
                <td>${p.name}</td>
                <td><span class="rating-badge ${ratingClass}">${p.rating > 0 ? p.rating : '-'}</span></td>
                <td>${tagsHtml}</td>
                <td><a href="${p.q_link}" target="_blank" class="btn-link"><i class="fas fa-external-link-alt"></i> View</a></td>
                <td><a href="${p.sol_path}" target="_blank" class="btn-sol"><i class="fas fa-code"></i> Code</a></td>
            `;
            tableBody.appendChild(row);
        });
    }

    // 3. Filter & Search Logic
    function filterData() {
        const searchTerm = searchInput.value.toLowerCase();
        const difficulty = difficultyFilter.value;

        const filtered = allProblems.filter(p => {
            // Search Logic (ID or Name)
            const matchesSearch = 
                p.name.toLowerCase().includes(searchTerm) || 
                p.id.toLowerCase().includes(searchTerm);

            // Filter Logic (Difficulty)
            let matchesDiff = true;
            if (difficulty !== 'all') {
                const r = p.rating;
                const target = parseInt(difficulty);
                // Example range logic
                if (target === 1800) matchesDiff = r >= 1800;
                else matchesDiff = r >= target && r < target + 200;
            }

            return matchesSearch && matchesDiff;
        });

        renderTable(filtered);
    }

    // Event Listeners
    searchInput.addEventListener('input', filterData);
    difficultyFilter.addEventListener('change', filterData);

    // 4. Calculate Stats
    function calculateStats(data) {
        document.getElementById('total-solved').innerText = data.length;
        
        const ratedProblems = data.filter(p => p.rating > 0);
        if (ratedProblems.length > 0) {
            const totalRating = ratedProblems.reduce((sum, p) => sum + p.rating, 0);
            const maxRating = Math.max(...ratedProblems.map(p => p.rating));
            
            document.getElementById('avg-rating').innerText = Math.round(totalRating / ratedProblems.length);
            document.getElementById('max-rating').innerText = maxRating;
        }
    }
});