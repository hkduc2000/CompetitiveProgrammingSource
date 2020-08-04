#include <bits/stdc++.h>
using namespace std;

int main() {
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int n;
   cin >> n;
   int s = 0, e = n-1;
   vector<int> a(n);
   for (int i=0;i<n;i++){
      cin >> a[i];
   }

   while (e-s>=2){
      int minn = INT_MAX, lmin;
      int maxx = INT_MIN, lmax;
      for (int i=s;i<=e;i++){
         if (a[i] > maxx){
            maxx = a[i]; lmax = i;
         }
         if (a[i] < minn) {
            minn = a[i]; lmin = i;
         }
      }
      int temp = a[s];
      a[s] = a[lmin];
      a[lmin] = temp;
      temp = a[e];
      a[e] = a[lmax];
      a[lmax]= temp;
      s++;e--;
   }
   for (int i=0;i<n;i++){
      cout << a[i] << ' ';
   }
}
