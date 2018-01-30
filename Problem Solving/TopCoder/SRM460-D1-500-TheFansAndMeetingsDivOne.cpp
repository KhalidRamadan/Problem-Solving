#include<bits/stdc++.h>

using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))

#define pb					push_back
#define MP					make_pair
#define ff  first
#define ss second
#define mod(a,b)  (a%b+b)%b


vector<int> min1, max1;
int n;
double john[1605];
double brus[1605];
bool vis[1605][41][41];
double mem[1605][41][41];

double rec(int fan, int x, int k)
{
	if (x == n || k == 0)
	{
		if (fan || k) return 0;
		return 1;
	}
	double &ret = mem[fan][x][k];
	if (vis[fan][x][k] != 0)
		return ret;
	vis[fan][x][k] = 1;
	ret = 0;
	double fans = max1[x] - min1[x] + 1, p = k / double(n - x);
	for (int i = min1[x]; i <= max1[x]; i++)
	{
		if (fan >= i)
			ret += (p * (1.0 / fans) * rec(fan - i, x + 1, k - 1));
	}
	ret += ((1.0 - p) * rec(fan, x + 1, k));
	return ret;
}


void clc(vector<int> mi, vector<int> mx, int k, double *vec)
{
	min1 = mi;
	max1 = mx;
	clr(vis, 0);
	clr(mem, 0);
	for (int i = 1; i <= 1600; i++)
	{
		vec[i] = rec(i, 0, k);
	}

}


class TheFansAndMeetingsDivOne {
public: double find(vector <int> miJ, vector <int> mxJ, vector <int> miB, vector <int> mxB, int k)
{
	n = (int)miJ.size();
	clc(miJ, mxJ, k, john);
	clc(miB, mxB, k, brus);
	double ans = 0;
	for (int i = 1; i <= 1600; i++)
		ans += (john[i] * brus[i]);
	return ans;
}



};