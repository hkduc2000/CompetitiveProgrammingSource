#include <bits/stdc++.h>
using namespace std;

#define DEBUG
int a,b,c, n;
int arr[4001];

int main(){
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   cin >> n >> a >> b >> c;
   for (int i=1;i<n+1;i++) {
      arr[i] = -1;
   }
   for (int i=0; i<n+1;i++){
      if (arr[i]==-1) continue;
      if (i+a<=n) arr[i + a] = max(arr[i+a], arr[i] + 1);
      if (i+b<=n) arr[i + b] = max(arr[i+b], arr[i] + 1);
      if (i+c<=n) arr[i + c] = max(arr[i+c], arr[i] + 1);
   }
   cout << arr[n];
}
