// problem link: https://codeforces.com/contest/2094/problem/B
// Author: nazrulislam_7 
#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    
    if (n == m) {
        cout << l << " " << r << nl;
        return;
    }
    int dif2 = m / 2;               
    int dif1 = m - dif2;   
    
    if (dif2 > r) {
        dif1 += (dif2 - r);
        cout << -dif1 << " " << r << nl;
    } else if (-l < dif1) {
        dif2 += (dif1 - (-l));
        cout << l << " " << dif2 << nl;
    } else {
        cout << -dif1 << " " << -dif1 + m << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}