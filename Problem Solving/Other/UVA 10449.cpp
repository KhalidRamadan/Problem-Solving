#include<bits/stdc++.h>
using namespace std;


int n;
vector<int> Bellman(vector<pair<pair<int, int>, int>> e, int start)
{
    if(n == 0) return vector<int>();
    int _n = n; // nodes;
    vector<int> dist(_n, 1e9);
    dist[start] = 0;
    for(int i = 0, r = 0; i < _n - 1; i++)
    {
        for(int j = 0; j < e.size(); j++)
        {
            if(dist[e[j].first.second] > dist[e[j].first.first] + e[j].second)
            {
                r = 1;
                dist[e[j].first.second] = dist[e[j].first.first] + e[j].second;
            }
        }
        if(r == 0) break;
    }
    
    for(int j = 0; j < e.size(); j++)
    {
        if(dist[e[j].first.second] > dist[e[j].first.first] + e[j].second)
        {
            dist[e[j].first.second] = -1e9;
        }
    }
    
    return dist;
}


int main()
{
    int st = 0;
    while(cin >> n)
    {
        st++;
        vector<pair<pair<int, int>, int>> e;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int mm;
        cin >> mm;
        for(int i = 0; i < mm; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            e.push_back({{x, y}, (a[y] - a[x]) * (a[y] - a[x]) * (a[y] - a[x])});
         //   e.push_back({{y, x}, (a[x] - a[y]) * (a[x] - a[y]) * (a[x] - a[y])});
        }
        
        vector<int> ans = Bellman(e, 0);
        
        int m;
        cin >> m;
        cout << "Set #" << st << endl;
        for(int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            x--;
            if(ans[x] < 3 || ans[x] >= 1e8)
                cout << "?";
            else cout << ans[x];
            cout << endl;
        }
        
    }
        
}


