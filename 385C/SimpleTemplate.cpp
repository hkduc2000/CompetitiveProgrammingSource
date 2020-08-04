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

int n, q;
vector <int> a;
vector <int> primenum;
#define limit 10000000
int cnt[limit + 1] = { 0 };
int pre[limit + 1] = { 0 };
bool prime[limit + 1] = { false };

//Domain of f(x) is just inluded in prime numbers so we just have to count how 
//many numbers in input that divisable for each prime number in 
//range (2 to max(element)).

void SieveOfEratosthenes() {
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	prime[0] = false;
	for (int p = 2; p * p <= limit; p++) {
		if (prime[p]) {
			for ( int i = p*p; i <= limit; i += p) {
				prime[i] = false;
			}
		}
	}
	for (int p = 2; p <= limit; p++) {
		if (prime[p]) {
			for (int i = p; i <= limit; i += p) {
				pre[p] += cnt[i];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif
	//First have to generate a map of pair including prime number X and the number Y
	// of numbers that are divisable for X. Let's consider limit of X, X will be
	// limited by the maximum element of input array.
	//After that, count the number 
	scanf("%d", &n);
	FOR(i, 0, n - 1) {
		int inp;
		scanf("%d", &inp);
		cnt[inp]++;
	}
	SieveOfEratosthenes();

	FOR(i, 1, limit) {
		pre[i] += pre[i - 1];
	}

	//Fucking queries
	scanf("%d", &q);
	FOR(i, 0, q - 1) {
		int l, r;
		scanf("%d %d", &l, &r);
		l = min(l, limit);
		r = min(r, limit);
		l--;
		int ans = pre[r] - pre[l];
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
