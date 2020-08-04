#include <bits/stdc++.h>
using namespace std;

#define DEBUG
int A, B, C, m;
const int nmax = 1e6 + 10;

struct dataa {
   int x, y, z;
} a[nmax];
struct res {
   int xl, xr, yl, yr, zl, zr;
} b[nmax];

bool cmpx(dataa a1, dataa a2) {
   if (a1.x < a2.x) return 1;
   return 0;
}
bool cmpy(dataa a1, dataa a2) {
   if (a1.y < a2.y) return 1;
   return 0;
}
bool cmpz(dataa a1, dataa a2) {
   if (a1.z < a2.z) return 1;
   return 0;
}

int main() {
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   while (true) {
      cin >> A;
      if (A == -1) break;
      cin >> B >> C;
      cin >> m;
      for (int i = 1; i <= m; i++) {
         cin >> a[i].x >> a[i].y >> a[i].z;
      }
      sort(a + 1, a + m + 1, cmpz);
      a[1].z = 1;
      a[m + 1].x = A + 1;
      a[m+1].y = B+1;
      a[m+1].z = C+1;


      int i = 1;
      while (i <= m) {
         int j = i;
         while (a[j].z == a[i].z) j++;
         j--;
         int l = a[i].z;
         int r = a[j + 1].z-1;
         for (int k = i; k <= j; k++) {
            b[k].zl = l;
            b[k].zr = r;
         }

         sort(a + i, a + j + 1, cmpy);

         int ii = i;
         while (ii<=j) {
            int jj = ii;
            while (a[jj].y == a[ii].y && jj<=j) jj++;
            jj--;
            if (ii==i) l = 1;
            else l = a[ii].y;
            if (jj==j) r = B;
            else r = a[jj+1].y-1;
            for (int k=ii;k<=jj;k++) {
               b[k].yl = l;
               b[k].yr = r;
            }
            sort(a+ii,a+jj+1,cmpx);

            int iii = ii;

            while (iii <= jj) {
               int jjj = iii;
               while (a[jjj].x == a[iii].x && jjj <= jj) jjj++;
               jjj--;
               if (iii == ii)
                  l = 1;
               else
                  l = a[iii].x;
               if (jjj == jj)
                  r = A ;
               else
                  r = a[jjj + 1].x - 1;
               for (int k = iii; k <= jjj; k++) {
                  b[k].xl = l;
                  b[k].xr = r;
               }
               iii = jjj+1;
            }
            b[ii].xl = 1;
            ii = jj+1;
         }
         b[i].yl = 1;
         i = j + 1;
      }
      b[1].zl = 1;

      cout << "YES" << '\n';
      for (int i = 1; i <= m; i++) {
         cout << b[i].xl << ' ' << b[i].yl << ' ' << b[i].zl << ' ' << b[i].xr << ' ' << b[i].yr << ' ' << b[i].zr << '\n';
      }
   }
   cout.tie(0);
   return 0;
}