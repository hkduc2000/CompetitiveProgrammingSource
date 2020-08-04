#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
using namespace std;

//define---------------
//#define HKD
int n;
unordered_map <string,string> award_list;
vector <string> order;
//---------------------

//function-------------

//---------------------

void input() {
	cin >> n;
	for (int i = 0; (i < n) && (award_list.size()<12); i++) {
		string university, team;
		cin >> university >> team;
		if (award_list[university] == "") {
			award_list[university] = team;
			order.push_back(university);
		}
	}
}

void solve() {
	for (int i = 0; i < order.size()-1; i++) {
		cout << order[i] << ' ' << award_list[order[i]] << endl;
	}
	cout << order.back() << ' ' << award_list[order.back()];
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