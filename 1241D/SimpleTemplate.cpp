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

int const maxn = 300001;
int n, t;
map <int, bool> lis;

int main()
{	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	//freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		deque<int> a(n);
		vector<int> cnt(maxn);
		lis.clear();
		int inp;
		FOR(i, 0, n-1) {
			scanf("%d", &inp);
			a[i] = inp;
			cnt[a[i]]++;
			lis[a[i]] = true;
		}
		int maxe = *max_element(ALL(a));
		int ans = 0;
		FOREACH(it,lis) {
			int i = 0;
			if (it.fi == maxe) break;
			while (it.fi >= a[i]) {
				if (it.fi ==a[i]) {
					cnt[it.fi]--;
				}
				i++;
			}
			if (cnt[it.fi] > 0) {
				ans++;
			}
		}
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