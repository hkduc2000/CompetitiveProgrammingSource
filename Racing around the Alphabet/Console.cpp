#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------

//#define HKD
int n;
const double r = 60 * 3.14159265359;
map <char, int> loc;
double ans;
//---------------------

//function-------------
double distance(char s, char e) {
	int big = max(loc[s], loc[e]);
	int small = min(loc[s], loc[e]);
	return 1.0*min(big - small, 28 - (big - small));
}
//---------------------

void solve() {
	for (int i = 0; i < 26; i++) {
		loc[char(65 + i)] = i;
	}
	loc[' '] = 26;
	loc['\''] = 27;
	string strn;
	getline(cin, strn);
	n = stoi(strn);
	while (n--) {
		string str;
		getline(cin, str);
		ans = 0;
		int t = 0;
		for (int i = 0; i < str.length() - 1; i++) {
			ans += (distance(str[i], str[i + 1]) * 1.0 * r / 28.0);
			t++;
		}
		ans /= 15.0;
		ans += t;
		cout << setprecision(6) << fixed << ans + 1 << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef HKD
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
	{
		solve();
	}
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif // DEBUG

	{
		solve();
	}
	return 0;
}