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

int n,m,l,r,x,y;
vector <int> a;
vector <map<int,int>> dp;
map <int, int> cnt;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	scanf("%d", &n);
	a.resize(n+1);
	dp.resize(n+1);
	
	FOR(i, 1, n) {
		scanf("%d", &a[i]);
	}

	FOR(i, 1, n) {
		cnt[a[i]]++;
		dp[i] = dp[i - 1];
		if (cnt[a[i]] > 1) {
			dp[i][cnt[a[i]]-1]--;
		}
		dp[i][cnt[a[i]]]++;
	}

	int ans;
	scanf("%d", &m);
	FOR(i, 0, m - 1) {
		ans = 0;
		scanf("%d %d %d %d", &l, &r, &x, &y);
		FOR(j, x, y) {
			ans += dp[r][j] - dp[l][j];
		}
		printf("%d\n", ans);
	}
	

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}