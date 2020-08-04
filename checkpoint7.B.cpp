#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
//#define DEBUG

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int n;
   cin >> n;
   int prev = 0;
   string inp;
   FOR(i,0,n-1){
      cin >> inp;
      int cur;
      if (inp == "mumble"){
         cur = prev +1;
      } else {
         cur = stoi(inp);
         if (cur != prev + 1) {
            cout << "something is fishy";
            exit(0);
         }
      }
      prev = cur;
   }
   cout << "makes sense";
}