// problem link:https://codeforces.com/problemset/problem/2106/B
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
  int n,x;  cin>>n>>x;
  vector<int> result;
  for (int i = x - 1; i >= 0; --i)
    result.push_back(i);
  for (int i = n - 1; i > x; --i)
    result.push_back(i);
  if (x < n)
    result.push_back(x);
  for (int num : result)
    cout << num << " ";
  cout << "\n";
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