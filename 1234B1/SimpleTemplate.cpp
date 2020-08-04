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

deque <int> screen;
map <int, bool> isOnScreen;
int n, k;
vector <int> ans;
map <int, bool> selected;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	scanf("%d", &n);
	scanf("%d", &k);
	screen.resize(k);
	int id;
	FOR(i, 0, n - 1) {
		scanf("%d", &id);
		if (isOnScreen[id]==false) {
			screen.push_front(id);
			isOnScreen[id] = true;
			isOnScreen[screen[k]] = false;
		}
	}

	selected[0] = true;
	FOR(i, 0, k-1) {
		if (selected[screen[i]] == false) {
			ans.push_back(screen[i]);
			selected[screen[i]] = true;
		}
	}

	printf("%d\n", ans.size());
	FOR(i, 0, ans.size() - 1) {
		printf("%d ", ans[i]);
	}


#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}