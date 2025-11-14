// problem link:https://codeforces.com/problemset/problem/598/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
void solve() {
    ll n;   cin>>n;
    ll total_sum = (n*(n+1))/2;
    ll p = 1, powerSum = 0;
    while(p<=n){
        powerSum+=p; 
        p*=2;
    }
    ll ans = total_sum - (2*powerSum);
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
