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

const int N = 100000000;

int n; // array size 

// Max size of tree 
int tree[2 * N][4];

// function to build the tree 
void build()
{
	// insert leaf nodes in tree 
	for (int i = 0; i < n; i++)
		tree[n + i][1] = 1;

	// build the tree by calculating parents 
	for (int i = n - 1; i > 0; --i) {
		tree[i][ = tree[i << 1] + tree[i << 1 | 1];
	}	
}

// function to get sum on interval [l, r) 
int query(int l, int r)
{
	int res = 0;

	// loop to find the sum in the range 
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1)
			res += tree[l++];

		if (r & 1)
			res += tree[--r];
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
#endif

	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

	// build tree  
	build();

	// print the sum in range(1,2) index-based 
	cout << query(1, 3) << endl;



	// print the sum in range(1,2) index-based 
	cout << query(1, 3) << endl;

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}