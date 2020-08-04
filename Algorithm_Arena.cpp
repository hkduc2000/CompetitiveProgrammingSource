#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
typedef long long ll;
ll n;
ll mod = 1e9 + ll(7);

int main()
{
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    ll a = n;
    ll b = (n-1);
    ll c = (n-2);
    if (n%3==0){
        a = n/3;
    } else if (n%3==1){
        b = (n-1)/3;
    } else {
        c = (n-2)/3;
    }
    if (a%2==0){
        a = a/2;
    } else if (b%2==0) {
        b = b/2;
    }
    a = a % mod;
    b = b % mod;
    c = c % mod;
    ll kgm = ll((a * b) % mod * c)%mod;
    ll t2 = ((n%mod) * ((n - 4) % mod)) % mod;
    ll t3 = (n % mod);
    ll res = kgm - t2 - t3;
    while (res<0){
        res += mod;
    }
    cout << res;
}
