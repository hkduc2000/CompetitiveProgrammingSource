#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DEBUG
ll const base = 1073741823 ;
int const MAXN = 60000;
int t, n, k;
ll tree[4*MAXN+1], a[MAXN+1];

void build(int l, int r, int p){
   if (l==r){
      tree[p] = a[r];
   } else {
      int mid = (l+r) / 2;
      build(l,mid, 2*p);
      build(mid+1,r, 2*p+1);
      tree[p] = tree[p*2] & tree[2*p+1];
   }
}

int query(int l, int r, int lq, int rq, int p){
   if (r < lq || l > rq)
   {
      return base;
   }
   if (lq<=l && r<=rq){
      return tree[p]; 
   } else {
      int mid = (r+l)/2;
      return (query(l,mid,lq,rq,p*2) & query(mid+1,r,lq,rq,p*2+1));
   }
}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   cin >> t;
   while (t--){
      cin >> n >> k;
      FOR(i,1,n*4+1){
         tree[i] = base;
      }
      FOR(i, 1, n) {
         cin >> a[i];
         a[i+n] = a[i];
         a[i+2*n] = a[i];
      }
      build(1,3*n,1);
      FOR(i,n+1,2*n){
         k = min(k,n/2);
         cout << query(1,3*n,i-k,i+k,1) << ' ';
      }
      cout <<endl;
   }

   
}