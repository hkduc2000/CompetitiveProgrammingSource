#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
string str;
int n;
char a[1001][1001];
//---------------------

//function-------------

char trans(char ch) {
	switch (ch)
	{
	case '^':
		return '>';
		break;
	case '>':
		return 'v';
		break;
	case 'v':
		return '<';
		break;
	case '<':
		return '^';
		break;
	default:
		return '.';
		break;
	}
}

void turnRight() {
	vector <char> save;
	int max_layer = n / 2;
	if (n % 2) {
		a[n / 2][n / 2] = trans(a[n / 2][n / 2]);
	}
	for (int layer = 0; layer < max_layer; layer++) {
		save.clear();
		//from top to left and safe left.
		for (int i = 1+layer; i < n-layer; i++) {
			save.push_back(a[i][n-layer-1]);
		}
		//from top to right
		for (int j = n - layer - 1; j >= 0 + layer; j--) {
			a[j][n-1-layer] = trans(a[layer][j]);
		}
		//from left to top
		int cnti = n - layer - 1;
		for (int j = layer; j <= n - layer - 2; j++) {
			a[layer][j] = trans(a[cnti][layer]);
			cnti--;
		}
		//from bottom to left
		a[n - layer - 1][layer] = trans(save.back());
		for (int j=n-layer-2;j>=layer+1;j--){
			a[j][layer] = trans(a[n - layer - 1][j]);
		}
		//return left to bottom
		int cntj = n - layer - 2;
		for (int it = 0; it < save.size();it++) {
			a[n - layer - 1][cntj] = trans(save[it]);
			cntj--;
		}
	}
}

//---------------------

void input() {
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}

void solve() {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'R') {
			cnt++;
		}
		else {
			cnt += 3;
		}
	}
	cnt = cnt % 4;
	for (int i = 0; i < cnt; i++) {
		turnRight();
	}
}

void output() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j];
		}
		cout << endl;
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