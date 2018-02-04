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

vector<string> client, server;
int vis[100];
int ret;
void dfs(int ser, int cli)
{
	vis[cli] = 1;
	for (int i = 0; i < client.size(); i++)
		if (client[i][cli] == 'Y' && !vis[i])
		{
			if (server[i][ser] == 'Y')
				server[i][ser] = 'N', ret--;
			dfs(ser, i);
		}
}

class NetworkSecurity
{
public: 
	int secureNetwork(vector<string> clientCable, vector<string> serverCable)
	{
		client = clientCable;
		server = serverCable;
		int ans = 0;
		for (int i = 0; i < serverCable[0].size(); i++)
		{
			ret = 0;
			for (int j = 0; j < serverCable.size(); j++)
				if (server[j][i] == 'Y')
					ret++;
			for (int j = 0; j < serverCable.size(); j++)
				if (server[j][i] == 'Y')
				{
					clr(vis, 0);
					dfs(i, j);
				}
			ans += ret;
		}

		return ans;
	}



};