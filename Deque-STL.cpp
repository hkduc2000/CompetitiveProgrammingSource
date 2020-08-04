#include <bits/stdc++.h>
using namespace std;

#define DEBUG
int t,n,k;

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> t;
    while (t--){
        cin >> n >> k; 
        deque <int> a(n);
        int inp;
        int maxx = INT_MIN;
        int i;
        for (i=0;i<k;i++){
            cin >> inp;
            maxx = max(maxx,inp);
            a.push_back(k);
        }
        cout << maxx << " ";
        while (i<n){
            int pop = a.front();
            a.pop_front();
            cin >> inp;
            a.push_back(inp);
            if (pop==maxx) {
                maxx = INT_MIN;
                for (int j=0;j<k;j++){
                    maxx = max(maxx, a[j]);
                }
            } else {
                maxx = max(maxx, inp);
            }
            cout << maxx << " ";
            i++;
        }
        cout << endl;
    }
    return 0;
}
