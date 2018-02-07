/*
	Author: Abdulla Ashraf
	Idea:
        -try every possible turn probabilty with memoization so it won't tle
        -in every turn a player may pick a mice using simple probablity rules if it is avaliable
        -stop when ther is no more white mice since it will difintly end for dragon
*/


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-9;

const int N = (1 << 15);
const int OO = 200000;

double mem[1005][1005];

double go(int a,int b,int t)
{
    if(!a)
        return 0;
    double &ret = mem[a][b];
    if(ret+EPS >= 0)
        return ret;
    ret = 0;
    if(t == 0)
    {
        if(a)
            ret += (1.0*a/(a+b));
        if(b)
            ret += (1.0*b/(a+b))*go(a,b-1,1-t);
    }
    else
    {
        if(b)
            ret += (1.0*b/(a+b))*(1.0*(a)/(a+b-1))*go(a-1,b-1,1-t);
        if(b > 1)
            ret += (1.0*b/(a+b))*(1.0*(b-1)/(a+b-1))*go(a,b-2,1-t);
    }
    return ret;
}

int main()
{
    int a,b;
    memset(mem,-1,sizeof mem);
    cin >> a >> b;
    cout << fixed << setprecision(9) << go(a,b,0);
    return 0;
}
