// problem link:https://codeforces.com/problemset/problem/1903/A
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
    int n, k;           cin >> n >> k;
    vector<ll> a(n);    readV(a);
    if(k == 1) {
        bool ok = true;
        for(int i = 1; i < n; i++) {
            if(a[i] < a[i-1]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    } else {cout << "YES\n";}
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

