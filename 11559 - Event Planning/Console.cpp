#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
//#define HKD
int N, H, B, W;
//---------------------

//function-------------

//---------------------

void input() {
	while (scanf("%d %d %d %d", &N, &B, &H, &W) == 4) {
		int min_cost = INT_MAX;
		int p;
		for (int i = 0; i < H; i++) {
			scanf("%d", &p);
			int space;
			int cost = INT_MAX;
			for (int j = 0; j < W; j++) {	
				scanf("%d", &space);
				if (space >= N) {
					cost = p * N;
				}
			}
			if (cost < B) {
				min_cost = min(min_cost, cost);
			}
		}
		if (min_cost == INT_MAX) {
			printf("stay home\n");
		}
		else {
			printf("%d\n", min_cost);
		}
	}
}

void solve() {

}

void output() {

}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef HKD
	freopen("E:/C++/input.txt", "r", stdin);
	freopen("E:/C++/output.txt", "w", stdout);
	auto start = chrono::steady_clock::now();
	{
		input();
		solve();
		output();
	}
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif // DEBUG

	{
		input();
		solve();
		output();

	}
	return 0;
}