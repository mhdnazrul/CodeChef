// problem link:https://codeforces.com/gym/106188/problem/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }
#define MOD 1000000007
void solve() {
    int n;    cin >> n;
    vector<ll> a(n);    readV(a);
    ll result = 0;
    ll p = 1;
    bool ok = false;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            if (ok) {
                result = (result + p) % MOD;
                ok = false;
                p = 1;
            }
        } else {
            p = (p * (a[i] % MOD)) % MOD;
            ok = true;
        }
    }
    if (ok) result = (result + p) % MOD;
    cout << result % MOD << nl;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    //if(!(cin>>test_cases)) return 0;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
