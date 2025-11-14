// problem link:https://codeforces.com/problemset/problem/2128/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }
ll Floor_nums(ll x)
{
 ll res = 0;
 while ((1LL << (res + 1)) <= x)res++;
 return res;
}

void solve()
{
 ll n, c;
 cin >> n >> c;
 vector<ll> a(n);
 readV(a);
 sort(a.begin(), a.end());
 set<ll> nums;
 for (int i = 0; i < n; ++i)nums.insert(i);

 ll answer = 0;
 for (int i = 0; i < n; ++i)
 {
  ll wit = a[i], max_val = -1;
  if (wit <= c)
   max_val = Floor_nums(c / wit);

  auto it = nums.upper_bound(max_val);
  if (it == nums.begin())
  {
   answer++;
   if (!nums.empty())
    nums.erase(prev(nums.end()));
  }
  else
  {
   --it;
   nums.erase(it);
  }
 }
 cout << answer << endl;
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