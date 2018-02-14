/*
	Author: Abdulla Ashraf
	Idea:
        -sort friends using the number of monitors required
        -use dp solution with bitmasks to try every possible combinations of friends and minimize the cost
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
const ll OO = 2ll * 1e18;

struct fri
{
    int c, k, v;

    fri(int c, int k, int v): c(c), k(k), v(v) {}

    bool operator < (const fri & e) const
    {
        return k < e.k;
    }
};

ll x[2][1<<20];
vector<fri> f;
ll n,m,b,c,k,v,t,a;

int main()
{
    cin >> n >> m >> b;
    for(int i=0; i<n; i++)
    {
        cin >> c >> k >> t;
        v = 0;
        while(t--)
        {
            cin >> a;
            v |= 1<<(a-1);
        }
        f.push_back(fri(c,k,v));
    }
    sort(f.begin(),f.end());
    int mx = (1<<m)-1;

    //base case :
    for(int i=0; i<mx; i++)
        x[0][i] = OO;
    x[0][mx] = 0;
    ll ans = OO;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=mx; j++)
            x[1-(i&1)][j] = min(x[i&1][j],f[i].c+x[i&1][j|f[i].v]); //transections
        ans = min(ans, x[1-(i&1)][0] + f[i].k * b); //base case at each level
    }
    if(ans >= OO)
        cout << -1;
    else
        cout << ans;
    return 0;
}
