// problem link:https://codeforces.com/problemset/problem/2106/D
// Author: nazrulislam_7

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }

bool can_collect_dp(int m, int nn, const vector<int> &a, const vector<int> &b) {
    vector<vector<bool>> dp(nn + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= nn; ++i) {
        dp[i][0] = true;
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (a[i - 1] >= b[j - 1] && dp[i - 1][j - 1]) {
                dp[i][j] = true;
            }
        }
    }
    return dp[nn][m];
}

bool can_collect_with_k_dp(int k, int m, int n, const vector<int> &a, const vector<int> &b) {
    for (int p = 0; p <= n; ++p) {
        vector<int> temp_a;
        for (int i = 0; i < p; ++i) temp_a.push_back(a[i]);
        temp_a.push_back(k);
        for (int i = p; i < n; ++i) temp_a.push_back(a[i]);
        if (can_collect_dp(m, n + 1, temp_a, b)) return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    readV(a);
    vector<int> b(m);
    readV(b);

    if (can_collect_dp(m, n, a, b)) {
        cout << 0 << nl;
        return;
    }

    int low = 1, high = 1000000000, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_collect_with_k_dp(mid, m, n, a, b)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << nl;
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