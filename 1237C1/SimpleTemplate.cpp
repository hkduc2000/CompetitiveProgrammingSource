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

struct point {
	int x, y, z;
	int stt;
};

bool sortx(point a, point b){
	if (a.x != b.x) { return a.x < b.x; }
	else if (a.y != b.y) { return a.y < b.y; }
	else return a.x < a.y;
}

bool isItCute(point a, point b, point c) {
	bool rt = (min(a.x, b.x) <= c.x) * (c.x <= max(a.x, b.x))
		* (min(a.y, b.y) <= c.y) * (c.y <= max(a.y, b.y))
		* (min(a.z, b.z) <= c.z) * (c.z <= max(a.z, b.z));
	return rt;
}
deque <point> a;
int n;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	cin >> n;
	a.resize(n);
	FOR(i, 0, n - 1) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		a[i].stt = i + 1;
	}
	sort(ALL(a), sortx);
	for (int i = 0; i < n; i += 2) {
		cout << a[i].stt << ' ' << a[i + 1].stt << endl;
	}

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}