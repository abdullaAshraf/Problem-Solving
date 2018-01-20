/*
	Author: Abdulla Ashraf
	Idea:
        - try all solutions with dp.
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

int mem[11][1005];
int n,m,a[11],b[11],c[11],d[11],c0,d0;

int go(int in, int r)
{
    if(in == m)
        return d0*(r/c0);
    int &ret = mem[in][r];
    if(ret != 0)
        return ret;
    int cn = 0;
    ret = 0;
    while(cn * c[in] <= r && cn * b[in] <= a[in])
    {
        ret = max(ret,cn*d[in]+ go(in+1,r-cn * c[in]));
        cn++;
    }
    return ret;
}

int main()
{
    cin >> n >> m >> c0 >> d0;
    for(int i=0; i<m; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    cout << go(0,n);
    return 0;
}
