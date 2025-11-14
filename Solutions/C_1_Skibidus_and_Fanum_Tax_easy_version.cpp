// problem link:https://codeforces.com/contest/2065/problem/C1
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
    int n, m;    cin >> n >> m;
    vector<ll> Vn(n);    readV(Vn);
    vector<ll> Vm(m);    readV(Vm);
    ll b = Vm[0];    ll prev = -1e18;

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        ll op1 = Vn[i];
        ll op2 = b - Vn[i];
        bool ok1 = (op1 >= prev);
        bool ok2 = (op2 >= prev);

        if (ok1 && ok2) {
            prev = min(op1, op2);
        } else if (ok1) {
            prev = op1;
        } else if (ok2) {
            prev = op2;
        } else {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << nl;
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