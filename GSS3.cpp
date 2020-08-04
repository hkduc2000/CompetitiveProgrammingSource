#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define DEBUG

struct inf {
   int sub, pre, suf, total;
};

int n, q, x, y,m;
const int MAXN = 50000;
const int minvalue = -50000;
int a[MAXN], b[MAXN+1];
inf tree[4 * MAXN+1];

inf handle(inf c1, inf c2) {
   inf res;
   res.total = c1.total + c2.total;
   res.pre = max(max(c1.pre, c1.total + c2.pre), c1.total + c2.total);
   res.suf = max(max(c2.suf, c2.total + c1.suf), c2.total + c1.total);
   res.sub = max(max(c1.suf + c2.pre, c1.sub), c2.sub);
   return res;
}

void build(int l, int r, int p) {
   if (l == r) {
      tree[p].total = a[l];
      tree[p].suf = a[l];
      tree[p].pre = a[l];
      tree[p].sub = a[l];
      b[l] = p;
   } else {
      int m = (l + r) / 2;
      build(l, m, p * 2);
      build(m + 1, r, p * 2 + 1);
      tree[p] = handle(tree[p * 2], tree[p * 2 + 1]);
   }
}

inf query(int l, int r, int lq, int rq,int p){
   if (lq > r || rq < l){
      return (inf){
          minvalue,
          minvalue,
          minvalue,
          minvalue
      };
   } else if (lq<=l && r<=rq){
      return tree[p];
   } else {
      int m = (l+r)/2;
      return handle(query(l,m,lq,rq,p*2),query(m+1,r,lq,rq,p*2+1));
   }
}

void update(int p){
   tree[p] = handle(tree[p * 2], tree[p * 2 + 1]);
   if (p>1){
      update(p/2);
   }
}

int main() {
   ios_base::sync_with_stdio(false) and std::cin.tie(NULL);
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   cin >> n;
   FOR(i, 1, n) cin >> a[i];
   build(1,n,1);
   cin >> m;
   int inp;
   FOR(i,0,m-1){
      cin >> inp >> x >> y;
      if (inp){
         cout << query(1,n,x,y,1).sub << endl;
      } else {
         int p = b[x];
         tree[p].total = y;
         tree[p].suf = y;
         tree[p].pre = y;
         tree[p].sub = y;
         if(p>1) update(p/2);
      }
   }
}
