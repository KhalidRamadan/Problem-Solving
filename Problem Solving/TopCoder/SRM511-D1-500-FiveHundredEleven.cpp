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

int memo[55][550];
vector<int> a;
int n;
bool rec(int play, int m)
{
	if (m == 511) return 1;
	if (play == n) return 0;
	int &ret = memo[play][m];
	if (ret != -1) return ret;
	ret = 0;
	int c = 0;
	for (int i = 0; i < n; i++)
		if ((m | a[i]) != m)
		{
			c++;
			if (!rec(play + 1, m | a[i]))
				ret = 1;
		}
	if ((n - c) > play && !rec(play + 1, m))
		ret = 1;
	return ret;
}

class FiveHundredEleven 
{
public: 
	string theWinner(vector<int> cards)
	{
		a = cards;
		clr(memo, -1);
		n = (int)cards.size();
		//  cout << rec(0, 0) << endl;
		if (rec(0, 0))
			return "Fox Ciel";
		return "Toastman";
	}



};