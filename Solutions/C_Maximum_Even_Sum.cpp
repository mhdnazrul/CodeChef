// problem link:https://codeforces.com/contest/2137/problem/C
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
  ll a,b;   cin>>a>>b;
  
	if ((a % 2 == 0) && (b & 1)) {cout << "-1\n"; return;}
	if (b & 1) {a *= b; b = 1;}
	else {a *= (b / 2); b = 2;}
	if ((a + b) & 1) cout << "-1\n";
	else cout << a + b << "\n";
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
