/*
	Author: Abdulla Ashraf
	Idea:
        -the number of squares is symmetric in the 4 quarters so we work on one.
        -try every square bottom-left and top-right points to know if it starts and ends before or after the circle.
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

int dis(int x, int y){
    return x*x+y*y;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,t=0;
    while(cin >> n)
    {
        if(t++)
            cout << "\n";
        int c=0,d=0;
        double r = n-0.5;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(dis(i+1,j+1) <= r*r)
                    c++;
                else if(dis(i,j) <= r*r)
                    d++;
            }
        c*=4;
        d*=4;
        printf("In the case n = %d, %d cells contain segments of the circle.\nThere are %d cells completely contained in the circle.\n",n , d , c);
    }
    return 0;
}
