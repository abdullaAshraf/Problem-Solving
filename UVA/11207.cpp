/*
	Author: Abdulla Ashraf
	Idea:
        -to get 4 squares from a paper you can only use one of 2 ways to maximize everyone
        -get 4 squares in 1 line so the edge of the square will be the min between the shorter length and the longer /4
        -or get the 4 in 2 lines the answer will be the shorter / 2
        -getting them in 3 lines will always lead to a worse answer.
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
    int n,t=0;
    while(cin >> n && n)
    {
        double a,b,mx = 0,mxi = 1;
        for(int i=1; i<=n; i++)
        {
            cin >> a >> b;
            if(b > a)
                swap(a,b);
            double v = max(min(a/4,b),b/2);
            if(mx < v)
            {
                mx = v;
                mxi = i;
            }
        }
        cout << mxi << "\n";
    }
    return 0;
}
