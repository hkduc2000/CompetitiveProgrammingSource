#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DEBUG
struct node {
   int fi,fif,la,laf,mostf;
   bool allEqual;
};

int const MAXN = 100000;
node tree[MAXN*4+1];
int a[MAXN+1], n,q;

node handle(node a, node b){
   if (a.fi==-1) return b;
   if (b.fi==-1) return a;
   node res;
   res.fi = a.fi;
   res.fif = a.fif;
   res.la = b.la;
   res.laf = b.laf;
   res.allEqual = false;
   res.mostf = max(a.mostf, b.mostf);
   if (a.la == b.fi) {
      if (a.allEqual && b.allEqual){
         res.fif = res.laf = a.fif + b.fif;
         res.allEqual = true;
      } else if (a.allEqual) {
         res.fif += b.fif;
      } else if (b.allEqual){
         res.laf += a.laf;
      }
      res.mostf =max(res.mostf,a.laf + b.fif);
   }
   return res;
}

void build(int l, int r, int p){
   if (l==r){
      tree[p] = (node){
         a[r], 1, a[r], 1, 1, true
      };
   } else {
      int m = (l+r)/2;
      build(l,m,p*2);
      build(m+1,r,p*2+1);
      tree[p] = handle(tree[p*2],tree[p*2+1]);
   }
}

node query(int l, int r, int lq, int rq, int p){
   if (r < lq || rq < l) {
      return (node){
         -1,0,0,0,0,0
      };
   }
   if (lq <= l && r <= rq) {
      return tree[p];
   } else {
      int m = (l + r) / 2;
      return handle(query(l, m, lq, rq, p * 2), query(m + 1, r, lq, rq, p * 2 + 1));
   }
}

int main(){
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(false) and std::cin.tie(NULL);
   cin >> n >> q;
   FOR(i,1,n) cin >> a[i];
   build(1,n,1);
   int l,r;
   while (q--){
      cin >> l >> r;
      cout << query(1,n,l,r,1).mostf << endl;
   }
}