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


long long C[55][55];
void _c()
{
	C[0][0] = 1;
	for (int i = 1; i < 55; i++)
		for (int j = 0; j < 55; j++)
		{
			if (j == 0) C[i][j] = 1;
			else   C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
}
map<int, int> mp, mp2;
vector<int> S;
bool vis[55];
set<int> pic;


int dfs(int s, int val)
{
	if (mp2[S[s - 1] + val]) pic.insert(mp2[S[s - 1] + val]);
	if (mp2[S[s - 1] - val]) pic.insert(mp2[S[s - 1] - val]);
	vis[s] = 0;
	if (vis[mp[S[s - 1] + (2 * val)]] && mp2[S[s - 1] + val])
		return dfs(mp[S[s - 1] + (2 * val)], val) + 1;
	return 1;
}

class OneDimensionalBalls
{
public: 
	long long countValidGuesses(vector <int> firstPicture, vector <int> secondPicture)
	{
		_c();
		S = secondPicture;
		sort(all(firstPicture));
		set<int> value;
		for (int i = 0; i < firstPicture.size(); i++)
			for (int j = 0; j < secondPicture.size(); j++)
			{
				int v = abs(firstPicture[i] - secondPicture[j]);
				value.insert(v);
			}
		for (int i = 1; i <= secondPicture.size(); i++)
			mp[secondPicture[i - 1]] = i;
		for (int i = 1; i <= firstPicture.size(); i++)
			mp2[firstPicture[i - 1]] = i;
		long long ans = 0;
		for (set<int>::iterator i = value.begin(); i != value.end(); i++)
		{
			if (*i == 0) continue;
			bool ok = 1;
			clr(vis, 0);
			for (int j = 0; j < firstPicture.size(); j++)
			{
				ok = 0;
				if (mp[firstPicture[j] + *i])
					vis[mp[firstPicture[j] + *i]] = 1, ok = 1;
				if (mp[firstPicture[j] - *i])
					vis[mp[firstPicture[j] - *i]] = 1, ok = 1;
				if (!ok) break;
			}
			long long ret = 0;
			if (ok)
			{
				ret = 1;
				for (int j = 1; j <= secondPicture.size(); j++)
				{
					if (vis[j] == 1)
					{
						pic.clear();
						int x = dfs(j, *i);
						ret *= C[x][pic.size()];
					}
				}
			}
			ans += ret;
		}
		return ans;
	}



};