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



int main()
{
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	int a, b, c, d, e;
	//printf("Enter number: ");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	if (a > b) {
		a = a + b;
		b = a - b;
		a = a - b;
	}
	if (a > c) {
		a = a + c;
		c = a - c;
		a = a - c;
	}
	if (a > d) {
		a = a + d;
		d = a - d;
		a = a - d;
	}
	if (a > e) {
		a = a + e;
		e = a - e;
		a = a - e;
	}
	if (b > c) {
		b = b + c;
		c = b - c;
		b = b - c;
	}
	if (b > d) {
		b = b + d;
		d = b - d;
		b = b - d;
	}
	if (b > e) {
		b = b + e;
		e = b - e;
		b = b - e;
	}
	if (c > d) {
		c = c + d;
		d = c - d;
		c = c - d;
	}
	if (c > e) {
		c = c + e;
		e = c - e;
		c = c - e;	
	}		
	if (d > e) {
		d = d + e;
		e = d - e;
		d = d - e;
	}

	printf("Sorted list: %d %d %d %d %d\n", a, b, c, d, e);
	printf("Sum: %d", a + b + c + d + e);


#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	return 0;

#endif 

	return 0;
}