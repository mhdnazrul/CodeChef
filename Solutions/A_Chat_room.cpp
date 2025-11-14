// problem link:https://codeforces.com/problemset/problem/58/A
// Author: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
void solve() {
    string s;
    cin >> s;
    string txt = "hello";
    int j = 0;
    for(int i = 0; i < s.size() && j < txt.size(); i++) {
        if(s[i] == txt[j]) {
            j++;
        }
    }   
    if(j == txt.size()) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    //cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}