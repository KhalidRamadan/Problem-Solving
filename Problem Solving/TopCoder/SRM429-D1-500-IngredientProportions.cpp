#include<bits/stdc++.h>

using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))

typedef long long         ll;
const ll OO = 1e6;

#define pb					push_back
#define MP					make_pair
#define ff  first
#define ss second
#define mod(a,b)  (a%b+b)%b


ll gcdz(ll a, ll b)
{
	ll c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

class IngredientProportions {
public: vector <int> getMasses(vector <string> proportions)
{
	int n = (int)proportions.size();
	vector<int> ans(n + 1, 1);
	vector<ll> aans(n + 1, 1);
	vector< pair< pair<int, int>, pair<ll, ll> > > qwerty(n);
	for (int i = 0; i < n; i++)
	{
		int a, b, p, q;
		sscanf(proportions[i].c_str(), "#%d and #%d as %d:%d", &a, &b, &p, &q);
		int gcd = __gcd(p, q);
		qwerty[i].ff.ff = a;
		qwerty[i].ff.ss = b;
		qwerty[i].ss.ff = p / gcd;
		qwerty[i].ss.ss = q / gcd;
	}
	bool ok = 1;
	while (ok)
	{
		ok = 0;
		for (int i = 0; i < n; i++)
		{
			int q1 = qwerty[i].ff.ff;
			int q2 = qwerty[i].ff.ss;
			ll an1 = aans[q1] * qwerty[i].ss.ss;
			ll an2 = aans[q2] * qwerty[i].ss.ff;
			if (an1 == an2) continue;
			ll gcd = gcdz(an1, an2);
			an1 = an1 / gcd;
			an2 = an2 / gcd;
			ok = 1;
			aans[q1] *= an2;
			aans[q2] *= an1;
		}
	}
	ll gcd = aans[0];
	for (int i = 1; i < n + 1; i++)
		gcd = gcdz(gcd, aans[i]);
	for (int i = 0; i < n + 1; i++)
	{
		ll xx = (aans[i]);
		ans[i] = (int)xx;
	}
	return ans;
}



};