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

int cinemasBuildingCost(std::vector<std::string> citiesList, std::vector<std::string> roads)
{
	map <string, pair<int,int>> costTable;
	map <int, bool> isMainID;
	//Input handling
	int ID = 0;
	FOR(i, 0, citiesList.size() - 1) {
		string str = citiesList[i];
		replace(str.begin(), str.end(), ';', ' ');
		stringstream ss(str);
		string city; int cost;
		ss >> city; ss >> cost;
		costTable[city].first = cost;
		costTable[city].second = ID;
		ID++;
	}
	if (roads.size()) {
		FOR(i, 0, roads.size() - 1) {
			string str = roads[i];
			replace(str.begin(), str.end(), ';', ' ');
			stringstream ss(str);
			string city1, city2;
			ss >> city1 >> city2;
			if (isMainID[costTable[city2].second]) {
				costTable[city1].second = costTable[city2].second;
			}
			else {
				costTable[city2].second = costTable[city1].second;
				isMainID[costTable[city1].second] = true;
			}
		}
	}

	int ans = 0;
	map <int, bool> printed;
	map <int, int> minCostOfID;
	for (auto it = costTable.begin(); it != costTable.end(); it++) {
		int cost = it->second.first;
		int ID = it->second.second;
		if ((minCostOfID[ID] > cost) || (minCostOfID[ID] == 0)) {
			minCostOfID[ID] = cost;
		}
	}

	for (auto it = minCostOfID.begin(); it != minCostOfID.end(); it++) {
		ans += it->second;
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

	vector <string> citiesList = { "p;45", "c;657", "e;184", "u;30", "f;849", "x;812", "i;874", "y;440", "j;148", "n;254" };

	vector <string> roads = { "p;e","p;y","c;x","c;j","c;n","e;f","e;x","e;j","u;x","u;i","u;y","u;j","f;y","f;n","i;n","y;j" };
	cinemasBuildingCost(citiesList, roads);

#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}