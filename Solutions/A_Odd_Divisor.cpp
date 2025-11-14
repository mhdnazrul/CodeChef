// problem link:https://codeforces.com/problemset/problem/1475/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }
bool isODD(ll n)
{
    if (n <= 2)return false;
    if (n % 2 != 0)return true;
    else {
        while (n % 2 == 0)n /= 2;
        return n > 1;
    }
}
void solve() {
    ll n;   cin>>n;
    cout<<(isODD(n)?"YES\n":"NO\n");
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