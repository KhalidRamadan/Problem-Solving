#include<bits/stdc++.h>
using namespace std;

#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))

typedef long long         ll;
const long double Pi = 3.14159265358979323;
#define pb					push_back
#define MP					make_pair
#define ff  first
#define ss second
#define mod(a,b)  (a%b+b)%b

int x, y, B, n;
vector<int> a;
double mem[51][365];
double rec(int v, int angle)
{
	if (v == (int)a.size())
	{
		double X = x - (B * cos(angle * Pi / 180));
		double Y = B * sin(angle * Pi / 180);
		return sqrt((X * X) + (Y * Y));
	}
	double &ret = mem[v][angle];
	if (ret != -1.0)
		return ret;
	ret = rec(v + 1, angle);
	ret = max(ret, rec(v + 1, (angle + a[v]) % 360));
	return ret;
}



class TurtleSpy {
public: double maxDistance(vector <string> commands)
{
	fill_n(&mem[0][0], 51 * 365, double(-1.0));
	n = (int)commands.size();
	for (int i = 0; i < n; i++)
	{
		string s;
		int c;
		stringstream str(commands[i]);
		str >> s >> c;
		cout << s << "     " << c << endl;
		if (s == "forward")
			x += c;
		else if (s == "backward")
			B += c;
		else
		{
			if (s == "left")
				c = 360 - c;
			a.pb(c);
		}

	}
	return rec(0, 0);
}



};