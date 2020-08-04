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
map <int, int> counter;
vector <int> a;
int ans;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	scanf("%d", &n);
	a.resize(n);
	FOR(i, 0, n - 1) {
		scanf("%d", &a[i]);
	}

	counter[4] = 0;	counter[8] = 0;
	counter[15] = 0; counter[16] = 0;
	counter[23] = 0; counter[42] = 0;

	FOR(i, 0, n - 1) {
		if (a[i] == 4) {
			counter[a[i]]++;
			continue;
		}
		auto itlow = counter.lower_bound(a[i]); itlow--;
		if (counter[a[i]] < (itlow->second)) {
			counter[a[i]]++;
		}
	}

	int numofsubse = INT_MAX;
	FOREACH(it, counter) {
		numofsubse = min(numofsubse, it.second);
	}
	ans = n - numofsubse * 6;
	printf("%d", ans);

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}