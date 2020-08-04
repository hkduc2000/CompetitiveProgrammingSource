#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
//#define DEBUG

const int minvalue = -15008;
struct inf {
   int sub,pre,suf,total;
   // int sub = minvalue;
   // int pre = minvalue;
   // int suf = minvalue;
   // int total = minvalue;
};

// const inf base;

const int MAXN = 50001;
int a[MAXN];
inf tree[4 * MAXN];
int n;

bool isEqual(inf c1, inf c2){
   return (c1.sub==c2.sub)*(c1.suf==c2.suf)*(c1.pre==c2.pre)*(c1.total==c2.total);
}

inf handle(inf c1, inf c2){
   // if (isEqual(c1, base)) return c2;
   // if (isEqual(c2, base)) return c1;
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
   } else {
      int m = (l + r) / 2;
      build(l, m, p * 2);
      build(m + 1, r, p * 2 + 1);
      tree[p] = handle(tree[p*2], tree[p*2+1]);
   }
}

inf query(int l, int r, int lq, int rq, int p) {
   if (r<lq || rq<l){
      return (inf)  //MADE CHANGES HERE
         {
              minvalue,
              minvalue,
              minvalue,
              0
         };

   }
   if (lq <= l && r <= rq) {
      return tree[p];
   } else {
      int m = (l + r) / 2;
      return handle(query(l,m,lq,rq,p*2),query(m+1,r,lq,rq,p*2+1));
   }
}

int main() {
   ios_base::sync_with_stdio(false) and std::cin.tie(NULL);
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   cin >> n;
   FOR(i, 1, n) {
      cin >> a[i];
   }
   build(1,n,1);
   int t;
   cin >> t;
   int l,r;
   while (t--){
      cin >> l >> r;
      inf ans = query(1, n, l, r, 1);
      cout << ans.sub << endl;
   }
}