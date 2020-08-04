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

std::vector<int> queriesOnRectange(int n, int m, std::vector<std::vector<int>> queries1, std::vector<std::vector<int>> queries2)
{
	vector <int> dp(n * m+1);
	FOR(i,0,queries1.size()-1){
		int s = queries1[i][0] * m + queries1[i][1];
		int e = queries1[i][2] * m + queries1[i][3];
		dp[s]++;
		dp[e+1]--;
	}
	FOR(i, 1, m* n - 1) {
		dp[i] = dp[i] + dp[i - 1];
	}

	FOR(i, 1, m* n - 1) {
		dp[i] += dp[i - 1];
	}
	vector <int> ans;

	FOR(i, 0, queries2.size() - 1) {
		int a = 0;
		FOR(r, queries2[i][0], queries2[i][2]) {
			int s = r * m + queries2[i][1];
			int e = r * m + queries2[i][3];
			if (s != 0) {
				a += dp[e] - dp[s-1];
			}
			else {
				a += dp[e];
			}
		}
		ans.push_back(a);
	}
	return ans;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	vector <vector<int>> queries1 = { {0, 0, 9, 9} };
	vector <vector<int>> queries2 = { {0, 0, 9, 9}, {2, 0, 2, 3} };
queriesOnRectange(10, 10, queries1, queries2);


#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}