// problem link:https://codeforces.com/group/YiaGPYJsA1/contest/645209/problem/C
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
    ll n, a, b, c;    cin >> n >> a >> b >> c;
    ll sum_ABC = a + b + c;
    ll need = n / sum_ABC;
    ll fill_up = need * sum_ABC;
    ll day = need * 3;
    ll diff = n - fill_up;

    if(diff > 0) {
        if(diff <= a) day += 1;
        else if(diff <= a + b) day += 2;
        else day += 3;
    }
    cout << day << nl;
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

