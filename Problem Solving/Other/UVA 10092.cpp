#include<bits/stdc++.h>
using namespace std;

#define MAXN 1200     		//maximum number of nodes
int need[25], tot = 0;
int n, m;
int nodes = 1;
int cap[MAXN][MAXN];



int path[MAXN];
int pathLength;
bool visited[MAXN];

int getPath(int StartNode,int TargetNode,int curLen,int maxcap)
{
    path[curLen]=StartNode;
    if (StartNode==TargetNode)
    {
        pathLength=curLen+1;
        return maxcap;
    }
    
    int ret = 0;
    visited[StartNode]=true;
    
    for(int i=0;i< nodes;i++)
    {
        if (visited[i] || cap[StartNode][i]<=0) continue;
        
        ret = getPath(i, TargetNode,curLen+1, min(maxcap,cap[StartNode][i]));
        
        if (ret>0) break;
    }
    return ret;
}

int maxFlow(int src, int sink)
{
    int total_flow = 0;
    
    while(1)
    {
        memset(visited,0,sizeof(visited));
        int newflow=getPath(src,sink,0,INT_MAX);
        
        if (!newflow) break;
        
        for(int i=1;i<pathLength;i++)
        {
            int m=path[i-1],n=path[i];
            
            cap[m][n]-=newflow;
            cap[n][m]+=newflow;
        }
        total_flow+=newflow;
    }
    
    return total_flow;
}


void solve()
{
    vector< vector<int> > a(n + 1);
    for(int i = 1 + n; i < m + n + 1; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(cap[i][j] == 1)
            {
                a[j].push_back(i - n);
                break;
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < a[i].size(); j++)
        {
            if(j) cout << " ";
            cout << a[i][j];
        }
        cout << endl;
    }
            
}



int main()
{
    while(cin >> n >> m && (n != 0 && m != 0))
    {
        tot = 0;
        nodes = 1;
        memset(need, 0, sizeof(need));
        memset(cap, 0, sizeof(cap));
        nodes += n;
        for(int i = 1; i <= n; i++)
        {
            cin >> need[i];
            tot += need[i];
            cap[0][i] = need[i];
        }
        for(int i = nodes; i < m + nodes; i++)
        {
            int cc;
            cin >> cc;
            for(int j = 0; j < cc; j++)
            {
                int xx;
                cin >> xx;
                cap[xx][i] = 1;
            }
            cap[i][m + nodes] = 1;
        }
        nodes += (m + 1);
        int maxf = maxFlow(0, nodes - 1);
        if(maxf == tot)
        {
            cout << 1 << endl;
            solve();
        }
        else cout << 0 << endl;
    }
    
    
    
}


/*
 
 3 15
 3 3 4
 2 1 2
 1 3
 1 3
 1 3
 1 3
 3 1 2 3
 2 2 3
 2 1 3
 1 2
 1 2
 2 1 2
 2 1 3
 2 1 2
 1 1
 3 1 2 3
 
 3 15
 7 3 4
 2 1 2
 1 1
 1 2
 1 2
 1 3
 3 1 2 3
 2 2 3
 2 2 3
 1 2
 1 2
 2 2 3
 2 2 3
 2 1 2
 1 1
 3 1 2 3
 0 0
 
 */
