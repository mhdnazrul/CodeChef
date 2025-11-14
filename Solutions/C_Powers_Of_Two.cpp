// problem link:https://codeforces.com/problemset/problem/1095/C
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
    ll n,k;     cin>>n>>k;
    priority_queue<int> pq;
    for(int i=0;i<=30; i++){
        if(n & (1<<i))pq.push(1<<i);
    }
    if(pq.size() > k){cout<<"NO\n";return;}

    while(pq.size() < k){
        ll top = pq.top();
        pq.pop();
        if(top==1)break;
        pq.push(top/2);
        pq.push(top/2);
    }
    if(pq.size()!=k){cout<<"NO\n";return;}
    cout<<"YES\n";
    while(!pq.empty()){
        cout<<pq.top()<<' ';
        pq.pop();
    }
    cout<<nl;
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