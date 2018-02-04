#include<bits/stdc++.h>

using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))

typedef long long         ll;

#define pb					push_back
#define MP					make_pair
#define ff  first
#define ss second
#define mod(a,b)  (a%b+b)%b


string s;
int n;
string sw;
long long mem[22][22];

long long rec(int a, int b)
{
	if (a + b == n)
	{
		if (a != n / 2 || b != n / 2)
			return 0;
		return 1;
	}
	long long &ret = mem[a][b];
	if (ret != -1) return ret;
	ret = 0;
	if (s[a + b] == sw[a])
		ret += rec(a + 1, b);
	if (s[a + b] == sw[b])
		ret += rec(a, b + 1);
	return ret;
}


long long bt(int x, int to, int tx)
{
	if (x == n / 2)
	{
		if (to != 0 || tx != 0)
			return 0;
		clr(mem, -1);
		return rec(0, 0);
	}
	long long ans = 0;
	if (tx)
	{
		sw[x] = 'x';
		ans += bt(x + 1, to, tx - 1);
	}
	if (to)
	{
		sw[x] = 'o';
		ans += bt(x + 1, to - 1, tx);
	}
	return ans;
}

class SPartition 
{
public:
	long long getCount(string ss)
	{
		s = ss;
		n = (int)ss.size();
		int to = 0, tx = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'x')
				tx++;
		}
		to = n - tx;
		if (to % 2 || tx % 2)
			return 0;
		sw.resize(n / 2);
		return bt(0, to / 2, tx / 2);
	}



};