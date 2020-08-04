#include <bits/stdc++.h>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORD(i, a, b) for (int i=a; i<=b; i--)
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

ll s, n, m, k;
vector <pair<ll, ll>> a, b;
int res[2];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	cin >> s >> k >> n >> m;
	a.resize(n + 1);
	b.resize(m + 1);
	a[0].first = INT64_MAX;
	b[0].first = INT64_MAX;
	FOR(i, 1, n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	FOR(i, 1, m) {
		cin >> b[i].first;
		b[i].second = i;
	}
	SORT(a); SORT(b); REVERSE(a); REVERSE(b);
	a[0].first = 0;
	b[0].first = 0;
	FOR(i, 2, n) {
		a[i].first += a[i - 1].first;
	}
	FOR(i, 2, m) {
		b[i].first += b[i - 1].first;
	}
	ll maxs = 0;
	int init = min(k, n);
	for (int i = init, j = k - init;
		i >= 0 && j <= m; i--, j++) {
		ll news = (a[i].first * b[j].first) + s * b[j].first
			+ 100 * a[i].first;
		if (news > maxs) {
			res[0] = i; res[1] = j;
			maxs = news;
		}
	}
	cout << res[0] << ' ' << res[1] << endl;
	FOR(i, 1, res[0]) {
		cout << a[i].second << ' ';
	}
	cout << endl;
	FOR(i, 1, res[1]) {
		cout << b[i].second << ' ';
	}

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}