// problem link:https://codeforces.com/contest/2169/problem/C
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
    int n;    cin >> n;
    vector<ll> a(n);    readV(a);
    vector<ll> store(n + 1, 0);
    for(int i = 0; i < n; ++i) store[i+1] = store[i] + a[i];
    
    ll end_val = store[n], mx = 0, mn = 0; 
    for(ll i = 1; i <= n; ++i) {
        ll idx = i*i + i;
        ll dif = idx - store[i];
        mx = max(mx, dif - mn);
        mn = min(mn, dif);
    }
    cout << end_val + mx << nl;
}
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
    // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}