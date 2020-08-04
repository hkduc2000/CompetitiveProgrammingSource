#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//#define DEBUG

int ans,n;
map <int, bool> bug;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   cin >> n;
   int inp;
   for (int i=0;i<n;i++){
      cin >> inp;
      bug[inp] = true;
   }
   int s = 0;
   int b = 0;
   for (int i=1;i<=365;i++){
      s += b;
      if (bug[i] == true){
         b++;
      }
      if (s+b>=20){
         s = 0;
         b = 0;
         ans++;
      }
   }
   if (b>0) ans++;
   cout << ans;
}