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


long long foct(int n, int p)
{

	long long ans = 0, a = p;
	while (n >= a)
	{
		ans += (n / a);
		a *= p;
	}
	return ans;
}

long long clc(int n, int m, int p)
{
	return foct(n + m, p) - foct(n, p) - foct(m, p);
}


class MagicalSpheres {
public: 
	int divideWork(int n, int m, int c)
	{
		for (int i = c; i >= 1; i--)
		{
			int k = i;
			bool ok = 1;
			for (int j = 2; j * j <= k; j++)
			{
				if (k % j == 0)
				{
					int tot = 0;
					while (k % j == 0)
					{
						tot++;
						k /= j;
					}
					if ((int)clc(n, m, j) < tot) ok = 0;
				}
			}
			if (k > 1)
				if ((int)clc(n, m, k) < 1) ok = 0;

			if (ok) return i;
		}
		return 1;
	}



};