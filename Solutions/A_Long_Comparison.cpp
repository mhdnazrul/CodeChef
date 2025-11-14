// problem link:https://codeforces.com/problemset/problem/1613/A
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
    int a,b,x,y;  cin>>a>>x>>b>>y;
    int ln_a = to_string(a).size();
    int ln_b = to_string(b).size();
    ll val_a = ln_a+x,   val_b = ln_b+y;
    if (val_a > val_b) cout << ">\n";
    else if (val_a < val_b) cout << "<\n";
    else {
        while (ln_a < ln_b) a *= 10, ln_a++;
        while (ln_a > ln_b) b *= 10, ln_b++;
        cout << ((a > b) ? ">\n" : ((a == b) ? "=\n" : "<\n"));
    }
    
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