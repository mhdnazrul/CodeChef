// problem link:https://codeforces.com/problemset/problem/339/A
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
    string s;  cin >> s;
    vector<int> digit;
    string op = "";
    int len_op = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (isdigit(s[i]))digit.push_back(s[i] - '0');
        if (s[i] == '+'){
            op += '+';
            len_op++;
        }
    }

    sort(all(digit));
    for (int j = 0; j < digit.size(); ++j)
    {
        cout << digit[j];
        if (j < len_op)cout << op[j];
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test_cases = 1;
    //cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}