#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
int s,n,t,duc;
int ans;
vector<pair<int, int>> a;
//---------------------

//function-------------

//---------------------

void input() {
	ans = INT_MIN;
	a.clear();
	cin >> n >> s;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		int time = s- a[i].second;
		if (time >= 0) {
			ans = max(ans, a[i].first);
		}
		else {
			ans = max(ans, a[i].first - (a[i].second - s));
		}
	}
}

void output() {
	cout << "Case #" << duc-t << ": " << ans << endl;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef HKD
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
	cin >> t;
	duc = t;
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
	duc = t;
	while (t--)
	{
		input();
		solve();
		output();

	}
	return 0;
}