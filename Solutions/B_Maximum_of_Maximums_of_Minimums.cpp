// problem link:https://codeforces.com/contest/872/problem/B
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
    int n ,k;   cin>> n >> k;
    vector<int> a(n);
    int mn=INT_MAX, mx=INT_MIN;
    for(int i=0; i<n; i++){
        cin>> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    if(k==2){mx = max(a[0], a[n-1]);}
    cout<<(k==1? mn:mx)<<nl;
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