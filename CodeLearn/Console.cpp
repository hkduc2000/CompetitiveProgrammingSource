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

double fen(double x, double y, int n) {
	double rt = x + x * x * y;
	long long int factorial = 1;
	int a;
	/*run from 1 to avoid case i=0 when calculate factorial
	and stop when factorial is exceed limit of long long
	because when it exceed the limit, value of 
	(pow(x, 2 * i + 2) * pow(y, 2 * i + 1)) / factorial
	is not remarkable
	*/
	for (int i = 1; (i <= n)&& (factorial>0); i++) {
		//factorial calculation
		factorial = factorial * ((2 * i) * (2 * i + 1));
		//a = (-1)^i 
		a = (i % 2) ? -1 : 1;
		rt += (double)a * (pow(x, 2 * i + 2) * pow(y, 2 * i + 1)) / factorial;
	}
	return rt;
}


int main()	
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif
	double x, y;
	int n;
	scanf("%lf", &x);
	scanf("%lf", &y);
	scanf("%d", &n);
	printf("fen(x,y,n) = %.4f", fen(x, y, n));
#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 
}