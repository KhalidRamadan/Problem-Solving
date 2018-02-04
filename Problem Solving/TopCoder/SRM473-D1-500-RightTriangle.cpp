#include<bits/stdc++.h>

using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))

typedef long long         ll;
const ll OO = 1e8;

#define pb					push_back
#define MP					make_pair
#define ff  first
#define ss second
#define mod(a,b)  (a%b+b)%b

class RightTriangle 
{
public:
	long long triangleCount(int places, int points, ll a, ll b, ll c)
	{
		int mod = places;
		vector<bool> P(places, 0);
		vector<int> F(places, 0);
		long long ans = 0, count = 0;
		for (int i = 0; i < points; i++)
		{
			long long A = (((a * i) % mod) * i) % mod;
			long long B = (b * i) % mod;
			long long p = (((A + B) % mod) + c) % mod;
			F[p]++;
		}
		for (int i = 0; i < 2 * places; i++)
		{
			count += F[i % places];
			F[i % places] = 0;
			if (P[i % places] == 0 && count) P[i % places] = 1, count--;
		}
		for (int i = 0; i < (places / 2); i++)
			if (P[i] && P[i + (places / 2)])
				ans += points - 2;

		if (places % 2)
			return 0;
		return ans;
	}



};
