// problem link:https://codeforces.com/problemset/problem/2065/A
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
    int st = 0, ed = 0;
    for (int i = 0; i < str.size() - 1; ++i)
    {
        if (str[i] == 'u' && str[i + 1] == 's')
        {
            st = i;
            ed = i + 1;
        }
        else continue;
    }
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (st == i && ed == i + 1) cout << "i";
        else cout << str[i];
    }
    cout << nl;
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