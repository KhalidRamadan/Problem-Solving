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


double dp[5001][2];

class RedIsGood {
public: double getProfit(int R, int B)
{
	for (int i = 0; i <= R; i++)
		dp[i][0] = i;
	for (int j = 1; j <= B; j++)
		for (int i = 1; i <= R; i++)
			dp[i][j % 2] = max(double(0), ((i * (dp[i - 1][j % 2] + 1)) + (j * (dp[i][!(j % 2)] - 1))) / double(i + j));
	//fill_n(&mem[0][0], 5001 * 5001, double(-1.0));
	return dp[R][B % 2];
}



};