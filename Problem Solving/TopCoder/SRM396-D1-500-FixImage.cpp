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

bool vis[51][51];
vector<string> aa;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
void ff(int x, int y)
{
	vis[x][y] = 1;
	int n = (int)aa.size();
	int m = (int)aa[0].size();
	for (int i = 0; i < 4; i++)
		if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m)
			if (aa[x + dx[i]][y + dy[i]] == '#' && vis[x + dx[i]][y + dy[i]] == 0)
				ff(x + dx[i], y + dy[i]);
}

class FixImage {
public: vector <string> originalImage(vector <string> ans)
{
	int n = (int)ans.size();
	int m = (int)ans[0].size();
	bool ok = true;
	while (ok)
	{
		ok = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (ans[i][j] == '#')
				{
					clr(vis, 0);
					aa = ans;
					ff(i, j);
					for (int i1 = 0; i1 < n; i1++)
					{
						int s = 0, e = 0;
						for (int j1 = 0; j1 < m; j1++)
							if (vis[i1][j1] == 1) { s = j1; break; }
						for (int j1 = m - 1; j1 >= 0; j1--)
							if (vis[i1][j1] == 1) { e = j1; break; }
						for (int j1 = s + 1; j1 < e; j1++)
						{
							if (ans[i1][j1] == '.') ok = true;
							ans[i1][j1] = '#';
						}
					}
					for (int j1 = 0; j1 < m; j1++)
					{
						int s = 0, e = 0;
						for (int i1 = 0; i1 < n; i1++)
							if (vis[i1][j1] == 1) { s = i1; break; }
						for (int i1 = n - 1; i1 >= 0; i1--)
							if (vis[i1][j1] == 1) { e = i1; break; }
						for (int i1 = s + 1; i1 < e; i1++)
						{
							if (ans[i1][j1] == '.') ok = true;
							ans[i1][j1] = '#';

						}
					}
				}
			}
	}
	return ans;
}



};