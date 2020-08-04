#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
int n,m;
int a[51][51];
int b[51][51];
vector <pair<int, int>> filled;
//---------------------

//function-------------
void fill(int i, int j) {
	if ((i+1<n) && (j + 1 < m)) {
		if (a[i][j] == 1 &&
			a[i][j + 1] == 1 &&
			a[i + 1][j] == 1 &&
			a[i + 1][j + 1] == 1) {
			b[i][j] = 1;
			b[i][j + 1] = 1;
			b[i + 1][j] = 1;
			b[i + 1][j + 1] = 1;
			filled.push_back(make_pair(i + 1, j + 1));
		}
	} 
}
//---------------------

void input() {
	cin >> n >> m;
	int inp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> inp;
			a[i][j] = inp;
		}
	}
}

void solve() {
	for (int i = 0; i<n-1; i++) {
		for (int j = 0; j < m; j++) {
			fill(i, j);
		}
	}
}

void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				cout << -1;
				return;
			}
		}
	}
	cout << filled.size() << endl;
	for (int i = 0; i < filled.size(); i++) {
		cout << filled[i].first << ' ' << filled[i].second << endl;
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