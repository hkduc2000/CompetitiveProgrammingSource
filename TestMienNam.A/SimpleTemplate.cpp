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
#define x first 
#define y second 
#define pb push_back 
#define ALL(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz)) 
#define DEBUG

int n, m;
char board[51][51];
int dp[51][51];
pair<int,int> last[51][51];

int calc(char a, char sign, int b) {
	if (sign == '+') {
		return (a - '0') + b;
	}
	else {
		return (a - '0') * b;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	cin >> n >> m;
	FOR(i, 1, n) FOR(j, 1, m) cin >> board[i][j];
	dp[n][m] = board[m][n] - '0';
	for (int sum = m + n - 2; sum >= 2; sum -= 2) {
		int i = min(sum, n);
		int j = sum - i;
		while (j <= min(sum,m)) {
			if (j < m && i < n) {
				if (dp[i][j] < calc(board[i][j], board[i][j + 1], dp[i + 1][j + 1])) {

				}
				dp[i][j] = max(dp[i][j],
					calc(board[i][j], board[i+1][j], dp[i + 1][j + 1]));
			}
			if (i < n - 1) {
				dp[i][j] = max(dp[i][j],
					calc(board[i][j], board[i + 1][j], dp[i + 2][j]));
			}
			if (j < m - 1) {
				dp[i][j] = max(dp[i][j],
					calc(board[i][j], board[i][j+1], dp[i][j + 2]));
			}
			j++; i--;
		}
	}

	cout << dp[1][1];

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}