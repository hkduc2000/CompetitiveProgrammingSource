#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i++)
#define pb push_back;
#define DEBUG

int n;
set <pair<int, int>> ind;
int ans=0;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
#endif
	cin >> n;
	vector <int> len(n);
	vector <vector<int>> re(n);
	vector <int> d(n);
	FOR(a, 0, n - 1) {
		cin >> len[a] >> d[a];
		int b;
		if (d[a] == 0) {
			ind.insert(make_pair(len[a], a));
		}
		FOR(j, 1, d[a]) {
			cin >> b; b--;
			re[b].push_back(a);
		}
	}
	int cnt = 0;
	while (ind.size() > 0) {
		auto wo = --ind.end();
		int lcur = wo->first;
		int cur = wo->second;
		ind.erase(wo);
		ans = max(ans, lcur + cnt);
		cnt++;
		FOR(i, 0, int(re[cur].size() - 1)) {
			int rel = re[cur][i];
			d[rel]--;
			if (d[rel] == 0) {
				ind.insert(make_pair(len[rel], rel));
			}
		}
	}
	cout << ans;
}
