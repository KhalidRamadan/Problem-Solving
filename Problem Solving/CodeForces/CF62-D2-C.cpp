#include<bits/stdc++.h>
using namespace std;

const double EPS = 1e-2;

typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define normalize(a)            (a)/length(a)

bool intersectSegments(point a, point b, point c, point d, point & intersect) {
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return false;
    
    double t1 = d2 / d1, t2 = d3 / d1;
    intersect = a + (b - a) * t1;
    
    if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
        return false;
    return true;
}

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
bool intersect(point p1, point p2, point p3, point p4) {
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3==p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;
    
    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

double TriArea(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}


double len(point a, point b)
{
    return sqrt((a.real() - b.real()) * (a.real() - b.real()) +
                (a.imag() - b.imag()) * (a.imag() - b.imag()));
    
}


double TriA(point a, point b, point c)
{
    double A = len(a, b);
    double B = len(b, c);
    double C = len(c, a);
    return TriArea(A, B, C);
}

bool pointInTri(point m, point a, point b, point c)
{
    double A1 = TriA(a, b, m);
    double A2 = TriA(b, c, m);
    double A3 = TriA(c, a, m);
    double tot = TriA(a, b, c);
    if(fabs(A1 + A2 + A3 - tot) < EPS && A1 > EPS && A2 > EPS && A3 > EPS)
        return true;
    return false;
}

bool check(point a, point b, point c, point d)
{
    if(a == c || a == d || b == c || b == d)
        return false;
    return true;
}
point a_;
bool cmpP(point a, point b)
{
    double A = len(a_, a);
    double B = len(a_, b);
    return A < B;
}


long double Seg(vector<vector<point>> & A, point a, point b)
{
    a_ = a;
    vector<point> points;
    points.push_back(a);
    points.push_back(b);
    for(int i = 0; i < A.size(); i++)
        for(int j = 0; j < 3; j++)
        {
            point c = A[i][j];
            point d = A[i][(j + 1) % 3];
            point inter;
            if(check(a, b, c, d) == 0 || intersect(a, b, c, d) == 0) continue;
            intersectSegments(a, b, c, d, inter);
            points.push_back(inter);
        }
    sort(points.begin() + 1, points.end(), cmpP);
    
    long double ans = 0;
    for(int i = 0; i < points.size() - 1; i++)
    {
        bool ok = 1;
        point m = .5 * (points[i] + points[i + 1]);
        for(int j = 0; j < A.size(); j++)
        {
            bool isIn = pointInTri(m, A[j][0], A[j][1], A[j][2]);
            if(isIn == 1)
            {
                ok = 0;
                break;
            }
        }
        if(ok)
            ans += len(points[i], points[i + 1]);
    }
    
    return ans;
    
}



int main()
{
    int n;
    cin >> n;
    long double ans = 0;
    vector<vector<point>> a(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            double x, y;
            cin >> x >> y;
            a[i].push_back(point(x, y));
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        ans += Seg(a, a[i][0], a[i][1]);
        ans += Seg(a, a[i][1], a[i][2]);
        ans += Seg(a, a[i][0], a[i][2]);
    }
    cout << fixed << setprecision(10);
    cout << ans << endl;
}
