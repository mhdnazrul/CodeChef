// problem link:https://codeforces.com/contest/230/problem/A
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
    ll s,n;     cin>>s>>n;
    vector<pair<ll,ll>> vp(n);
    for(ll i = 0; i<n;i++){
        cin>>vp[i].first>>vp[i].second;
    }
    sort(all(vp));
    for(ll i=0; i<n;i++){
        if(s > vp[i].first) s+= vp[i].second;
        else {cout<<"NO\n";return;}
    }
    cout<<"YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    //if(!(cin>>test_cases)) return 0;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}