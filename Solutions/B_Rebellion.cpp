// problem link:https://codeforces.com/contest/1746/problem/B
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
    ll n;    cin>>n;
    vector<ll> vec(n+1);
    ll ones = 0;
    for(ll i=1;i<=n;i++){
        cin>>vec[i];
        if(vec[i]==1)ones++;
    }
    ll cnt = 0;
    for(ll i=n; i>0;i--){
        if(vec[i]==0 && ones>0){
            cnt++;
        }
        ones--;
    }
    cout<<cnt<<"\n";
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
 			 			 	  				 	 		