#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define DEBUG

vector <ll> neg;
vector <ll> pos;

ll solve(vector <ll> a){
   int n = a.size();
   if (n==0) return 0;
   sort(a.begin(),a.end());
   vector <ll> sum(n);
   sum[0] = a[0];
   FOR(i,1,n-1) sum[i] = a[i] + sum[i-1];
   ll maxop = 0;
   ll op= 0;
   FOR(i,0,n-1){
      op = a[i] * (n-i);
      int j = lower_bound(a.begin(),a.begin()+i, double(a[i])/2) - a.begin();
      ll total;
      if (j==0){
         total = 2*sum[i-1];
      } else {
         total = 2*(sum[i-1] - sum[j-1]);
      }
      op += (total - (i-j)*a[i]);
      maxop = max(maxop,op);
   }
   return maxop;
}

int main() {
   ios_base::sync_with_stdio(false) and std::cin.tie(NULL);
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int n;
   cin >> n;
   ll inp;
   ll sumall = 0;
   FOR(i,0,n-1){
      cin >> inp;
      sumall += inp;
      if (inp>0){
         pos.push_back(inp);
      } else{
         neg.push_back(inp);
      }
   }
   cout << solve(pos) << ' ' << solve(neg) << endl;
   cout << sumall - max(solve(neg), solve(pos));
}