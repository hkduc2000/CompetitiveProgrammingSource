#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define debug(printOut) cout << printOut << endl;

ll const all1 = 1677721523 ;
int const N = 100000;
int tree[2*N], a[N];
int n;

void build(int l, int r, int p){
   if (l==r) {
      tree[p] = a[r];
   } else {
      int mid = (l + r)/2;
      build(l, mid, p*2);
      build(mid+1,r, p*2+1);
      tree[p] = tree[p*2] + tree[p*2+1];
   }
}

void updateTreeNode(int p, int value){
   //update the number at the position p in the array 
   tree[n+p-1] = value;
   int ups = (n+p-1)/2;
   while (ups > 0){
      tree[ups] =  tree[ups*2+1] + tree[ups*2];
      ups /= 2;
   }    
}

int query(int lq, int rq7
, int l, int r, int p){
   if (r < lq || l > rq)
   {
      return 0;
   }
   if ((lq<=l && r<=rq)||(r==l)){
      cout << l << ' ' << r << " pos:" << p << endl;
      return tree[p];
   }
   int m = (r+l)/2;
   return query(lq,rq,l,m,p*2) + query(lq,rq,m+1,r,p*2+1);
}

int main(){
   cin >> n;
   FOR(i,1,n) cin >> a[i];
   build(1,n,1);
   FOR(i,1,2*n-1){
      debug(tree[i]);
   }
   int l, r;
   cin >>  l >> r;
   cout << query(l,r,1,n,1);
} 