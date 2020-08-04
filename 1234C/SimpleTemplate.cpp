#include <bits/stdc++.h>
#include <chrono>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i=a; i<=b; i++)
//#define DEBUG

int n, t;
string row[2];

int toNum(char ch) {
	return (int)ch - 48;
}

void solve() {
	cin >> n;
	cin >> row[0] >> row[1];
	int sw = 0;
	FOR(i, 0, n - 1) {
		if (toNum(row[sw][i]) > 2) {
			sw = 1 - sw;
			if (toNum(row[sw][i]) <= 2) {
				printf("NO\n");
				return;
			}
		}
	}
	if (sw) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	cin >> t;
	while (t--) {
		solve();
	}


#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}