#include <bits/stdc++.h>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (ll i=a; i<=b; i++)
#define FORD(i, a, b) for (ll i=a; i>=b; i--)
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

ll n;
ll cnt1 = 1;
ll cnt2 = 1;
ll sum, ans;
vector <ll> a;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif
	cin >> n;
	a.resize(n);
	FOR(i, 0, n - 1) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % 3 != 0) {
		printf("%d", 0);
		exit(0);
	}
	ll s = a[0];
	int i = 1;
	while ((s != sum / 3) && (i<n-1)) {
		s += a[i];
		i++;
	}
	if (i == n-1) {
		printf("%d", 0);
		exit(0);
	}

	s = a[n-1];
	int j = n-2;
	while ((s != sum / 3) && (j>0)) {
		s += a[j];
		j--;
	}
	if (j == 0) {
		printf("%d", 0);
		exit(0);
	}
	
	int limit = j - i + 1;
	vector <int> suml(limit + 1);
	vector <int> sumr;
	FOR(it, i, j) {
		suml[it - i] = a[it];
	}
	sumr = suml;
	FOR(it, 1, suml.size() - 1) {
		suml[it] += suml[it - 1];
	}
	FORD(it, limit - 2, 0) {
		sumr[it] += sumr[it + 1];
	}
	vector <ll> dp(limit + 1); 
	dp[limit] = 1;
	FORD(it, limit - 1, 0) {
		dp[it] += dp[it + 1] + (sumr[it]==0);
	}
	ans += dp[1];
	FOR(it, 0, limit-2) {
		if (suml[it] == 0) {
			ans += dp[it + 2];
		}
	}

	printf("%lld", ans);

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}