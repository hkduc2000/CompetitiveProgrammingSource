#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<ll> d;

int find(int l, int r, ll val)
{
	while (l < r)
	{
		int m = (l + r) / 2;
		if (d[m] > val)
			r = m - 1;
		else
			l = m + 1;
	}
	return (l + r) / 2;
}

int find2(int l, int r, ll val)
{
	while (l < r)
	{
		int m = (l + r) / 2;
		if (d[m] * d[m] > val)
			r = m - 1;
		else
			l = m + 1;
	}
	return (l + r) / 2;
}

void solve()
{
	sort(d.begin(), d.end());
	ll res1, res2, res3;
	res1 = res2 = res3 = 0;
	for (int i = 0; i < d.size() - 1; i++)
	{
		for (int j = i + 1; j < d.size(); j++)
		{
			ll a = d[i];
			ll b = d[j];
			int add = 0;
			double cc = sqrt(a * a + b * b);
			vector<ll>::iterator nhon = d.begin() + j;
			auto maxx = lower_bound(d.begin() + j + 1, d.end(), a + b);
			if (ll(cc) == cc)
			{
				auto sl = lower_bound(d.begin() + j + 1, maxx, cc);
				auto sr = upper_bound(d.begin() + j + 1, maxx, cc);
				res1 += distance(d.begin() + j + 1, sl);
				res2 += distance(sl, sr);
				res3 += distance(sr, maxx);
			}
			else
			{
				auto sl = upper_bound(d.begin() + j + 1, maxx, cc);
				res1 += distance(d.begin() + j + 1, sl);
				res3 += distance(sl, maxx);
			}
		}
	}
	cout << res1 << ' ' << res2 << ' ' << res3 << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		d.push_back(tmp);
	}
	solve();
}