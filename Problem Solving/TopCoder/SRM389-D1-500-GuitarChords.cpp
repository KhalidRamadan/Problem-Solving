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


int n, m;
int diff[6][6];
string notes[] = { "", "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
int vis[6];

int clc(vector<int> arr, int count)
{
	if (count == 0) return 0;
	int ret = OO;
	for (int i = 0; i < count; i++)
	{
		int ans = 0;
		for (int j = 0; j < count; j++)
		{
			if (arr[i] > arr[j]) ans = max(ans, arr[j] - arr[i] + 12);
			else ans = max(ans, arr[j] - arr[i]);
		}
		ret = min(ret, ans + 1);
	}
	return ret;
}



int rec(int x, vector<int> fill, int count)
{
	if (x == n)
	{
		for (int i = 0; i < m; i++)
			if (!vis[i]) return OO;
		int ans = clc(fill, count);
		return ans;
	}
	int ret = OO;
	for (int i = 0; i < m; i++)
	{

		vis[i] += 1;
		if (diff[x][i] == 0)
			ret = min(ret, rec(x + 1, fill, count));
		else
		{
			fill[count] = diff[x][i];
			ret = min(ret, rec(x + 1, fill, count + 1));
		}
		vis[i] -= 1;
	}
	return ret;
}
class GuitarChords {
public:
	int stretch(vector <string> strings, vector <string> chord)
	{
		n = (int)strings.size();
		m = (int)chord.size();
		map<string, int> mp;
		for (int i = 1; i <= 12; i++)
			mp[notes[i]] = i;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				diff[i][j] = mod(mp[chord[j]] - mp[strings[i]], 12);
		vector<int> fill(6);
		return rec(0, fill, 0);
	}



};