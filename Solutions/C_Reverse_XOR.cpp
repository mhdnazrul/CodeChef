// problem link:https://codeforces.com/problemset/problem/2160/C
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
    ll n; cin >> n;
    bool ans = 1;
    if(((__builtin_popcount(n))&1))
        ans = 0;
    else
    {
        int k = 0;
        for(int i=0; (1<<i)<=n; i++)
            k = i;
        
        k += (__builtin_ctz(n));

        for(int i=0; (1<<i)<=n; i++)
        {
            if((((1<<i)&n)>0) != (((1<<(k-i))&n)>0))
                ans = 0;

        }
    }
    cout << ( ans ? "YES" : "NO" ) << '\n';
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
