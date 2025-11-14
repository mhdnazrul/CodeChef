// problem link: https://codeforces.com/contest/2146/problem/B
// Author: nazrulislam_7 
#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m + 1, 0);
    vector<int> cnt(m + 1, 0);
    vector<char> flag(n + 1, 0);
    int cnt_set = 0;
    bool check = true;
    
    for (int i = 1; i <= n; ++i) {
        int l;
        cin >> l;
        for (int j = 0; j < l; ++j) {
            int a;
            cin >> a;
            if (cnt[a] == 0) {
                v[a] = i;
            } else {
                v[a] = 0;
            }
            ++cnt[a];
        }
    }
    
    for (int i = 1; i <= m; ++i) {
        if (cnt[i] == 0) {
            check = false;
            break;
        }
        if (v[i] > 0) {
            int set_id = v[i];
            if (!flag[set_id]) {
                flag[set_id] = 1;
                ++cnt_set;
            }
        }
    }
    
    if (!check || cnt_set >= n - 1) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        solve();
    }
    return 0;
}