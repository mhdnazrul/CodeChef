// problem link:https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'

void solve() {
    double p,x;  cin>>p>>x;
    double ans = (x*100) / (100-p);
    cout<<fixed<<setprecision(2);
    cout<<ans<<nl;
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