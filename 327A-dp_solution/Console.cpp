#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
#define HKD
int n;
vector <int> a, b;
//---------------------

//function-------------

//---------------------

void input() {
	cin >> n;
	a.resize(n);
	b = a;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
}

void solve() {
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] &&
				b[i] < b[j]+a[i]) {
				b[i] = b[j] + a[i];
			}
		}
	}
}

void output() {
	cout << *max_element(b.begin(), b.end());
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