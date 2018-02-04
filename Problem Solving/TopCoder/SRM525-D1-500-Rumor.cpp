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


vector<string> graph0;
int ans = OO;
int n;
int c = 0;
void rec(vector< pair<bool, bool> > old, vector< pair<bool, bool> > nw, int indx, int day)
{
	c++;
	if (indx == n)
	{
		bool ok = 1;
		for (int i = 0; i < n; i++)
			if (nw[i].ff != 1 || nw[i].ss != 1)
				ok = 0;
		if (ok) ans = min(ans, day + 1);
		else if (day < 20) rec(nw, nw, 0, day + 1);
		return;
	}
	for (int i = indx; i <= n; i++)
	{
		if (i == n)
		{
			rec(old, nw, n, day);
			return;
		}
		if (old[i].ff == 1 && old[i].ss == 1)
		{
			bool ok1 = 0, ok2 = 0;
			vector< pair<bool, bool> > temp = nw;
			for (int j = 0; j < n; j++)
				if (graph0[i][j] == 'Y' && temp[j].ff != 1)
					ok1 = 1, temp[j].ff = 1;
			for (int j = 0; j < n; j++)
				if (graph0[i][j] == 'Y' && nw[j].ss != 1)
					ok2 = 1, nw[j].ss = 1;
			if (ok1) rec(old, temp, i + 1, day);
			if (ok2) rec(old, nw, i + 1, day);
			if (ok1 || ok2) return;
		}
		else
		{
			for (int j = 0; j < n; j++)
				if (graph0[i][j] == 'Y')
					nw[j].ff |= old[i].ff, nw[j].ss |= old[i].ss;
		}

	}
}


class Rumor {
public:
	int getMinimum(string knowledge, vector<string> graph)
	{
		int k = 0;
		graph0 = graph;
		n = (int)knowledge.size();
		vector< pair<bool, bool> > tmp(n, MP(0, 0));
		for (int i = 0; i < n; i++)
			if (knowledge[i] == 'Y')
				tmp[i].ff = 1, tmp[i].ss = 1, k++;
		if (k == n) return 0;
		rec(tmp, tmp, 0, 0);
		if (ans == OO) return -1;
		return ans;
	}

};