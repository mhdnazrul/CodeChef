// problem link:https://codeforces.com/problemset/problem/2093/C
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }

bool isPrime(ll n)
{
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0)  return false;
  for (ll i = 5; i * i <= n; i += 6){
    if (n % i == 0 || n % (i + 2) == 0)return false;
  }
  return true;
}

void solve()
{
  int x, k;  cin >> x >> k;
  string temp = to_string(x);
  string str = "";
  for (int i = 0; i < k; ++i) str += temp;

  if (str.size() > 18) { cout << "NO\n";return;}
  ll n = stoll(str);
  cout<<(isPrime(n)? "YES\n":"NO\n");
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