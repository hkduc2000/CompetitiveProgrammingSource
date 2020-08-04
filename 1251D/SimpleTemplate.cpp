#include <bits/stdc++.h>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (ll i=a; i<=b; i++)
#define FORD(i, a, b) for (ll i=a; i<=b; i--)
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define MAX(a, b) a = max(a, b) 
#define MIN(a, b) a = min(a, b) 
#define fi first 
#define se second 
#define pb push_back 
#define ALL(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz)) 
//#define DEBUG

ll t, n, s;

ll f(ll s1, ll x) {
	return s1 + x + x * (n / 2);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::lock::now();
#endif
	cin >> t;
	while (t--) {
		cin >> n >> s;
		vector <pair<ll, ll>> a(n);
		FOR(i, 0, n - 1) {
			cin >> a[i].first >> a[i].second;
		}
		sort(ALL(a), [](pair<ll, ll> c, pair<ll, ll>d) {
			return c.second < d.second;
			});
		ll s1 = 0;
		for (ll i = 0; i < n / 2; i++) {
			s1 += a[i].first;

			}
		ll l = a[n / 2].first;
		ll r = a[n / 2].second;
		while (l < r) {
			ll mid = (l + r) / 2;
			if (f(s1, mid) > s) {
				r = mid-1;
			}
			else l = mid+1;
		}
		cout << l << endl;
	}


#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}