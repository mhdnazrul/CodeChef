// problem link:https://codeforces.com/contest/2168/problem/A1
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
    string str;    cin >> str;
    if(str == "first"){
        int n; cin >> n;
        vector<int>a(n);
        readV(a);

        string s;
        s.reserve(n*2);

        for(int x:a){
            s.push_back('a' + x -1); 
        }
        cout<<s;
    }
    else{ 
        string s; cin >> s;
        int n = s.size();
        cout<<n<<"\n";
        for(char c : s){
            cout << (c-'a'+1) << " ";
        }
        cout<<"\n";
    }
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