// problem link:https://codeforces.com/contest/2169/problem/B
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
    string s;    cin >> s;
    int ln = s.length();
    int greater = ln,less = -1;

    for(int i=0; i<ln; ++i) {
        if (s[i] == '>' || s[i] == '*') greater = min(greater, i);
        if (s[i] == '<' || s[i] == '*') less = max(less, i);
    }

    if (greater < less)  cout << -1 << nl;
    else {
        int cnt = 0;
        for(int i=0; i<ln; ++i) {
            int ls = 0;
            if (s[i] == '<') ls = i + 1;
            else if (s[i] == '>') ls = ln - i;
            else {ls = max(i + 1, ln - i);}
            cnt = max(cnt, ls);
        }
        cout << cnt << nl;
    }
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