#include <bits/stdc++.h>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORD(i, a, b) for (int i=a; i<=b; i--)
#define FOREACH(a, b) for (auto&(a) : (b)) 
#define MAX(a, b) a = max(a, b) 
#define MIN(a, b) a = min(a, b) 
#define fi first 
#define se second 
#define pb push_back 
#define ALL(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz)) 
//#define DEBUG

int n, m;
const int nmax = 1e3 + 10;
const ll base = 1e11;
const ll oo = 1e17;
ll res = 0;
typedef pair<ll, int> li;
vector<li> g[nmax];
ll d[nmax];
int nume[nmax];
ll cmin[nmax];
int cl[nmax];
priority_queue<li, vector<li>, greater<li> > q;

void dijkstra(int s)
{
	for (int i = 1; i <= n; i++)
	{
		d[i] = oo;
		cl[i] = 0;
		cmin[i] = oo;
		nume[i] = 0;
	}
	q.push(li(d[s], s));
	while (!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if (cl[u]) continue;
		cl[u] = 1;
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i].second;
			ll c = g[u][i].first;

			if (d[v] > min(c, cmin[u]) * (nume[u] + 1))
			{
				cmin[v] = min(c, cmin[u]);
				nume[v] = nume[u] + 1;
				d[v] = cmin[v] * nume[v];
				q.push(li(d[v], v));
			}
		}
	}
	for (int i = 1; i <= n; i++) if (i != s)
	{
		res = (res + d[i]) % base;
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
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		ll c;
		cin >> u >> v >> c;
		g[u].pb(li(c, v));
		g[v].pb(li(c, u));
	}
	for (int i = 1; i <= n; i++) dijkstra(i);
	res = (res/2) % (int)(1e9);
	cout << res;
	


#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}