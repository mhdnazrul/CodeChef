// problem link:https://codeforces.com/problemset/problem/1535/B
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
    int n;  cin>>n;
    vector<int> v(n),odd,even;
    readV(v);
    for(auto x: v){
        if(x%2==0)even.push_back(x);
        else odd.push_back(x);
    }
    vector<int> mix;
    for (int x : even) mix.push_back(x);
    for (int x : odd) mix.push_back(x);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (__gcd(mix[i], 2 * mix[j]) > 1) ans++;
        }
    }
    cout<<ans<<nl;
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