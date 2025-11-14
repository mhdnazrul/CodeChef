// problem link:https://codeforces.com/problemset/problem/26/B
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'

void solve() {
  string s;
  cin >> s;

  int open = 0, ans = 0;
  for (char c : s) {
      if (c == '(') open++;
      else if (open > 0) { 
          ans += 2;
          open--;
      }
  }

  cout << ans << "\n";
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