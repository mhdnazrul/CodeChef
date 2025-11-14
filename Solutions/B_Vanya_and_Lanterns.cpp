// problem link:https://codeforces.com/problemset/problem/492/B
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
    int n; double l;    cin>>n>>l;
    vector<double> v(n);    readV(v);
    sort(all(v));
    double diff = 0;
    for(int i=0; i<n-1; i++){
        diff = max(diff, v[i+1] - v[i]);
    }
    double result = max({v[0], l - v[n-1], diff/2.0});
    cout<<fixed<<setprecision(10);
    cout<<result<<nl;
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