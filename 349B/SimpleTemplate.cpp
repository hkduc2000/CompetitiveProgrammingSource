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

int v,r,k;
int a[9],b[9];
vector <int> ans;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	scanf("%d", &v);
	int min_paint = INT_MAX;
	int min_num;
	FOR(i, 0, 8) {
		scanf("%d", &a[i]);
		if (min_paint > a[i]) {
			min_paint = a[i];
			min_num = i + 1;
		}
	}

	if (v < min_paint) {
		printf("%d", -1);
	}
	
	FOR(i, 0, 8) {
		b[i] = a[i] - min_paint;
	}

	// k is number of character in ans, r is liter of paints remain
	k = v / min_paint;
	r = v % min_paint;
	// Now we're supposing that ans is full of min number
	ans.resize(k);
	FOR(i, 0, k - 1) ans[i] = min_num;
	
	FOR(i, 0, k - 1) {
		FORD(j, 8, 1) {
			if (b[j] <= r) {
				ans[i] = j + 1;
				r -= b[j];
				break;
			}
		}
	}

	FOR(i, 0, k-1) printf("%d", ans[i]);


#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}