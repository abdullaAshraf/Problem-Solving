/*
	Author: Abdulla Ashraf
	Idea:
        -number divisble by 3 is numbers whose mod by 3 is 0, so we count for every mod to 3
        -the update will be shifiting values of those counters
        -the answer is the counter of the mod 0
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
int tree[2 * N][3];
int lazy[2 * N];
void build(int cur, int l, int r)
{
    lazy[cur] = 0;
    if (l == r)
    {
        tree[cur][0] = 1;
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[cur][0] = tree[left][0]+ tree[right][0];
}

void propagte(int cur, int l, int r, int left, int right)
{
    lazy[cur] %= 3;
    if (lazy[cur] != 0)
    {
        if(lazy[cur] == 1)
        {
            int t = tree[cur][0];
            tree[cur][0] = tree[cur][2];
            tree[cur][2] = tree[cur][1];
            tree[cur][1] = t;
        }
        else
        {
            int t = tree[cur][0];
            tree[cur][0] = tree[cur][1];
            tree[cur][1] = tree[cur][2];
            tree[cur][2] = t;
        }
        if (l != r)
        {
            lazy[left] += lazy[cur];
            lazy[right] += lazy[cur];
        }
        lazy[cur] = 0;
    }
}

void updateRange(int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    propagte(cur, l, r, left, right);

    if (l > y || x > r)
        return;

    if (l >= x && r <= y)
    {
        lazy[cur]++;
        propagte(cur, l, r, left, right);
        return;
    }

    updateRange(left, l, mid, x, y);
    updateRange(right, mid + 1, r, x, y);
    tree[cur][0] = tree[left][0]+ tree[right][0];
    tree[cur][1] = tree[left][1]+ tree[right][1];
    tree[cur][2] = tree[left][2]+ tree[right][2];
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
        return tree[cur][0];

    int res1 = getAnswer(left, l, mid, x, y);
    int res2 = getAnswer(right, mid + 1, r, x, y);
    return res1+ res2;
}


int main()
{
    int T,n,m,t,a,b;
    scanf("%d %d",&n, &m);
    build(1,1,N);
    while(m--)
    {
        scanf("%d %d %d",&t, &a, &b);
        if(t)
            printf("%d\n",getAnswer(1,1,N,a+1,b+1));
        else
            updateRange(1,1,N,a+1,b+1);
    }

    return 0;
}
