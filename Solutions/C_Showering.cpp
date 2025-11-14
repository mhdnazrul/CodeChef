// problem link:https://codeforces.com/contest/1999/problem/C
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
    int n, s, m; cin >> n >> s >> m;
    bool OK = false;
    int l[n], r[n];
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
        if(i == 0 && l[i] - 0 >= s) OK = true;
        else if(i == n - 1 && m - r[i] >= s) OK = true;
        else{
            if(l[i] - r[i - 1] >= s) OK = true;
        }
    }
    (OK) ? cout << "YES\n" : cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    if(!(cin>>test_cases)) return 0;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}