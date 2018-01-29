/*
	Author: Abdulla Ashraf
	Idea:
        -split every number into 31 bit, now to the follwoing for every bit alone, the bit will be 0 in the final output only if it k or less steps near to a zero on the array
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

const int N = (1 << 17);
const int OO = 200000;

std::bitset<32> a[20005],p[20005];
int l[32],f[32];

int main()
{
    int T,n,k,t;
    cin >> T;
    while(T--)
    {
        memset(l,-1,sizeof l);
        memset(f,-1,sizeof f);
        scanf("%d %d",&n, &k);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&t);
            int v = 1;
            for(int j=0; j<31; j++)
            {
                p[i][j] = 1;
                a[i][j] = ((t&v) == 0 ? 0 : 1);
                v<<=1;
                if(a[i][j] == 0)
                {
                    l[j] = i;
                    if(f[j] == -1) f[j] = i;
                }
            }
        }
        for(int j=0; j<31; j++)
        {
            if(l[j] == -1)
                continue;
            int lst = l[j] - n;
            for(int i=0; i<n; i++)
            {
                if(a[i][j] == 0)
                    lst = i;
                if(i-lst <= k)
                    p[i][j] = 0;
            }
            int fst = f[j]+n;
            for(int i=n-1; i>=0; i--)
            {
                if(a[i][j] == 0)
                    fst = i;
                if(fst-i <= k)
                    p[i][j] = 0;
            }
        }
        for(int i=0; i<n; i++)
            printf("%d ",p[i].to_ulong());
        printf("\n");
    }
    return 0;
}
