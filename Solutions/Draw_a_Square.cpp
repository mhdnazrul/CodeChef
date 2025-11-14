// problem link:https://codeforces.com/problemset/problem/2074/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'

void solve() {
  int l, r, d, u;
  cin >> l >> r >> d >> u;
  if (l == r && r == d && d == u)
    cout << "YES" << nl;
  else
    cout << "No" << nl;
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