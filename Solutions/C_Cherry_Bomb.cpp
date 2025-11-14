// problem link:https://codeforces.com/problemset/problem/2106/C
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
    ll n, k;    cin >> n >> k;
    vector<ll> a(n), b(n);
    readV(a); readV(b);    
    ll sum = -1;
    bool ok = true;
    for (int i = 0; i < n; ++i){
      if (b[i] != -1){
        if (sum == -1)sum = a[i] + b[i];
        else if (a[i] + b[i] != sum){ok = false; break;}
      }
    }

    if (!ok){cout << 0 << "\n";return;}
    if (sum == -1){
      ll l = 0, r = 2 * k;
      for (int i = 0; i < n; ++i){
        l = max(l, a[i]);
        r = min(r, a[i] + k);
      }

      if (l > r)cout << 0 << "\n";
      else cout << (r - l + 1) << "\n";
    }
    else{
      for (int i = 0; i < n; ++i){
        if (b[i] == -1) {
          ll val = sum - a[i];
          if (val < 0 || val > k){ok = false;break;}
        }
      }
      cout << (ok ? 1 : 0) << "\n";
    }
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