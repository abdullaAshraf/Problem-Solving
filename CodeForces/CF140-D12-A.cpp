/*
	Author: Abdulla Ashraf
	Idea:
        -used equation from http://www.ambrsoft.com/TrigoCalc/Circles2/CirclePoint/CirclePointDistance.htm
        -assumed the bigger circle center is (0,0) and one of the small is (R-r,0) which reduced the equations to an easier form
        -handled some special cases
        -calculate the theta angle to know how much of the circle a single small circle take
        -compare the number of circles with the percent for each
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,R,r;
    cin >> n >> R >> r;
    if(r > R)
        cout << "NO";
    else if(r*2 == R)
        if(n > 2)
            cout << "NO";
        else
            cout << "YES";
    else if(r*2 > R)
        if(n > 1)
            cout << "NO";
        else
            cout << "YES";
    else
    {
        double x = R-r;
        double x1 = r*r/x;
        double y1 = r*sqrt(x*x-r*r)/x;
        double t = 2*atan(r/sqrt((x-x1)*(x-x1) + y1*y1));
        if (360 / (t*180/PI)+EPS > n)
            cout << "YES";
        else
            cout << "NO";
    }
    return 0;
}
