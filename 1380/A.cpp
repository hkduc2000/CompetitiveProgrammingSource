#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
int n,t;
int a[1000];

int main(){
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> t;
    int min1=a[0], min2=a[0];
    int ind1=0, ind2=0;
    while (t--){
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        if (checkAsc(a,n) || checkDesc(a,n)){
            cout << "NO" << endl;
            continue;
        }
        int x,y,z;
        for (int i=n-2;i>0;i--){
            if (a[i]>a[i+1]){
                y = i;
                z = i+1;
                break;
            }
        }
        cout << y << " " << z << endl;
        for (int i=y-1;i>=0;i--){
            if (a[i] < a[y])
            {
                x = i;
            }
        }
        cout << "YES" << endl;
        cout << x+1 << " " << y+1 << " " << z+1 << endl;
    }
}
