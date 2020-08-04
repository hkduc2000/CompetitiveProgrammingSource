#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define fi first
#define se second

int k, n, ans, odd, even;
vector <pair<int,int>> gaps;

int a[100];

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   cin >> n;
   if (n==1){
      cout << 0;
      return 0;
   }
   FOR(i, 0, n - 1) {
      int inp;
      cin >> inp;
      if (inp == 0) {
         a[i] = 0;
      } else if (inp % 2) {
         odd += 1;
         a[i] = 1;
      } else {
         even += 1;
         a[i] = 2;
      }
   }
   FOR(i, 0, n - 2) {
      if (a[i] + a[i + 1] == 3) {
         ans++;
      }
   }
   int i = 0;
   while (i < n && a[i] != 0) {
      i++;
   }
   int cur = 0;
   int rem = 0;
   int cnt = 0;
   for (i; i < n; i++) {
      if (a[i] == 0) {
         if (i>0) if (a[i - 1] != 0) rem = a[i - 1];
         cnt++;
      } else if (a[i - 1] == 0) {
         if (a[i] == rem || rem == 0) {
            gaps.push_back(make_pair(cnt,a[i]));
         } else {
            cnt = 0;
            ans++;
         }
      }
   }
   if (cnt != 0) gaps.push_back(make_pair(cnt, rem));
   ans += int(gaps.size());
   sort(gaps.begin(), gaps.end());
   FOR(i, 0, int(gaps.size()) - 1) {
      if (gaps[i].se == 1){
         if (odd>=gaps[i].fi){
            odd -= gaps[i].fi;
            ans--;
         }
      }
      if (gaps[i].se == 2) {
         if (even >= gaps[i].fi){
            even -= gaps[i].fi;
            ans--;
         }
      }
   }
   cout << ans;
}