// problem link:https://codeforces.com/contest/2145/problem/C
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
  int n;  cin >> n;
  string s;  cin >> s;
  int cnt_a = 0, cnt_b = 0;
  for (char c : s)
  {
    if (c == 'a')  cnt_a++;
    else  cnt_b++;
  }
  if (cnt_a == cnt_b){cout << 0 << "\n";return;}

  int diff = cnt_a - cnt_b;
  int cnt = 0, min_len = n;
  map<int, int> mp;
  mp[0] = 0;  
  for (int i = 0; i < n; ++i)
  {
    if (s[i] == 'a')  cnt++;
    else  cnt--;
    int balans = cnt - diff;
    if (mp.count(balans))
    {
      int st_ln = mp[balans];
      int crent_ln = (i + 1) - st_ln;
      min_len = min(min_len, crent_ln);
    }
    mp[cnt] = i + 1;
  }
  cout<< (min_len == n? -1:min_len) << "\n";
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