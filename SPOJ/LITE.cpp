/*
	Author: Abdulla Ashraf
	Idea:
        -use a normal lazy propgation counting segment tree
        -but every update will switch every light case in that range, so if the range has x vaules and y of them are on after switching x-y will be on
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
int tree[2 * N];
int lazy[2 * N];
void build(int cur, int l, int r)
{
    lazy[cur] = 0;
    if (l == r)
    {
        tree[cur] = 0;
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
    if (lazy[cur] != 0)
    {
        tree[cur] = (r-l+1)- tree[cur];
        if (l != r)
        {
            lazy[left] = 1-lazy[left];
            lazy[right] = 1-lazy[right];
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
        lazy[cur] = 1-lazy[cur];
        propagte(cur, l, r, left, right);
        return;
    }

    updateRange(left, l, mid, x, y);
    updateRange(right, mid + 1, r, x, y);
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


int main()
{
    int T,n,m,t,a,b;
    scanf("%d %d",&n, &m);
    build(1,1,N);
    while(m--)
    {
        scanf("%d %d %d",&t, &a, &b);
        if(t)
            printf("%d\n",getAnswer(1,1,N,a,b));
        else
            updateRange(1,1,N,a,b);
    }

    return 0;
}
