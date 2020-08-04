#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
//#define HKD
int n;
double e;
vector <double> fac;
//---------------------

//function-------------

//---------------------

void input() {
	cin >> n;
	fac.resize(n + 1);
	fac[0] = 1;
	e = 1;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
		e += (1.0 / fac[i]);
	}
}

void output() {
	cout << setprecision(12) << fixed  << e;
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