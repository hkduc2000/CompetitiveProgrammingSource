#include <bits/stdc++.h>
#include <chrono>
#include <unordered_set>
using namespace std;

//define---------------
int n,t;
map <int, int> inp;
vector <pair<int, int>> a;
unordered_set <long long> check;

//---------------------

//function-------------

//---------------------

void input() {
	cin >> n;
	check.clear();
	inp.clear();
	a.clear();
	int m;
	for (int i = 0; i < n * 4; i++) {
		cin >> m;
		inp[m]++;
	}
	for (auto it = inp.begin(); it != inp.end(); it++) {
		a.push_back(make_pair(it->first,it->second));
	}
}

void solve() {
	for (int i = 0; i <= a.size()/2; i++) {
		int op = a.size() - 1 - i;
		if ((a[i].first == a[op].first)&&(a[i].second % 4==0))  {
			check.insert(a[i].first * a[op].first);
		} else if ((a[i].second == a[op].second) && (a[i].second%2==0)) {
			check.insert(a[i].first * a[op].first);
		}
		else {
			cout << "NO" << endl;
			return;
		}
	}
	if (check.size() == 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
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