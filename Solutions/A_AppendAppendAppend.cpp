// problem link:https://codeforces.com/problemset/gymProblem/104114/A
// Author: nazrulislam_7 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    vector<vector<int>> vec(n + 1, vector<int>(26, -1));

    for (int i = n - 1; i >= 0; --i) {
        vec[i] = vec[i + 1];
        vec[i][s[i] - 'a'] = i;
    }

    int days = 1;
    int idx = 0; 

    for (int i = 0; i < m; ++i) {
        int char_needed = t[i] - 'a'; 

        if (vec[idx][char_needed] == -1) {
            days++;
            idx = 0; 
        }
        
        int fnd_idx = vec[idx][char_needed];
        idx = fnd_idx + 1;
    }
    
    cout << days << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    for(int tc = 1; tc <= test_cases; tc++){
        solve();
    }
    return 0;
}