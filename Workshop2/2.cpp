#include <bits/stdc++.h>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
using namespace std;


typedef long long ll;
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORD(i, a, b) for (int i=a; i>=b; i--)
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

/*
With the easy one we just need to iterate all possible substring and remove
it.
After that, check if t is remain a substring of s
*/

string s, t;
int ans = INT_MIN;
unordered_set <string> counter;

bool HoangKimDuc(string sub) {
	int pos = 0;
	for (int i = 0; (i < sub.length()) && (pos < t.length()); i++) {
		if (sub[i] == t[pos]) pos++;
	}
	return (pos == t.length());
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	cin >> s >> t;
	FOR(i, 0, s.length() - 1) {
		FOR(j, i + 1, s.length()) {
			string sub = s.substr(0, i) + s.substr(j, s.length() - j);
			if ((sub != "") && HoangKimDuc(sub)) {
				ans = max(ans, int(s.length() - sub.length()));
			}
			//cout << s.substr(0, i) << ' ' <<
			//	s.substr(j, s.length() - j) << endl;
			counter.insert(sub);
		}
		ans = max(ans, 0);
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