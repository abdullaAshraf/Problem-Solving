/*
	Author: Abdulla Ashraf
	Idea:
        -to get the top 2 max element we will use and array of 4 elements as the segment tree node
        -add the top 2 max for each child (left & right) and sort it.
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
const ll OO = (ll) 1 * 1e18;
int tree[2 * N][4];
int arr[2 + N];
void build(int cur, int l, int r)
{
    if (l == r)
    {
        tree[cur][3] = arr[l];
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[cur][0] = tree[left][3];
    tree[cur][1] = tree[right][3];
    tree[cur][2] = tree[left][2];
    tree[cur][3] = tree[right][2];
    sort(tree[cur],tree[cur]+4);
}

void update(int cur, int l, int r, int ind, int val)
{
    if (ind < l || ind > r)
        return;
    if (l == r && ind == l)
    {
        tree[cur][3] = val;
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, ind, val);
    update(right, mid + 1, r, ind, val);
    tree[cur][0] = tree[left][3];
    tree[cur][1] = tree[right][3];
    tree[cur][2] = tree[left][2];
    tree[cur][3] = tree[right][2];
    sort(tree[cur],tree[cur]+4);
}

pair<int,int> getAnswer(int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    if (y < l || x > r)
        return mp(0,0);
    if (l >= x && r <= y)
        return mp(tree[cur][3],tree[cur][2]);

    pair<int,int> r1 = getAnswer(left, l, mid, x, y);
    pair<int,int> r2 = getAnswer(right, mid + 1, r, x, y);
    int v[4];
    v[0] = r1.first;
    v[1] = r2.first;
    v[2] = r1.second;
    v[3] = r2.second;
    sort(v,v+4);
    return mp(v[3],v[2]);
}

int main()
{
    int n,m,a,b;
    char c;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",arr+i);
    build(1,1,N);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%s %d %d",&c,&a,&b);
        if(c == 'U')
            update(1,1,N,a,b);
        else
        {
            pair<int,int> x = getAnswer(1,1,N,a,b);
            printf("%d\n",x.first+x.second);
        }
    }
    return 0;
}
