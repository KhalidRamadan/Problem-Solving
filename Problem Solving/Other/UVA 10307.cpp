#include<bits/stdc++.h>
using namespace std;
// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1248



int grid[150][150];
int spath[150][150];
int vis[150][150];
string G[150];
int n;


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int Prim()
{
    vector<int> vis(n, 0), dist(n, 1e9);
    int cur = 0;
    dist[cur] = 0;
    int ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        int newNode = -1, miniV = 1e9;
        vis[cur] = 1;
        for(int j = 0; j < n; j++)
            if(vis[j] == 0)
            {
                if(spath[cur][j] < dist[j])
                    dist[j] = spath[cur][j];
                if(dist[j] < miniV)
                {
                    miniV = dist[j];
                    newNode = j;
                }
            }
        ans += miniV;
        cur = newNode;
    }
    return ans;
}


void BFS(int x, int y)
{
    memset(vis, 0, sizeof(vis));
    int cur = grid[x][y];
    
    queue<pair<pair<int, int> , int> > q;
    q.push({{x, y}, 0});
    vis[x][y] = 1;
    while(q.empty() == 0)
    {
        pair<pair<int, int> , int> s = q.front();
        q.pop();
        int scur = grid[s.first.first][s.first.second];
        if(scur != 200)
            spath[scur][cur] = spath[cur][scur] = s.second;
        
        for(int i = 0; i < 4; i++)
        {
            int ff = grid[s.first.first + dx[i]][s.first.second + dy[i]];
            int f = vis[s.first.first + dx[i]][s.first.second + dy[i]];
            if(ff != 300 && f == 0)
            {
                vis[s.first.first + dx[i]][ s.first.second + dy[i]] = 1;
                q.push({{s.first.first + dx[i], s.first.second + dy[i]}, s.second + 1});
            }
            
        }
    }
}


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        n = 0;
        memset(grid, 0, sizeof(grid));
        memset(vis, 0, sizeof(vis));
        memset(spath, 0, sizeof(spath));

        int x, y;
        cin >> y >> x;
        cin.ignore();
        for(int i = 0; i < x; i++)
            getline(cin, G[i]);
        
        
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
            {
                if(G[i][j] == 'A' || G[i][j] == 'S')
                {
                    grid[i][j] = n;
                    n++;
                }
                else if(G[i][j] == ' ')
                {
                    grid[i][j] = 200;
                }
                else grid[i][j] = 300;
            }
        
        
        
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
            {
                if(grid[i][j] != 200 && grid[i][j] != 300)
                {
                    BFS(i, j);
                }
            }
        
        cout << Prim() << endl;
    }
    
}
/*
2
6 5
######
#A#A##
# # A#
#S  ##
######
7 7
#######
#AAA###
#    A#
# S ###
#     #
#AAA###
#######
 
 */
