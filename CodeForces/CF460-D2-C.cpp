/*
	Author: Abdulla Ashraf
	Idea:
        -use binary search on all possible heights of min flower
        -now the problem is can we using m , w range increaments make all the flower equal to or longer than h ?
        -to answer this use something like dynamic partial sum, adding in a variable (ad) and decrease on the postion after the next w flowers
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

ll a[100005],b[100005],n,m,w,aa = 1, bb= 2*1e9;

bool f(int h)
{
    memset(b,0,sizeof b);
    ll ad = 0,c=0;
    for(int i=0; i<n; i++)
    {
        ad -= b[i];
        if(a[i] + ad < h)
        {
            c += h - a[i] - ad;
            if(i+w <100002)
                b[i + w] = h - a[i] - ad;
            ad = h-a[i];
        }
    }
    return c <= m;
}

int main()
{
    cin >> n >> m >> w;
    for(int i=0; i<n; i++)
        cin >> a[i];
    while (bb - aa > 1)
    {
        int m = (aa + bb) / 2;
        if (f(m))
            aa = m;
        else
            bb = m;
    }
    cout << aa << endl;
    return 0;
}
