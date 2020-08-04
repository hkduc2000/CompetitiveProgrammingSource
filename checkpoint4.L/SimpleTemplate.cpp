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
#define pb push_back 
#define ALL(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz)) 
#define DEBUG

int n;
vector<pair<int, int>> a;
vector<pair<int, int>> b;
ll ans, space;
bool sortSecond(pair<int, int> x, pair<int, int> y) {
	return x.second > y.second;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif
	int string;
	scanf("%d", &n);
	int inp1, inp2;
	FOR(i, 0, n - 1) {
		scanf("%d %d", &inp1, &inp2);
		if (inp1 > inp2) {
			b.push_back(make_pair(inp1, inp2));
		}
		else {
			a.push_back(make_pair(inp1, inp2));
		}
	}
	SORT(a); 
	sort(b.begin(),b.end(),sortSecond);
	//REVERSE(b);
	a.insert(a.end(), ALL(b));
	FOR(i, 0, a.size() - 1) {
		ll buy = 0;
		if (a[i].first > space) {
			buy += a[i].first - space;
			ans += buy;
		}
		space += (a[i].second - a[i].first + buy);
	}
	
	cout << ans;

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}