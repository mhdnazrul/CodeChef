// problem link: https://codeforces.com/problemset/problem/2146/A
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
        int n;
        cin >> n;
        vector<int> a(n),cnt(n + 1);
        readV(a);
        for (int v : a) {
            cnt[v]++;
        }
        vector<int> freq;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] > 0) {
                freq.emplace_back(cnt[i]);
            }
        }
        int ans = 0;
        for (int f = 1; f <= n; ++f) {
            int c = 0;
            for (int x : freq) {
                if (x >= f) {
                    c++;
                }
            }
            ans = max(ans, c * f);
        }
        cout << ans << '\n';

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