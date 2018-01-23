/*
	Author: Abdulla Ashraf
	Idea:
        -sort as required :)
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

double fixAngle(double A)
{
    return A>1 ? 1 : (A<-1 ? -1 : A);
}

double angleO(point a, point O, point b)
{
    point v1(a - O), v2(b - O);
    double ret = acos( fixAngle ( dp(v1, v2) / length(v1) / length(v2) ) );
    if(b.Y < 0)
        return 2*PI - ret;
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,x,y;
    cin >> n;
    vector<point> p;
    for(int i=0; i<n; i++)
    {
        cin >> x >> y;
        p.push_back(point(x,y));
    }
    sort(p.begin(),p.end(),[](point a, point b)
    {
        if(fabs(angleO(point(1,0), point(0,0), a) - angleO(point(1,0), point(0,0), b)) < EPS)
            return a.X*a.X + a.Y*a.Y < b.X*b.X + b.Y*b.Y;
        return angleO(point(1,0), point(0,0), a) < angleO(point(1,0), point(0,0), b);
    });
    for(auto it : p)
        cout << it.X << " " << it.Y << "\n";

    return 0;
}
