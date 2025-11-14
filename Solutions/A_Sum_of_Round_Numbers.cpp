// problem link:https://codeforces.com/problemset/problem/1352/A
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
    int arr[6], total = 0, m = 1;
    for(int i=0; i<6; i++)
    {
        arr[i] = n%10;
        n /= 10;
        if(arr[i]!=0)
            total++;
    }
    cout << total << endl;
    for(int i=0; i<6; i++)
    {
        if(arr[i]!=0)
            cout << arr[i]*m << " ";
        m *= 10;
    }
    cout << nl;                                                                           
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    cin >> test_cases;
    for(int tc = 1; tc <= test_cases; tc++){
    //  cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}