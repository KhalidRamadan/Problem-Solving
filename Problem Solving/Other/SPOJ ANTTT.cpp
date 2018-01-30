#include<bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
typedef pair<point, point> line;
int ccw(point a, point b, point c) {
    point v1(b - a), v2(c - a);
    double t = cp(v1, v2);
    
    if (t > +EPS)
        return +1;
    if (t < -EPS)
        return -1;
    if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
        return -1;
    if (norm(v1) < norm(v2) - EPS)
        return +1;
    return 0;
}

bool intersect(point p1, point p2, point p3, point p4)
{
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3==p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;
    
    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}


int e[1001][1001];

int vis[1001];
int id = 1;
int n;
void dfs(int indx)
{
    vis[indx] = id;
    
    for(int i = 0; i < n; i++)
    {
        if(e[indx][i] == 1 && vis[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(vis, 0, sizeof(vis));
        memset(e, 0, sizeof(e));
        int m;
        cin >> n >> m;
        vector<line> a;
        for(int i = 0; i < n; i++)
        {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            a.push_back({point(x1, y1), point(x2, y2)});
           // cout << x1 << " " << y1 << endl;
           // cout << a[i].first.real() << " " << a[i].first.imag() << endl;
           // cout << a[i].first << endl;
        }
        
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
            {
                if(intersect(a[i].first, a[i].second, a[j].first, a[j].second) == 1)
                    e[i][j] = e[j][i] = 1;
            }
        
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i);
                id++;
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            if(vis[x - 1] == vis[y - 1])
                cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
