#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#define FOR(i, a, b) for (int i = a; i <= b; i++)

int t,n;
string s;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   cin >> t;
   while (t--){
      cin >> n;
      cin >> s;
      int ans = 0;
      int cnt = 0;
      int i = 0;
      while (s[i]!='A' && i<n) i++;
      for (i;i<n;i++){
         if (s[i]=='A'){
            ans = max(ans, cnt);
            cnt = 0;
         } else {
            cnt++;
         }
         ans = max(ans, cnt);
      }
      cout << ans << endl;
   }
}