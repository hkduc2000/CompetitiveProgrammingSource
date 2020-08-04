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
#define PI 3.141592654
#define DEBUG

int arr[4];
int t,n;

int bacba(float a, float b, float c, float d)
{
	int rt = INT_MAX;
	double rs[3];
	float dt, k, x1, x2, x3, x;
	dt = pow(b, 2) - 3 * a * c;
	k = ((double)9 * a * b * c - (double)2 * pow(b, 3) - (double)27 * pow(a, 2) * d) / (2 * sqrt(pow(fabs(dt), 3)));
	if (dt > 0)
	{
		if (fabs(k) <= 1)
		{
			rs[0] = ((double)2 * sqrt(dt) * cos(acos(k) / (double)3) - b) / ((double)3 * a);
			rs[1] = ((double)2 * sqrt(dt) * cos(acos(k) / (double)3 - ((double)2 * PI / (double)3)) - b) / ((double)3 * a);
			rs[2] = ((double)2 * sqrt(dt) * cos(acos(k) / (double)3 + ((double)2 * PI / (double)3)) - b) / ((double)3 * a);
			FOR(i, 0, 2) {
				int rounded = round(rs[i]);
				if ((pow(rounded, 3) * a + rounded * rounded * b
					+ rounded * c + rounded * a) == 0) {
					rt = min(rt, rounded);
				}
			}
		}
		if (fabs(k) > 1)
		{
			x = ((sqrt(dt) * fabs(k)) / (3 * a * k)) * (pow((fabs(k) + sqrt(pow(k, 2) - 1)), 1.0 / 3) + pow((fabs(k) - sqrt(pow(k, 2) - 1)), 1.0 / 3)) - (b / (3 * a));
			return x;
		}
	}
	else if (dt == 0)
	{
		x = (-b - pow(-(pow(b, 3) - 27 * a * a * d), 1.0 / 3)) / (3 * a);//do ham pow khong dung doi so am nen ta phai doi dau.Ct goc:x=(-b+pow(pow(b,3)-27*a*a*d),1.0/3))/(3*a)
		return x;
	}
	else
	{
		x = (sqrt(fabs(dt)) / (3 * a)) * (pow((k + sqrt(k * k + 1)), 1.0 / 3) - pow(-(k - sqrt(k * k + 1)), 1.0 / 3)) - (b / (3 * a));
		return x;
	}
}

int bachai(float a, float b, float c)
{
	int rt=INT_MAX;
	float d, x1, x2;

	d = b * b - 4 * a * c;
	if (d == 0)
	{
		return (-b / (2 * a));
	}
	else
	{
		x1 = (-b - sqrt(d)) / (2 * a);
		x2 = (-b + sqrt(d)) / (2 * a);
		int rounded = round(x1);
		if ((rounded * rounded * a + rounded * b + c) == 0) {
			rt = min(rt, rounded);
		}
		rounded = round(x2);
		if ((rounded * rounded * a + rounded * b + c) == 0) {
			rt = min(rt, rounded);
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

	cin >> t;
	while (t--)
	{
		cin >> n;
		FOR(i, 0, n - 1) {
			cin >> arr[i];
		}
		if (n == 3) {
			cout << bacba(arr[0], arr[1], arr[2], arr[3]) << endl;
		}
		else if(n==2) {
			cout << bachai(arr[0], arr[1], arr[2]) << endl;
		}
		else {
			cout << -arr[1] / arr[0] << endl;
		}
	}


#ifdef DEBUG
	auto end = chrono::steady_clock::now();
	chrono::duration<double> diff = end - start;
	cout << endl << "Time: " << diff.count() << " s\n";
	return 0;

#endif 

	return 0;
}