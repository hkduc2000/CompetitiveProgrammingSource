#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
typedef long long ll;
ll t;
ll n;
ll pipe, pillar;
ll ans;
string road;

//---------------------

//function-------------

//---------------------

void input() {
	ans = 0;
	cin >> n >> pipe >> pillar;
	cin >> road;
}

void solve() {
	ll i = 0;
	while ((road[i] == '0') && (i < n)) {
		ans += pipe + pillar;
		i++;
	}
	if (i == n) {
		ans += pillar;
		cout << ans << endl;
		return;
	}

	ll j = n-1;
	while (road[j] == '0') {
		ans += pipe + pillar;
		j--;
	}

	ans += pipe*2;

	ans += (j - i + 1) * (2 * pillar + pipe) + 2*pillar;

	for (ll it = i; it <= j; it++) {
		if (road[it] == '0') {
			ll s = it;
			while (road[it] == '0') {
				it++;
			}
			ll dis = it - s;
			ans += min(2 * pipe -(dis - 1) * pillar,ll(0));
		}
	}
	cout << ans <<endl;
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