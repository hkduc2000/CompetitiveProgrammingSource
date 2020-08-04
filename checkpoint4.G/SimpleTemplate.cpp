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

const size_t MAX_COUNT = 100000;

struct info {
	int score, pen;

	bool operator< (const info& i) const {
		return (score == i.score) ? pen > i.pen : score < i.score;
	}
};

info scoreboard[MAX_COUNT];
bool visit[MAX_COUNT];
queue<int> q;

int main() {
	int count = 0, submit = 0;
	cin >> count >> submit;

	int rank = 1;
	for (int i = 0; i < submit; i++) {
		int id = 0, pt = 0;
		cin >> id >> pt;
		scoreboard[id].score++;
		scoreboard[id].pen += pt;
		if (id != 1) {
			if (scoreboard[1] < scoreboard[id]) {
				if (!visit[id]) {
					visit[id] = true;
					q.push(id);
					rank++;
				}
			}
		}
		else {
			int t = rank;
			for (int j = 1; j < t; j++) {
				int next = q.front();
				q.pop();

				if (scoreboard[1] < scoreboard[next]) {
					q.push(next);
				}
				else {
					visit[next] = false;
					rank--;
				}
			}
		}
		cout << rank << endl;
	}
	return 0;
}