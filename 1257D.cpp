#include<bits/stdc++.h>
using namespace std;

#define DEBUG
#define dur first
#define pow second
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
int t,n,m;

int search(vector<int> a, int l, int r, int key){
   if (r == l) {
      if (a[r] <= key) return r;
      else
   }
   int mid = (l+r)/2;
   if (a[mid] = key) return mid;
   if (a[mid] < key){
      r = mid;
   } else {
      l = mid + 1;
   }
   return search(a,l,r,key);
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
      cin >> n;
      vector <int> mons(n);
      FOR(i,0,n-1) cin >> mons[i];
      cin >> m;
      vector <pair<int,int>> inp(m);
      FOR(i,0,m-1){
         cin >> inp[i].pow >> inp[i].dur;
      }
      sort(inp.begin(),inp.end());

      vector<pair<int, int>> hero;
      hero.pb(inp[m-1]);
      pair<int,int> prev = inp[m-1];
      FOR(i,m-2,0){
         if (inp[i].pow > prev.pow){
            hero.push_back(inp);
            prev = inp[i];
         }
      }

      sort(mons.begin(), mons.end(), [](int a, int b) { return a > b; });
      int ind = n-1;
      FOR(i,0,hero.size()-1){
         int loc = search(mons,0,ind,hero[i].power);
      }
   }
}
