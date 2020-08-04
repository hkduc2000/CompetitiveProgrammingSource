#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
int n,t;
vector <int> a;

void solve(){
    cin >> n; 
    a.resize(n);
    for (int i=0;i<n;i++) cin >> a[i];
    vector<int> inds, ua;
    for (int i=0;i<n;i++){
        if (ua.size()==0 || ua.back()!=a[i]){
            ua.push_back(a[i]);
            inds.push_back(i+1);
        } 
    }
    for (int i=1;i<ua.size()-1;i++){
        if (ua[i-1]<ua[i] && ua[i] > ua[i+1]){
            cout << "YES" << endl << inds[i-1] << " "
                << inds[i] << " " << inds[i+1] << endl;
            return;
        }
    }
    cout << "NO" << endl;
        
}

int main(){
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--){
        solve();
    }
        
}
