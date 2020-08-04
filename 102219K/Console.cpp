#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
typedef long long ll;
ll sum;
int ans;
int t,n,duc;
vector <ll> a;

//---------------------

//function-------------

//---------------------

void input() {
	a.clear();
	ans = 0;
	sum = 0;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
}

void solve() {
	for (int i = 0; i < n; i++) {
		if (sum <= a[i]) {
			sum += a[i];
			ans++;
		}
	}
}

void output() {
	cout << "Case #" << duc - t << ": " << ans << endl;
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