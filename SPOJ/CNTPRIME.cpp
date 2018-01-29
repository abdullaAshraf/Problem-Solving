/*
	Author: Abdulla Ashraf
	Idea:
        -use sieve to get all primes in the range 2 to 10^6
        -make a normal counting segment tree with lazy propagtion to count the primes
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

const int N = (1 << 14);
const int OO = 200000;
int arr[N+2];
int tree[2 * N];
int lazy[2 * N];
void build(int cur, int l, int r)
{
    lazy[cur] = -1;
    if (l == r)
    {
        tree[cur] = arr[l];
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[cur] = tree[left]+ tree[right];
}

void propagte(int cur, int l, int r, int left, int right)
{
    if (lazy[cur] != -1)
    {
        tree[cur] = (r-l+1)*lazy[cur];
        if (l != r)
        {
            lazy[left] = lazy[cur];
            lazy[right] = lazy[cur];
        }
        lazy[cur] = -1;
    }
}

void updateRange(int cur, int l, int r, int x, int y, int val)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    propagte(cur, l, r, left, right);

    if (l > y || x > r)
        return;

    if (l >= x && r <= y)
    {
        lazy[cur] = val;
        propagte(cur, l, r, left, right);
        return;
    }

    updateRange(left, l, mid, x, y, val);
    updateRange(right, mid + 1, r, x, y, val);
    tree[cur] = tree[left]+ tree[right];
}

int getAnswer(int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    propagte(cur, l, r, left, right);

    if (y < l || x > r)
        return 0;
    if (l >= x && r <= y)
        return tree[cur];

    int res1 = getAnswer(left, l, mid, x, y);
    int res2 = getAnswer(right, mid + 1, r, x, y);
    return res1+ res2;
}


int p[1000005];

int main()
{
    for(int i=2; i<=1e6; i++)
        p[i] = 1;
    for(int i=2; i*i<= 1e6; i++)
        if(p[i])
            for(int j=i*i; j<=1e6; j+=i)
                p[j] = 0;
    int T,n,m,t,a,b;
    cin >> T;
    for(int tt=1; tt<=T; tt++)
    {
        printf("Case %d:\n",tt);
        memset(arr,0,sizeof arr);
        scanf("%d %d",&n, &m);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&t);
            arr[i] = p[t];
        }
        build(1,1,N);
        while(m--)
        {
            scanf("%d %d %d",&t, &a, &b);
            if(t)
                printf("%d\n",getAnswer(1,1,N,a,b));
            else
            {
                scanf("%d",&t);
                updateRange(1,1,N,a,b,p[t]);
            }
        }
    }
    return 0;
}
