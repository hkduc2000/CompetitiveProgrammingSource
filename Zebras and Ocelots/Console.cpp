#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
int n;
vector <char> a;
typedef long long ll;
ll ans;
//---------------------

//function-------------

//---------------------

void input() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void solve() {
	reverse(a.begin(),a.end());
	for (int i = 0; i < n; i++) {
		if (a[i] == 'O') {
			ans +=  ll(pow(2, i));
		}
	}
}

void output() {
	cout << ans;
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