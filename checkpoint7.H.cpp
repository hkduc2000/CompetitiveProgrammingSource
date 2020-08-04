#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define DEBUG

int n, m;
vector <string> ans;
double const base = 10080;
int best_p = INT_MAX;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   string a;
   getline(cin,a);
   stringstream f(a);
   f >> n >> m;
   for (int i = 0; i < m; i++) {
      getline(cin, a);
      cout << a << endl;
      string ss, mower;
      bool done = false;
      for (int i=0;i<a.length();i++){
         if (done==false){
            if (a[i] != ',') mower = mower + a[i];
            else done = true;
         } else {
            if (a[i] == ',') {
               ss = ss + ' ';
            } else {
               ss = ss + a[i];
            }
         }
      }
      stringstream s(ss);
      int p,c,t,r;
      s >> p >> c >> t >> r;
      cout << mower <<  ' ' << p << ' ' << c << ' ' <<
          t << ' ' << r << endl;
      if (base/(t * c / r) > n){
         if (p < best_p){
            ans.clear();
            best_p = p;
            ans.push_back(mower);
         } else if (p == best_p) {
            ans.push_back(mower);
         }
      }
   }
   for (int i=0; i<ans.size();i++){
      cout << ans[i] << endl;
   }
}
