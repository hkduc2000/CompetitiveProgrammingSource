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

bool a[10001][10001];
int dp[10001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif
	dp[1] = 2;
	FOR(i, 2, 10000) {
		dp[i] = i - 1;
		FOR(j, 1, i-1) {
			if (a[i][j]==false) {
				for (int m = 2; m*i <= 10000; m++) {
					a[m * i][m * j] = true;
				}
			}
			else {
				dp[i]--;
			}
		}
	}

	FOR(i, 2, 10000) {
		dp[i] += dp[i - 1];
	}

	int n,stt,inp;
	cin >> n;
	while (n--) {
		cin >> stt >> inp;
		cout << stt << ' ' << dp[inp] << endl;
	}

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}