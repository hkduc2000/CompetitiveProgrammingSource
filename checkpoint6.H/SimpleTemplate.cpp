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

int n, c, b;
vector <int> bb;
string ans;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	cin >> n >> c >> b;
	bb.resize(b);
	FOR(i, 0, b-1) {
		cin >> bb[i];
	}
	bb.push_back(INT_MAX);
	if (c%2){
		ans += "10";
		c--;
	}
	else {
		ans += '0';
	}

	int j = 0;
	for (int i = ans.size()+1; i <= n; i++) {
		if (c == 0) {
			ans += '0';
			continue;
		}
		if (i > bb[j]) j++;
		if (i != bb[j]) {
			if (ans.back() == '1') {
				ans += '0';
			}
			else {
				ans += '1';
				c -= 2;
			}

		}
		else {
			ans += '0';
		}
	}
	cout << ans;

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}