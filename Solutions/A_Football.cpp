// problem link:https://codeforces.com/problemset/problem/96/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
void solve() {
  string str; cin >> str;
  int zero = 0, ones = 0, stk = 0;
  for (char x : str) {
      if (x == '0') { zero++; ones = 0; }
      else { zero = 0; ones++; }
      stk = max(stk, max(ones, zero));
  }
  cout << (stk >= 7 ? "YES\n" : "NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    //cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}