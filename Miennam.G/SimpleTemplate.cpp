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
#define DEBUG

ll n, S;
map <ll, vector<int>> a;
vector <ll> f,sq;
set <int> ans;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif
	ans.insert(n);
	cin >> n >> S;
	ll inp;
	FOR(i, 0, n - 1) {
		cin >> inp;
		a[inp].push_back(i + 1);
	}
	FOREACH(it, a) {
		if (it.second.size() >= 2) {
			f.push_back(it.first);
		}
		if (it.second.size() >= 4) {
			sq.push_back(it.first);
		}
	}
	f.push_back(LLONG_MAX);
	ll maxS = 0;
	auto bg = lower_bound(ALL(f), sqrt(S));
	for (int i=0;f[i]*f[i] <= S && i<f.size()-1;i++){
		auto y = upper_bound(bg, f.end(),S / f[i]) - 1;
		if (f[i] == *y) {
			if (y == f.begin()) {
				cout << -1; break;
			}
			else {
				y--;
			}
		}
		if (maxS < *y * f[i]) {
			maxS = *y * f[i];
			ans.clear();
			ans.insert(a[f[i]][0]);
			ans.insert(a[f[i]][1]);
			ans.insert(a[*y][0]);
			ans.insert(a[*y][1]);
		} else if (maxS == *y *f[i]) {
			if (min(a[f[i]][0],a[*y][0]) < *ans.begin()) {
				ans.clear();
				ans.insert(a[f[i]][0]);
				ans.insert(a[f[i]][1]);
				ans.insert(a[*y][0]);
				ans.insert(a[*y][1]);
			}
		}
	}

	FOR(i, 0, int(sq.size()-1)) {
		if (sq[i] * sq[i] > maxS) {
			if (sq[i] * sq[i] <= S) {

			}
		}
		else if (sq[i] * sq[i] == maxS) {
			if (a[sq[i]][0] < *ans.begin()) {
				ans.clear();
				ans.insert(a[sq[i]][0]);
				ans.insert(a[sq[i]][1]);
				ans.insert(a[sq[i]][2]);
				ans.insert(a[sq[i]][3]);
			}
		}
	}
	
	if (ans.size() == 0) {
		cout << -1;
		exit(0);
	}
	FOREACH(it, ans) {
		cout << it << ' ';
	}
	
#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}