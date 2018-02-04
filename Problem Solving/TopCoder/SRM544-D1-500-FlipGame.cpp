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


class FlipGame
{
public:
	int minOperations(vector <string> board)
	{
		int n = (int)board.size();
		int m = (int)board[0].size();
		int ok = 1;
		int ans = 0;
		while (ok)
		{
			ok = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = ok; j < m; j++)
					if (board[i][j] == '1')
						ok = j + 1;
				for (int j = 0; j < ok; j++)
				{
					if (board[i][j] == '1')
						board[i][j] = '0';
					else board[i][j] = '1';
				}
			}
			if (ok) ans++;
		}
		return ans;
	}
};