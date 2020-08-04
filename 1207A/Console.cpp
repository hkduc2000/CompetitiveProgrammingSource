#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
int t;
int b, p, f,h,c;
int ans;
//---------------------

//function-------------

//---------------------

void input() {
	cin >> b >> p >> f >> h >> c;
}

void solve() {
	ans = 0;
	if (h > c) {
		ans += min(p, b / 2) * h;
		b -= min(p, b / 2) * 2;
		ans += min(f, b / 2) * c;
	}
	else {
		ans += min(f, b / 2) * c;
		b -= min(f, b / 2) * 2;
		ans += min(p, b / 2) * h;
	}
}

void output() {
	cout << ans << endl;
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