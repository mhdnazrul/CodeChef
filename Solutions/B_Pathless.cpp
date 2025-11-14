// problem link: https://codeforces.com/contest/2130/problem/B
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
void solve() {
    int n, s; 
    vector<int> a(3, 0);
    int sum = 0;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        sum += t;
        a[t]++;
    } 
    if(sum == s || s > sum + 1) {cout << "-1\n"; return;}
    for(int i = 0; i < a[0]; i++) cout << "0 ";
    for(int i = 0; i < a[2]; i++) cout << "2 ";
    for(int i = 0; i < a[1]; i++) cout << "1 ";
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        solve();
    }
    return 0;
}
