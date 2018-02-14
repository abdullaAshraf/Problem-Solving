/*
	Author: Abdulla Ashraf
	Idea:
        -each edge on the road can be used any odd number of times and the total cost is <=100000 so we can use dp [50][100000]
	-use floyd to get the path from each node to every node
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
const int OO = 1000000000;

int x[51][51],mem[51][100005],p[51][51],s;


int go(int in, int r)
{
    if(r == 0)
        return 0;
    if(p[s][in] == s || r < 0)
        return OO;

    int &ret = mem[in][r];
    if(ret != -1)
        return ret;
    return ret = min(go(p[s][in],r),2+go(in,r-2*x[in][p[s][in]]));
}

int main()
{
    //freopen("in.txt","r",stdin);
    int T,n,m,a,b,c,h;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                x[i][j] = OO;
                p[i][j] = i;
            }
            x[i][i] = 0;
        }
        while(m--)
        {
            scanf("%d %d %d",&a,&b,&c);
            x[a][b] = x[b][a] = c;
        }
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    if( x[i][j] > x[i][k]+x[k][j])
                    {
                        x[i][j] = x[i][k]+x[k][j];
                        p[i][j] = p[k][j];
                    }
        scanf("%d",&h);
        while(h--)
        {
            memset(mem,-1,sizeof mem);
            scanf("%d %d %d",&a,&b,&c);
            s = b;
            int j = a,y=0;
            while (s != j)
            {
                y++;
                j = p[s][j];
                for(int i=0; i<=c; i++)
                    mem[j][i] = -1;
            }

            for(int i=0; i<=c; i++)
                mem[s][i] = -1;
            int v = y+go(a,c-x[a][b]);
            if(v < OO)
                printf("Yes %d\n",v);
            else
                printf("No\n");
        }
        if(T)
            printf("\n");
    }
    return 0;
}
