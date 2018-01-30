#include<bits/stdc++.h>

using namespace std;

#define all(v)				((v).rbegin()), ((v).rend())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))

typedef long long         ll;
const ll OO = 1e6;

#define pb					push_back
#define MP					make_pair
#define ff  first
#define ss second
#define X first.second
#define Y first.first
#define coin second
#define mod(a,b)  (a%b+b)%b

vector< pair< pair<int, int>, int> > a;
int mem[51][52];
int n;
double V, G;
class PlatformJumper {
	bool check(int p1, int p2)
	{
		if (a[p1].Y < a[p2].Y) return false;
		double t = abs(a[p1].X - a[p2].X) / V;
		double d = (G * t * t) / 2.0;
		return d <= (a[p1].Y - a[p2].Y);
	}
	int rec(int x, int p)
	{
		if (x == n)
			return 0;
		int &ret = mem[x][p];
		if (ret != -1)
			return ret;
		if (p == 51 || check(p, x))
			ret = rec(x + 1, x) + a[x].coin;
		ret = max(ret, rec(x + 1, p));
		return ret;
	}

public: int maxCoins(vector <string> platforms, int v, int g)
{
	clr(mem, -1);
	n = (int)platforms.size();
	V = v;
	G = g;
	a.resize(n);
	for (int i = 0; i < n; i++)
		sscanf(platforms[i].c_str(), "%d %d %d", &a[i].X, &a[i].Y, &a[i].coin);
	sort(all(a));
	return rec(0, 51);
}



};