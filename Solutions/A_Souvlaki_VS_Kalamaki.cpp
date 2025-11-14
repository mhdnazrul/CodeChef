// problem link:https://codeforces.com/contest/2163/problem/A
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
    int n;
    cin >> n;
    vector<int> a(n);
    readV(a);
    sort(all(a));
    bool flag = true;
    for (int i = 1;i < n; i+=2){
        if (i+1 < n){
            if (a[i] != a[i+1])flag = false;
        }
    }

    cout<< (flag?"YES\n":"NO\n");
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    if(!(cin>>test_cases)) return 0;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}