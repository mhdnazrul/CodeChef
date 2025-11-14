// problem link:https://codeforces.com/problemset/problem/208/A
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
    string store;
    for (int i = 0; i < (int)s.size(); ) {
        if (i + 2 < s.size() && s.substr(i, 3) == "WUB") {
            store += ' ';
            i += 3;
        } else {
            store += s[i];
            i++;
        }
    }

    stringstream ss(store);
    string word, ans;
    while (ss >> word) {
        if (!ans.empty()) ans += ' ';
        ans += word;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    //if(!(cin>>test_cases)) return 0;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}