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

int n;
vector <int> a;
vector <map<int, int>> dp;
int ans = INT_MIN;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif
	scanf("%d", &n);
	dp.resize(n);
	a.resize(n);
	FOR(i, 0, n - 1) scanf("%d", &a[i]);
	sort(ALL(a));
	//First, we need to find every number make 
	FOR(s, 1, n - 2) {
		int f = s - 1;
		int t = s + 1;
		while ((f >= 0) && (t < n)) {
			if (a[f] + a[t] == a[s] * 2) {
				int d = a[f] - a[s];
				dp[f][d] += (dp[f][d] == 0);
				dp[s][d] = dp[f][d] + 1;
				dp[t][d] = dp[s][d] + 1;
				ans = max(ans, dp[t][d]);
				t++; f--;
			}
			else if (a[f]+a[t] < a[s]*2) {
				t++;
			}
			else {
				f--;
			}
		}
	}
	ans = max(ans, 2);
	cout << ans;

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}