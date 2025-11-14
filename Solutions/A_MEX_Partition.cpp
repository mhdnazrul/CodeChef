// problem link:https://codeforces.com/problemset/problem/2160/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }
void solve()
{
 int n,x, cnt = 0;  cin >> n; 
 vector<int> vec(102, 0);
 for (int i = 0; i < n; ++i)
 {
  cin >> x;
  if (x < 102)vec[x]++;
 }

 while (vec[cnt] > 0)cnt++;

 cout << cnt << endl;
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