#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
//#define HKD
double  p,t;
double speed,ans;
//---------------------

//function-------------

//---------------------

void input() {
	cin >> t >> p;
}

void solve() {
	if (p >= 20) {
		speed = (100 - p) / t;
		ans = (p - 20) / speed + 40 / speed;
	}
	else {
		speed = (120 - 2*p) / t;
		ans = 2.0 * p / speed;
	}
	
}

void output() {
	cout << setprecision(4) << fixed << ans;
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