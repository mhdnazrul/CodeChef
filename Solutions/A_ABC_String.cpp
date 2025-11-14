// problem link:https://codeforces.com/contest/1494/problem/A
// Author ~ cf handle: nazrulislam_7
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define nl '\n'
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
template<class T> void readV(vector<T>& v) { for(auto &x : v) cin >> x; }
template<class T> void printV(const vector<T>& v) { for(auto x : v) cout << x << ' '; cout << '\n'; }
bool check(string s, map<char, char> mpp){
  int open=0;
  for(char &c:s){
      if(mpp[c]=='('){open++;}
      else{open--;}
      if(open<0){return false;}
  }
  return open==0;
}
void solve() {
  string s;  cin>>s;
  int n=s.size();
  if(s[0]==s[n-1]){
      cout<<"NO\n";
      return;
  }
  map<char, char> mp;
  mp[s[0]]='(';
  mp[s[n-1]]=')';
  char txt='a';
  if((s[0]=='A' && s[n-1]=='B') || (s[0]=='B' && s[n-1]=='A')){
      txt='C';
  }
  else if((s[0]=='C' && s[n-1]=='B') || (s[0]=='B' && s[n-1]=='C')){
      txt='A';
  }
  else{
      txt='B';
  }
  mp[txt]='(';
  if(check(s, mp)){
      cout<<"YES\n";
      return;
  }
  mp[txt]=')';
  if(check(s, mp)){
      cout<<"YES\n";
      return;
  }
  cout<<"NO\n";
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