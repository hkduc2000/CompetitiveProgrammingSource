#include <bits/stdc++.h>
#include <chrono>
#include <unordered_set>
using namespace std;

//define---------------
unordered_set <long long> a;
long long  n;
vector <long long > factor;
//---------------------

//function-------------
long long  gcd(long long  a, long long  b)
{
	if (a == 0)
		return b;
	return gcd(b % a, a);
}
//---------------------

void input() {
	cin >> n;
	long long  inp;
	for (long long  i = 0; i < n; i++) {
		cin >> inp;
		a.insert(inp);
	}
}

void solve() {
	long long  UCLN = *a.begin();
	for (auto it = a.begin(); it != a.end(); it++) {
		UCLN = gcd(*it, UCLN);
	}

	long long  add = 0;
	while (UCLN % 2 == 0)
	{
		add++;
		UCLN = UCLN / 2;
	}
	if (add) factor.push_back(add); 

	for (long long  i = 3; i <= sqrt(UCLN); i = i + 2)
	{
		long long  add = 0;
		while (UCLN % i == 0)
		{
			add++;
			UCLN = UCLN / i;
		}
		factor.push_back(add);
	}

	if (UCLN > 2) {
		factor.push_back(1);
	}
}

void output() {
	long long  result = 1;
	for (long long  i = 0; i < factor.size(); i++) {
		result *= (factor[i] + 1);
	}
	cout << result;
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