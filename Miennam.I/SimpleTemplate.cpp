#include <bits/stdc++.h>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORD(i, a, b) for (int i=a; i>=0; i--)
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

ll ans[3];
long double n;
vector <int> op;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	cin >> ans[0] >> ans[1] >> ans[2] >> n;
	while (n > 1) {
		ll parent = ll(n + 1) / 3;
		if ((n / 3) < parent) {
			op.push_back(1);
		}
		else if ((n / 3) == parent) {
			op.push_back(2);
		}
		else {
			op.push_back(3);
		}
		n = parent;
	}
	FORD(i, op.size() - 1, 0) {
		ll R = ans[0], G=ans[1],B=ans[2];
		if (op[i] == 1) {
			ans[0] = R + G;
			ans[1] = B;
			ans[2] = G;
		}
		else if (op[i] == 2) {
			ans[0] = B;
			ans[1] = G + B;
			ans[2] = R;
		}
		else {
			ans[0] = G;
			ans[1] = R;
			ans[2] = B+R;
		}
	}

	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];


#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}