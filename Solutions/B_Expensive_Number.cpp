// problem link:https://codeforces.com/problemset/problem/2093/B
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
    string s;    cin >> s;
    int n = s.size();
    double mn = 1e18;
    int del = n - 1;
    for (int m = 1; m < (1 << n); ++m) {
        ll number = 0;
        int digitSum = 0;
        bool started = false;
        for (int i = 0; i < n; ++i) {
            if (m & (1 << i)) {
                int d = s[i] - '0';
                digitSum += d;
                if (started || d != 0) {
                    number = number * 10 + d;
                    started = true;
                }
            }
        }
        if (digitSum == 0) continue;
        double cost = static_cast<double>(number) / digitSum;
        int removed = n - __builtin_popcount(m);
        if (cost < mn || (abs(cost - mn) < 1e-9 && removed < del)) {
            mn = cost;
            del = removed;
        }
    }
    cout << del << nl;
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