#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
int t,a,b,c;

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--){
        int res1=-1, res2=-1;
        cin >> a >> b >> c;
        double vl = (double)c / b;
        if (vl <= a){
            res2 = b;
        }
        if (a<=c){
            res1 = 1;
        }
        cout << res1 << " " << res2 << endl; 
    }
}
