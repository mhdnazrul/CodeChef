// problem link:https://codeforces.com/problemset/problem/2106/A
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
  int n;
  string s;
  cin >> n >> s;

  int total_ones = 0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      char bit = s[j];
      if (j == i)
      {
        bit = (bit == '0') ? '1' : '0';
      }
      if (bit == '1')
      {
        ++total_ones;
      }
    }
  }

  cout << total_ones << endl;
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