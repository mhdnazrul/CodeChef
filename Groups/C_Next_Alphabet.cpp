// problem link:https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/C
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
  char ch;
  cin >> ch;
  int int_of_char = ch;
  if (ch == 'z')
  {
    cout << "a" << '\n';
  }
  else if (int_of_char > 96 && int_of_char < 122)
  {
    char char_of_Target = int_of_char + 1;
    cout << char_of_Target << '\n';
  }
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