// problem link:https://codeforces.com/contest/2169/problem/A
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
    ll n,a;    cin >> n >> a;
    vector<ll> v(n);    readV(v);
    int lf = lower_bound(all(v), a) - v.begin();
    int rt = v.end() - upper_bound(all(v), a);
    cout<<(lf>rt?a-1:a+1)<<nl;
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