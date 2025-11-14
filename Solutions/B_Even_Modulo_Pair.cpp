// problem link:https://codeforces.com/contest/2164/problem/B
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }
bool checkMOD(ll x, ll y) {
    if (x >= y) return false;
    ll rem = y % x;
    return (rem % 2 == 0); 
}
void solve() {
    int n; 
    cin >> n;
    vector<ll> a(n);
    readV(a);

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (checkMOD(a[i], a[j])) {
                cout << a[i] << ' ' << a[j] << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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