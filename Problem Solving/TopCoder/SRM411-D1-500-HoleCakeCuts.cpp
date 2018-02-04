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


class HoleCakeCuts 
{
public: 
	int cutTheCake(int cakeLength, int holeLength, vector <int> horizontalCuts, vector <int> verticalCuts)
	{
		int ans = 1, holes = 0, c = 0;
		for (int i = 0; i < (int)verticalCuts.size(); i++)
		{
			if (abs(verticalCuts[i]) <= holeLength)
			{
				if (holes) ans++;
				holes++;
			}
			ans++;
		}
		for (int i = 0; i < (int)horizontalCuts.size(); i++)
		{
			ans += (int)verticalCuts.size() + 1;
			cout << c << endl;
			if (abs(horizontalCuts[i]) <= holeLength)
			{
				if (!holes && c) ans++;
				else if (holes) ans -= (holes - 1);
				c++;
			}
		}
		return ans;
	}

};