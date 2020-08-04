#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
#define HKD
int n, m;
string str1, str2;
int dp[6][10];
//---------------------

//function-------------

//---------------------

void input() {
	cin >> n >> str1 >> m >> str2;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
}

void output() {
	cout << dp[n][m];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef HKD
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
	{
		input();
		solve();
		output();
	}
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif // DEBUG

	{
		input();
		solve();
		output();

	}
	return 0;
}