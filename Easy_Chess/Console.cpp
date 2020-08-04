#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
//#define HKD
int n;
int mid = 3;
bool board[8][8];
string rowboard = "abcdefgh";
//---------------------

//function-------------

void goTo(int i, int j) {
	cout << rowboard[j] << i + 1 << ' ';
	board[i][j] = true;
	n--;
}

void endGame(int j) {
	if (n == 2) {
		cout << rowboard[j] << 8 << ' '; //End game with 2 step
	}
	cout << "h8" << ' ';
	exit(0);
}

void handleRow(int row, int a, int b, int stopPoint) {
	mid = 7 - mid;
	int sw = 1;
	while (board[row][a] == false ||
		board[row][b] == false) {
		if (sw && (board[row][b] == false)) {
			goTo(row, b);
			if (n == stopPoint) endGame(b);
			b--;
		}
		else {
			goTo(row, a);
			if (n == stopPoint) endGame(a);
			a++;
		}
		sw = 1 - sw;
	}
	goTo(row + 1, mid);
}

//Check if the game can end now or not?
void preHandle(int row, int mid) {

	if (n == 2) {
		endGame(mid);
	}


	if (n == 3) {
		cout << rowboard[mid + 1] << row + 1 << ' ';
		cout << rowboard[mid + 1] << 8 << ' ';
		cout << "h8" << ' ';
		exit(0);
	}
}

//---------------------

void input() {
	cin >> n;
	board[0][0] = true;
}

void solve() {
	//Row 1 handling
	cout << "a1" << ' ';
	preHandle(0, 0);
	handleRow(0, 1, 7, 2);

	//Row 2-7
	for (int i = 1; i < 7; i++) {
		preHandle(i, mid);
		handleRow(i, 0, 7, 2);
	}

	//Row 8
	handleRow(7, 0, 6, 1);
	cout << "h8" << ' ';
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
	}
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif // DEBUG

	{
		input();
		solve();
	}
	return 0;
}