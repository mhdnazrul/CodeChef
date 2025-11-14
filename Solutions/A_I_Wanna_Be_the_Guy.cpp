// problem link:https://codeforces.com/problemset/problem/469/A
// Author ~ cf handle: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, p, t;  cin >> n >> p;
  set<int> st;
  for (int i = 0; i < p; i++) cin >> t, st.insert(t);
  int q;  cin >> q;
  for (int i = 0; i < q; i++) cin >> t, st.insert(t);
  cout << (n == st.size() ? "I become the guy.\n" : "Oh, my keyboard!\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    //cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}