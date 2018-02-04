#include<bits/stdc++.h>

using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))

typedef long long         ll;
const ll OO = 1e6;
const ll mod = 555555555;
#define pb					push_back
#define MP					make_pair
#define ff  first
#define ss second
#define mod(a,b)  (a%b+b)%b

int __gcd(int a, int b) {
	return b == 0 ? a : __gcd(b, a % b);
}


long long com(int n, int k)
{
	vector<int> a(n - (n - k)), b(k);
	for (int i = n, j = 0; i > n - k; i--, j++)
		a[j] = i;
	for (int i = k, j = 0; i >= 1; i--, j++)
		b[j] = i;

	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
		{
			int gcd = __gcd(a[i], b[j]);
			a[i] /= gcd;
			b[j] /= gcd;
		}
	long long ans = 1;
	for (int i = 0; i < a.size(); i++)
	{
		ans *= a[i];
		ans %= mod;
	}
	return ans;
}


int dp[3310][3310];

void DP()
{
	dp[0][0] = 1;
	for (int i = 1; i <= 3300; i++)
		for (int j = 0; j <= i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][j] %= mod;
		}
}



class XorBoard {
public: 
	int count(int H, int W, int Rcount, int Ccount, int S)
	{
		DP();
		long long ans = 0;
		long long ret = 0;
		for (int i = 0; i <= min(H, Rcount); i++)
			for (int j = 0; j <= min(W, Ccount); j++)
				if ((W * i) + (H * j) - (2 * i * j) == S && (Rcount - i) % 2 == 0 && (Ccount - j) % 2 == 0)
				{
					// cout << i << " " << j << endl;
					int R = (Rcount - i) / 2;
					int C = (Ccount - j) / 2;
					ret = 1;
					ret *= dp[H][i];
					ret %= mod;
					ret *= dp[W][j];
					ret %= mod;
					ret *= dp[H + R - 1][R];
					ret %= mod;
					ret *= dp[W + C - 1][C];
					ret %= mod;
					ans += (ret % mod);
					ans %= mod;
				}
		return int(ans);
	}



};

//438 1127 223 943 246813


/*
1860480
(w * i) + (H * j) - 2(i * j) = s
*   1 0 0

1   0 1 1
0   1 0 0
1   0 1 1







*/