// problem link:https://codeforces.com/problemset/problem/2130/A
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
    int n; cin >> n;
    vector<int>a(n), cnt(101, 0);

    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ans += a[i];
    }

    for (int i = 0; i < n; i++){
        cnt[a[i]]++;
    }

    cout << ans + min(cnt[0], cnt[1]) + max(0, cnt[0] - cnt[1]) << '\n';
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