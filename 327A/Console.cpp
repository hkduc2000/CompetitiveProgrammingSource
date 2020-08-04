#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
int n, one, ze ;
int maxprofit = INT_MIN;
vector <pair<int, int>> a;
//---------------------

//function-------------
int profit(int i, int j) {
	return (a[i].second - a[j-1].second) - (a[i].first - a[j-1].first);
}
//---------------------

void input() {
	cin >> n;
	a.resize(n+1);
	int inp;
	for (int i = 1; i <= n; i++) {
		cin >> inp;
		(inp) ? one++ : ze++;
		a[i].first = one;
		a[i].second = ze;
	}
}

void solve() {
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j <= i; j++) {
			maxprofit = max(maxprofit,profit(i,j));
		}
	}
}

void output() {
	cout << one + maxprofit;
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