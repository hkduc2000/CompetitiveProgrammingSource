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


int const limit = 501;
int w, h, q , ans;
string sl[limit];
int hor[limit][limit];
int ver[limit][limit];


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif
	scanf("%d %d", &h, &w);
	FOR(i, 0, h-1) cin >> sl[i];

	FOR(i, 0, h-1) FOR(j, 0, w-1) {
		hor[i + 1][j + 1] = hor[i + 1][j] + hor[i][j + 1] - hor[i][j];
		ver[i + 1][j + 1] = ver[i + 1][j] + ver[i][j + 1] - ver[i][j];
		if (sl[i][j] == '.') {
			if ((j + 1 < w) && (sl[i][j + 1] == '.')) hor[i + 1][j + 1]++;
			if ((i + 1 < h) && (sl[i + 1][j] == '.')) ver[i + 1][j + 1]++;
		}

	}

	scanf("%d", &q);
	int x1, y1, x2, y2;
	FOR(i, 0, q-1) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--; y1--;
		ans = hor[x2][y2 - 1] - hor[x1][y2 - 1] - hor[x2][y1] + hor[x1][y1];
		ans += ver[x2-1][y2] - ver[x1][y2] - ver[x2-1][y1] + ver[x1][y1];
		printf("%d\n", ans);
	}


#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}