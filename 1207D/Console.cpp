#include <bits/stdc++.h>
#include <chrono>
using namespace std;

//define---------------
//#define HKD
typedef long long ll;
#define ii pair<ll, ll>
const ll MOD = 998244353;
ll n;
ll res=1, A=1, B=1, C = 1;
vector <ii> v;
//---------------------

//function-------------
bool compareFirst(ii a, ii b) {
	return (a.first < b.first);
}

bool compareSecond(ii &a,ii &b)
{
	return (a.second < b.second);
}

ll fac(ll n) {
	ll rt = 1;
	for (ll i = 1; i <= n; i++) {
		rt = (rt * i) % MOD;
	}
	return rt;
}
//---------------------

void input() {
	cin >> n;
	v.resize(n);
	for (ll i = 0; i < n; i++) {
		res = (res * ll(i+1)) % MOD; //install res
		cin >> v[i].first >> v[i].second;
	}
	
	
}

void solve() {
	sort(v.begin(), v.end(), compareFirst);
	vector <ii>t = v;
	// check equal subsequece and sort subsequence again in term of second
	for (ll i = 0; i < n-1; i++) {
		if (v[i].first == v[i + 1].first) {
			ll j = i; 	i++;
			while ((i < n) && (v[i].first == v[j].first)) {
				i++;
			}
			ll add = i - j;
			A = (A * fac(add))%MOD;
			//sort again
			sort(v.begin() + j, v.begin() + i, compareSecond);
			i--;
		}
	}
	
	sort(t.begin(), t.end(), compareSecond);
	for (ll i = 0; i < n - 1; i++) {
		if (t[i].second == t[i + 1].second) {
			ll j = i; 	i++;
			while ((i < n) && (t[i].second == t[j].second)) {
				i++;
			}
			ll add = i - j;
			B = (B * fac(add))%MOD;
			i--;
		}
	}

	bool check = true;
	for (ll i = 0; i < n; i++) {
		if (v[i].second != t[i].second) {
			check = false;
			break;
		}
	}

	if (check) {
		for (ll i = 0; i < n - 1; i++) {
			if (v[i].second == v[i + 1].second && 
				v[i].first == v[i+1].first) {
				ll j = i; 	i++;
				while ((i<n) && 
					(t[i].second == t[j].second) &&
					(v[j].first == v[i].first)) {
					i++;
				}
		
				ll add = i - j;
				C = (C * fac(add)) % MOD;
				i--;
			}
		}
	}
	else {
		C = 0;
	}

}

void output() {
	res = ((res - A) % MOD + MOD) % MOD;
	res = ((res - B) % MOD + MOD) % MOD;
	res = (res + C) % MOD;
	cout << res;
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