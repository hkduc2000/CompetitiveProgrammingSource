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
vector <string> s;

bool isNum(char ch) {
	return ((ch > 47) * (ch < 58));
}

bool compare(string file) {
	bool waiting = false;
	string n1;
	string n2;
	FOR(i, 0, s[0].length()) {
		if (i == min(file.length(),s[0].length())) {
			if (waiting) {
				return stoi(n2) > stoi(n1);
			}
			return (i==s[0].length());
		}
		char x = s[0].at(i);
		char y = file.at(i);
		bool xIsNum = isNum(x);
		if (xIsNum) {
			n1 += x;
		}
		bool yIsNum = isNum(y);
		if (yIsNum) {
			n2 += y;
		}
		if (xIsNum && yIsNum) { waiting = true; }
		if (xIsNum + yIsNum == 1) {

		}

		if (waiting == false) {
			if ((int)x < (int)y) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	return 1;
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
	s.resize(n + 1);
	FOR(i, 0, n) cin >> s[i];
	

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}