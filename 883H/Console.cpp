#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
#define HKD
int n,k;
string str;
vector <char> a;
map <char, int> m;
//---------------------

//function-------------

//---------------------

void input() {
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		m[str[i]]++;
	}
}

void solve() {
	vector <char> del;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second % 2) {
			k++;
			a.push_back(it->first);
			it->second--;
			if (it->second == 0) {
				del.push_back(it->first);
			}
		}
	}
	for (int i = 0; i < del.size(); i++) {
		m.erase(del[i]);
	}

	if (k == 0) {
		cout << 1 << endl;
		string left, right;
		for (auto it = m.begin(); it != m.end(); it++) {
			for (int i = 1; i <= (it->second)/2; i++) {
				left = left + it->first;
				right = it->first + right;
			}
		}
		cout << left << right;
		return;
	}

	if (n == k) {
		cout << str.length() << endl;
		for (int i = 0; i < n; i++) {
			cout << str[i] << ' ';
		}
		return;
	}

	if (((n - k) / 2) % k) {
		while (((n - k) / 2) % k) {
			k += 2;
			auto it = m.begin();
			if (it->second > 0) {
				it->second -= 2;
				a.push_back(it->first);
				a.push_back(it->first);
			}
			else {
				it++;
				a.push_back(it->first);
				a.push_back(it->first);
			}
		}
	}
		cout << k << endl;
		int cnt = (n - k) / 2 / k;
		string left, right;
		set <char> check;
		auto it = m.begin();
		while (it != m.end()) {
			while (it->second > 0) {
				left = left + it->first;
				right = it->first + right;
				check.insert(it->first);
				it->second -= 2;
				cnt--;
				if (cnt == 0) {
					check.insert(a.front());
					cout << left << a.front() << right << endl;
					/*for (auto i=check.begin(); i != check.end(); i++) {
						cout << *i;
					}
					check.clear();
					cout << endl;*/
					a.erase(a.begin());
					cnt = (n - k) / 2 / k;
					left = ""; right = "";
				}
			}
			it++;
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