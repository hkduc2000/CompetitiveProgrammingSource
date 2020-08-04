#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
#define HKD
int n;
map <int, int> dp;
int min_piece = 4001;
//---------------------

//function-------------

//---------------------

void input() {
	cin >> n;
	int inp;
	for (int i = 0; i < 3; i++) {
		cin >> inp;
		dp[inp] = 1;
		if (inp < min_piece) {
			min_piece = inp;
		}
	}
}

void solve() {
	int i = min_piece + 1;
	while (i<=n) {
		int d = 0;
		for (auto it = dp.begin(); (it != dp.end())&&(it->first<=i); it++) {
			if (dp[i - it->first] > 0) {
				d = max(d, it->second + dp[i - it->first]);
			}
			else {
				dp.erase(i - it->first);
			}
		}
		if (d) {
			dp[i] = d;
		}
		i++;
	}
}

void output() {
	cout << dp[n];
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