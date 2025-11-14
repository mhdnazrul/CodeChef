// problem link:https://codeforces.com/contest/2168/problem/A2
// Author: nazrulislam_7 (fixed)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }

void solve() {
    string str;     cin>>str;
    if(str=="first"){
        int n; cin>>n;
        vector<ll>a(n);
        readV(a);

        string s;
        for(ll x:a){
            vector<int> d;
            while(x>0){
                d.push_back(x%26);
                x/=26;
            }
            if(d.empty()) d.push_back(0);
            reverse(d.begin(), d.end());
            int k = d.size();
            s.push_back(char('a' + (k-1)));
            for(int v:d) s.push_back(char('a'+v));
        }
        cout<<s;
    }
    else{
        string s; cin>>s;
        vector<ll> a;
        int i=0, L=s.size();
        while(i<L){
            int k = (s[i]-'a') + 1;
            i++;
            ll x=0;
            for(int t=0;t<k;t++){
                int v = s[i]-'a';
                i++;
                x = x*26 + v;
            }
            a.push_back(x);
            
        }
        cout<<a.size()<<"\n";
        printV(a);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    for(int tc = 1; tc <= test_cases; tc++){
        solve();
    }
    return 0;
}
