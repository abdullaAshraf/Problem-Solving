/*
	Author: Abdulla Ashraf
	Idea:
        -check if the segment intersect with any of the rectangle sides
        -check if any of the segment ends are inside the rectangle in case the whole segment was inside the rectangle
        -the code fails because the intersection method can not tell the difference between parllel and identical segments
        so some cases like 2 1 2 10 & 2 2 2 3 will give the answer of false.
*/


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const int N = 10005;
const double PI = acos(-1.0);
const double EPS = 1e-9;


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

bool isCollinear(point a, point b, point c) {
	return fabs( cp(b-a, c-a) ) < EPS;
}

bool intersectSegments(point a, point b, point c, point d)
{
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return false;  // Parllel || identical

    double t1 = d2 / d1, t2 = d3 / d1;
    //intersect = a + (b - a) * t1;

    if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS || t1 > 1 + EPS)
        return false;
    return true;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        double x1,y1,x2,y2,a,b,c,d;
        cin >> x1 >> y1 >> x2 >> y2 >> a >> b >> c >> d;
        if(intersectSegments(point(x1,y1),point(x2,y2),point(a,b),point(a,d)) ||
           intersectSegments(point(x1,y1),point(x2,y2),point(a,b),point(c,b)) ||
           intersectSegments(point(x1,y1),point(x2,y2),point(c,d),point(a,d)) ||
           intersectSegments(point(x1,y1),point(x2,y2),point(c,d),point(c,b)) ||
           (x1 > a && x1 < c && y1 < b && y1 > d) || (x2 > a && x2 < c && y2 < b && y2 > d))
            cout << "T\n";
        else
            cout << "F\n";
    }
    return 0;
}
