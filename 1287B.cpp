#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#define FOR(i, a, b) for (int i = a; i <= b; i++)

int const sum = 236;
int k, n, ans;
string a[1500];
unordered_map <string,bool> check;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   cin >> n >> k;
   FOR(i,0,n-1){
      cin >> a[i];
      check[a[i]] = true;
   }
   FOR(i,0,n-2){
      FOR(j,i+1,n-1){
         string x = a[i], y = a[j];
         string z;
         FOR(it,0,k-1){
            if (x[it] == y[it]){
               z += x[it];
            } else {
               char add = sum - x[it] - y[it];
               z += add;
            }
         }
         if (check[z]) ans++;
      }
   }
   cout << ans/3;
}