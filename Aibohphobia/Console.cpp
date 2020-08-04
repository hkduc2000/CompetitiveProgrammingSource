#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
#define HKD
int t,MLS;
string a,b;
static int dp[6101][6101];
//---------------------

//function-------------
int max_longest_subsequence(string str1,string str2) {
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	return dp[str1.length()][str2.length()];
}

//---------------------

void input() {
	int duc;
	cin >> duc >> a ;
	for (int i = a.size() - 1; i >= 0; i--) {
		b += a[i];
	}
}

void solve() {
	MLS = max_longest_subsequence(a, b);
}

void output() {
	cout << a.length() - MLS << endl;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef HKD
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
	cin >> t;
	while (t--)
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
	cin >> t;
	while (t--)
	{
		input();
		solve();
		output();

	}
	return 0;
}