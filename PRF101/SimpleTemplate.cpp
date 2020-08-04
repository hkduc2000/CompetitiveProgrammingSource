#include<bits/stdc++.h>
using namespace std;

#define DEBUG
#define dur second
#define pow first
#define FOR(i,a,b) for(int i=a;i<=b;i++)
int t, n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> t;
	while (t--) {
		cin >> n;
		vector <int> mons(n);
		FOR(i, 0, n - 1) cin >> mons[i];
		cin >> m;
		vector <pair<int, int>> hero(m);
		FOR(i, 0, m - 1) {
			cin >> hero[i].pow >> hero[i].dur;
		}
		sort(hero.begin(), hero.end());
		sort(mons.begin(), mons.end(), [](int a, int b) { return a > b; });
		for (int i = 0; i < n; i++) cout << mons[i];
	}
}