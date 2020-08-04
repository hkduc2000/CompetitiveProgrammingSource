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
#define DEBUG

int n;
vector <int> queries;
bool dp[1000001];
int const nmax = 1000001;
int p[nmax];
int snt[nmax];
int cnt = 0;

void sangnt(int nn)
{
	for (int i = 1; i <= nn; i++) p[i] = 1;
	p[1] = 0;
	for (int i = 2; i * i <= nn; i++) if (p[i])
	{
		snt[++cnt] = i;
		int j = i + i;
		while (j <= nn)
		{
			p[j] = 0;
			j += i;
		}
	}
}

int numOfDigit(int x)
{
	int res = 0;
	while (x > 0)
	{
		res++;
		x /= 10;
	}
	return res;
}

int totient(int x)
{
	if (p[x]) return x - 1;
	int res = x;
	for (int i = 1; i <= cnt; i++)
	{
		if (snt[i] > x) break;
		if (x % snt[i] == 0)
		{
			res = res * (snt[i] - 1) / snt[i];
		}
		while (x % snt[i] == 0) x /= snt[i];
	}
	return res;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif
	scanf("%d", &n);
	queries.resize(n);
	FOR(i, 0, n - 1) {
		scanf("%d", &queries[i]);
	}

	int last = *max_element(ALL(queries));
	dp[0] = 0;
	sangnt(last);
	FOR(i, 1, last) {
		int k1 = i - totient(i);
		int k2 = i - numOfDigit(i);
		bool case1 = !dp[i - 1];
		bool case2 = !dp[k1];
		bool case3 = !dp[k2];
		dp[i] = case1 + case2 + case3;
	}

	FOR(i, 0, n - 1) {
		if (dp[queries[i]]) {
			printf("BACH\n");
		}
		else {
			printf("KHOA\n");
		}
	}

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}