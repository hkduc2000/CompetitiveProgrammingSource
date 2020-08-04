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
int n;
ll res[3];
vector<int> d;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif
	cin >> n;
	d.resize(n);
	for (int i = 0; i < n; i++) cin >> d[i];
	SORT(d);
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			ll a = d[i];
			ll b = d[j];
			double temp = sqrt(a * a + b * b);
			auto r2 = lower_bound(d.begin() + j + 1, d.end(), a + b);
			if (temp == ll(temp))
			{
				auto r1 = lower_bound(d.begin() + j + 1, r2, temp);
				auto l2 = upper_bound(d.begin() + j + 1, r2, temp);
				res[0] += distance(d.begin() + j + 1, r1);
				res[1] += distance(r1, l2);
				res[2] += distance(l2, r2);
			}
			else {
				auto l2 = upper_bound(d.begin() + j + 1, r2, temp);
				res[2] += distance(l2, r2);
				res[0] += distance(d.begin() + j + 1, l2);
			}
		}
	cout << res[0] << ' ' << res[1] << ' ' << res[2];

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}