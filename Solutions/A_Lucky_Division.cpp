// problem link:https://codeforces.com/problemset/problem/122/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
void solve() {
    int n, i, store[14] = {4,7,44,47,74,77,444,447,474,477,744,747,774,777};
    cin>>n;
    bool flag=false;
    for(i=0;i<14;i++){
        if(n%store[i]==0){
            flag=true;
            break;
        }
    }
    cout<<(flag?"YES":"NO")<<nl;
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