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

ll mem[30][30];
ll DP(int n, int m)
{
	ll nums = 1;
	for (int i = 1; i <= n; i++)
		nums *= i;
	if (m >= n) return nums;
	if (m == 1) return nums / n;
	ll &ret = mem[n][m];
	if (ret != -1) return ret;

	ret = nums / n;
	nums /= n;
	ll v = 1;
	for (int i = 1; i < n; i++)
	{
		v *= i;
		ret += ((nums / v) *  DP(i, m - 1));
	}
	return ret;
}

int __gcd(int a, int b) {
	return b == 0 ? a : __gcd(b, a % b);
}


class KeysInBoxes
{
public: 
	string getAllKeys(int N, int M)
	{
		clr(mem, -1);
		ll b = 1;
		for (int i = 1; i <= N; i++)
			b *= i;
		ll a = DP(N, M);
		ll g = __gcd(a, b);
		a /= g;
		b /= g;
		string s;
		stringstream str;
		str << a << "/" << b;
		s = str.str();
		return s;
	}



};