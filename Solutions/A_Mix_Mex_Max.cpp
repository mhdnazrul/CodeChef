// problem link:https://codeforces.com/problemset/problem/2127/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    readV(a);
    vector<int> b;
    for (int x : a) if (x != -1) b.push_back(x);
    if (b.empty()) {cout << "YES\n";return;}
    bool all_equal = true;
    for (int i = 1; i < (int)b.size(); ++i) {
        if (b[i] != b[0]) { all_equal = false; break; }
    }

    if (all_equal && b[0] != 0) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
