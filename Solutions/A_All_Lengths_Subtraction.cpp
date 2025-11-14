// problem link:https://codeforces.com/contest/2143/problem/A
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
        cin >> n;
        vector<int> vec(n + 1);
        for (int i = 0; i < n; ++i){
         int x;     cin >> x;
         vec[x] = i;
        }
       
        int l = 0,r = n - 1;
        bool ok = true;
        for (int k = 1; k <= n; ++k)
        {
         int current_pos = vec[k];
         if (current_pos == l)l++;
         else if (current_pos == r)r--;
         else{
          ok = false;
          break;
         }
    } 
        cout<<(ok?"YES\n":"NO\n");      
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