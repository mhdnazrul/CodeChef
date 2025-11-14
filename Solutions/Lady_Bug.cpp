// problem link:https://codeforces.com/problemset/problem/2092/B
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'

void solve() {
  ll n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int f1 = 0, f2 = 0;

  for (int i = 0; i < n; ++i){
    if (i % 2){
      if(s1[i] == '1')f2--;
      if(s2[i] == '0')f1++;
    }
    else{
      if(s1[i] == '1') f1--;
      if(s2[i] == '0') f2++;
    }
  }
  cout << ((f1 >= 0 && f2 >= 0) ? "YES\n" : "NO\n");
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