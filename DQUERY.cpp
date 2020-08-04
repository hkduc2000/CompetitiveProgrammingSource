#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define DEBUG

struct tripair {
   int l, r, stt, ans;
};
int const MAXN = 30000;
int n, blsize, q, curR, curL, res;
int a[MAXN];
vector<tripair> b;
// map<int, int> cnt;
int cnt[1000001];

void add(int x) {
   cnt[x]++;
   if (cnt[x] == 1) {
      res++;
   }
}

void remove(int x) {
   cnt[x]--;
   if (cnt[x]==0){
      res--;
   }
}

int main() {
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   scanf("%d", &n);
   FOR(i, 0, n - 1) {
      scanf("%d", &a[i]);
   }
   scanf("%d", &q);
   b.resize(q);
   FOR(i, 0, q - 1) {
      scanf("%d %d", &b[i].l,&b[i].r);
      b[i].l--;
      b[i].r--;
      b[i].stt = i;
   }
   blsize = ceil(sqrt(n));
   sort(b.begin(), b.end(),
        [](const tripair &a, const tripair &b) -> bool {
           return a.l < b.l;
        });
   int i;
   for (i = blsize - 1; i < b.size() - 1; i += blsize) {
      sort(b.begin() + i - blsize + 1, b.begin() + i,
           [](const tripair &a, const tripair &b) -> bool {
              return a.r < b.r;
           });
   }
   i -= blsize;
   sort(b.begin() + i, b.end(),
        [](const tripair &a, const tripair &b) -> bool {
           return a.r < b.r;
        });

   cnt[a[0]]++;
   res = 1;
   FOR(i, 0, q - 1) {
      while (curL < b[i].l) {
         remove(a[curL]);
         curL++;
      }
      while (curL > b[i].l) {
         curL--;
         add(a[curL]);
      }
      while (curR > b[i].r) {
         remove(a[curR]);
         curR--;
      }
      while (curR < b[i].r) {
         curR++;
         add(a[curR]);
      }
      b[i].ans = res;
   }
   sort(b.begin(), b.end(),
        [](const tripair &a, const tripair &b) -> bool {
           return a.stt < b.stt;
        });
   FOR(i,0,q-1){
      printf("%d\n", b[i].ans);
   }
}
