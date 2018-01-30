#include<bits/stdc++.h>
using namespace std;

typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )
#define cp(a,b)                 ( (conj(a)*(b)).imag() )

point polygonCenteriod(vector<point> points) {
    double x = 0, y = 0, a = 0, c;
    int n = (int)points.size();
    for(int i = 0; i < n; ++i)
    {
        int j = (i + 1) % n;
        c = cp(points[i], points[j]), a += c;
        x += (points[i].X + points[j].X) * c;
        y += (points[i].Y + points[j].Y) * c;
    }
    a /= 2, x /= 6 * a, y /= 6 * a;
    return point(x, y);
}


point center_;

bool CMP(point p0, point p1)
{
    point center = center_;
    return angle(p0 - center) >= angle(p1 - center);
}

vector<point> sortp(vector<point> points) {
    
    for(int i = 0; i < points.size(); i++)
        if( make_pair(points[i].Y, points[i].X) < make_pair(points[0].Y, points[0].X))
            swap(points[0], points[i]);
    center_ = points[0];
    sort( points.begin()+1, points.end(), CMP);
    return points;
}

int main()
{
    int n;
    while(cin >> n && n >= 3)
    {
        vector<point> a(n);
        for(int i = 0; i < n; i++)
        {
            double x, y;
            cin >> x >> y;
            a[i] = point(x, y);
        }
        a = sortp(a);
        point center = polygonCenteriod(a);
        cout << fixed << setprecision(3);
        if(center.real() == -0) center.real(0);
        if(center.imag() == -0) center.imag(0);
        cout << center.real() << " " << center.imag() << endl;
    }

}
