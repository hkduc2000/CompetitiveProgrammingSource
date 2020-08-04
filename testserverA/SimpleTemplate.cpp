#include <bits/stdc++.h>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORD(i, a, b) for (int i=a; i>=b; i--)
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

int n,k;
vector <int> a;
vector <int> b;
int ans= INT_MAX;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif
	a.push_back(0);
	b.push_back(0);
	scanf("%d", &n); scanf("%d", &k);
	int inp;
	FOR(i, 0, n - 1) {
		scanf("%d", &inp);
		if (inp >= 0) {
			a.push_back(inp);
		}
		else {
			b.push_back(abs(inp));
		}
	}
	SORT(a);
	SORT(b);

	int t = min((int)a.size()-1, k);
	int dis;
	int j;
	FORD(i, t , 0) {
		j = k - i;
		if (j > b.size() - 1) break;
		dis = 2 * min(a[i], b[j]) + max(a[i], b[j]);
		ans = min(ans, dis);
	}
	printf("%d", ans);
#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}