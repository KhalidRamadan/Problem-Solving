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


class ConvexSequence {
public:
	long long getMinimum(vector <int> a)
	{
		int n = (int)a.size();
		long long ans = 0;
		bool ok = true;
		while (ok)
		{
			ok = false;
			for (int i = 1; i < n - 1; i++)
			{
				if (a[i - 1] + a[i + 1] < 2 * a[i])
				{
					ok = true;
					int x = (a[i - 1] + a[i + 1]) / 2;
					ans += (a[i] - x);
					a[i] = x;
				}
			}
		}
		return ans;
	}



};