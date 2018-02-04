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


class RandomSwaps {
public: 
	double getProbability(int n, int c, int a, int b)
	{
		long double m = ((n - 1) * n) / 2;
		double ans = (a == b);
		cout << ans << endl;
		while (c--)
			ans = ((1 - ans) * (1.0 / m)) + (ans * ((m - n + 1.0) / m));
		return ans;
	}



};