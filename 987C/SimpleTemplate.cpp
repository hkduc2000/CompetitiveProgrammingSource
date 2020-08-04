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
vector <int> s, c, stt;
int const maxprice = 10e8+1;
int dp[3001][4];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	scanf("%d", &n);
	s.resize(n);
	c = s;
	stt = s;
	FOR(i, 0, n - 1) scanf("%d", &s[i]);

	FOR(i, 0, n - 1) {
		scanf("%d", &dp[i][1]);
		
	}

	FOR(k, 2, 3) FOR(i, 0, n - 1) dp[i][k] = maxprice;

	FOR(i, 1, n - 1)
		FOR(j, 0, i-1) {
		if (s[i] > s[j]) {
			dp[i][2] = min(dp[i][2], dp[i][1] + dp[j][1]);
		}
	}

	FOR(i, 2, n - 1) FOR(j, 1, i-1) {
		if (s[i] > s[j]) {
			dp[i][3] = min(dp[i][3], dp[i][1] + dp[j][2]);
		}
	}
	//Lỗi cuối cùng ở k=3 số đầu tiên không khớp với implement

	int ans=INT_MAX;
	FOR(i, 2, n - 1) {
		if (ans > dp[i][3]) {
			ans = dp[i][3];
		}
	}
	if (ans == maxprice) {
		printf("%d", -1);
	}
	else {
		printf("%d", ans);
	}

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}