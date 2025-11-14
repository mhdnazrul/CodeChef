// problem link:https://codeforces.com/group/MWSDmqGsZm/contest/326175/problem/B
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'

void solve() {
    ll a,b,k;   cin>>a>>b>>k;
    if(a%k==0 && b%k==0)cout<<"Both\n";
    else if(a%k!=0 && b%k!=0)cout<<"No One\n";
    else cout<<(a%k==0?"Memo\n":"Momo\n");
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