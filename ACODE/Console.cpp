#include <bits/stdc++.h>
#include <chrono>
#include <string>
using namespace std;

//define---------------
#define HKD
string inp;
vector <int> dp;
//---------------------

//function-------------

//---------------------

void input() {
	dp.clear();
	dp.resize(inp.length());
}

void solve() {
	
	if (inp.length() == 1) {
		cout << 1 << endl;
		return;
	}

	dp[0] = 1;
	int start = 2;
	if (inp[1] == '0') {
		if (inp[2] == '0') {
			cout << 0 << endl;
			return;
		}
		dp[1] = 1;
		if (dp.size() > 2) {
			dp[2] = 1;
		}
		start = 3;
	} else if (stoi(inp.substr(0, 2))<27) {
		dp[1] = 2;
	}
	else {
		dp[1] = 1;
	}

	for (int i = start; i < inp.length(); i++) {
		if (inp[i] == '0') {
			dp[i] = dp[i - 2];
			if (inp[i + 1] == '0') {
				cout << 0 << endl;
				return;
			}
			if (i + 1 < inp.length()) {
				dp[i + 1] = dp[i - 2];
			}

			i++;
		} else if (stoi(inp.substr(i-1, 2)) < 27) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		else {
			dp[i] = dp[i - 1];
		}
	}
	cout << dp[inp.length() - 1] << endl;
}

void output() {
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef HKD
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
	while (true) 	
	{
		cin >> inp;
		if (inp == "0") {
			exit(0);
		}
		input();
		solve();
		output();
	}
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif // DEBUG
	while (true)
	{
		cin >> inp;
		if (inp == "0") {
			exit(0);
		}
		input();
		solve();
		output();

	}
	return 0;
}