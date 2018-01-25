/*
	Author: Abdulla Ashraf
	Idea:
        -segment tree every node holds 5 information (sum , max right , max left , max total , max element)
        -now to merge nodes do as following:
          -max element = max of the two childs max element
          -max right = max between max right for thr right one or sum of the right and max right of the left (this is the max we can get taking the most right element with us)
          -max left as max right but on the oter side
          -sum is the sum of both
          -max total is the desired vaule and we calculate it using max right and left from childs that's why we keep them
          -keep sum cause we need it in calculting max left & max right
          -keep max element to handle the cause where all elements are -ve as we still must pick at least one element
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

const int N = (1 << 16);
const ll OO = (ll) 1 * 1e18;

struct node
{
    ll s,l,r,m,mx;
};

ll arr[N + 2];
node tree[2 * N];
void build(int cur, int l, int r)
{
    if (l == r)
    {
        tree[cur].s = tree[cur].mx = arr[l];
        tree[cur].r = max(0ll,arr[l]);
        tree[cur].l = max(0ll,arr[l]);
        tree[cur].m = max(0ll,arr[l]);
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[cur].s = tree[right].s + tree[left].s;
    tree[cur].l = max(tree[left].l,tree[left].s + tree[right].l);
    tree[cur].r = max(tree[right].r,tree[right].s + tree[left].r);
    tree[cur].m = max(tree[right].l + tree[left].r,max(tree[left].m,tree[right].m));
    tree[cur].mx = max(tree[left].mx, tree[right].mx);
}

node getAnswer(int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    if (y < l || x > r)
    {
        node v;
        v.l = v.r = v.m = v.s = 0;
        v.mx = -OO;
        return v;
    }
    if (l >= x && r <= y)
        return tree[cur];

    node r1 = getAnswer(left, l, mid, x, y);
    node r2 = getAnswer(right, mid + 1, r, x, y);
    node v;
    v.s = r2.s + r1.s;
    v.l = max(r1.l,r1.s + r2.l);
    v.r = max(r2.r,r2.s + r1.r);
    v.m = max(r2.l + r1.r,max(r1.m,r2.m));
    v.mx = max(r1.mx, r2.mx);
    return v;
}

int n,m,a,b;

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    for(int i=n+1; i<=N; i++)
        arr[i] = 0;
    build(1,1,N);
    cin >> m;
    while(m--)
    {
        scanf("%d %d",&a,&b);
        node x = getAnswer(1,1,N,a,b) ;
        if(x.mx < 0)
            printf("%d\n", x.mx);
        else
            printf("%d\n", x.m);
    }
    return 0;
}
