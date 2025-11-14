// problem link:https://codeforces.com/contest/2164/problem/A
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
    int n;
    cin >> n;
    vector<ll> a(n);
    readV(a);
    ll x;
    cin >> x;

    if (n == 1) {cout << (a[0] == x ? "YES\n" : "NO\n"); return;}

    bool ok = false;
    for (int i = 0; i< n-1; ++i) {
        ll mn = min(a[i], a[i+1]);
        ll mx = max(a[i], a[i+1]);
        if (mn <= x && x <= mx) { ok = true; break; }
    }
    cout << (ok ? "YES\n" : "NO\n");
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