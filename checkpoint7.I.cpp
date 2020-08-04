#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector <pair<string,string>> p;
vector <string> ans;

//#define DEBUG

bool operator < (string a, string b){
   if (a.length() < b.length()) return true;
   if (a.length() > b.length()) return false;
   for (int i=0;i<a.length();i++){
      if (a[i]<b[i]) return true;
      if (a[i]>b[i]) return false;
   }
   return false;
}

bool operator <= (string a,string b){
   if (a.length() < b.length()) return true;
   if (a.length() > b.length()) return false;
   for (int i = 0; i < a.length(); i++) {
      if (a[i] < b[i]) return true;
      if (a[i] > b[i]) return false;
   }
   return true;
}


string subtract(string a, string b){
   string ans = a;
   int i = a.length() -1, j = b.length() -1;
   int rmb = 0;
   while (j>=0){
      int na = a[i] - '0' + rmb, nb = b[j]- '0';
      rmb = 0;
      if (na>=nb){
         ans[i] = (na-nb) + '0';
      } else {
         ans[i] = (na+10-nb) + '0';
         rmb = -1;
      }
      i--; j--;
   }
   ans[i] = a[i] + rmb;
   while (ans[0]=='0'){
      ans.erase(0,1);
   }
   return ans;
}

int n;
string s;
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifdef DEBUG
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   cin >> n >> s;
   p.resize(n);
   for (int i=0;i<n;i++){
      cin >> p[i].second >> p[i].first;
   }
   sort(p.begin(), p.end(),
      [](pair<string, string> & a, pair<string, string> &b) -> bool
      {
         return a.first <= b.first;
      });
   for (int i=n-1;i>=0;i--){
      if ( p[i].first <= s && subtract(s,p[i].first) < p[i].first){
         ans.push_back(p[i].second);
         s = subtract(s,p[i].first);
      }
   }

   if (s==""){
      cout << ans.size() << endl;
      for (int i=0;i<ans.size();i++){
         cout << ans[i] << endl;
      }
   } else {
      cout << 0;
   }
}