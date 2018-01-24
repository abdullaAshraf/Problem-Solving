/*
	Author: Abdulla Ashraf
	Idea:
        - something like trying to maximize the length of a consecutive subsequence whose sum is less than or equal to a value.
	- but instead of normal summation we need to sum the max of m vaules where segment tree come in handy.
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
ll arr[5][N + 2];
ll tree[5][2 * N];
void build(int v,int cur, int l, int r)
{
    if (l == r)
    {
        tree[v][cur] = arr[v][l];
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(v,left, l, mid);
    build(v,right, mid + 1, r);
    tree[v][cur] = max(tree[v][left],tree[v][right]);
}

ll getAnswer(int v,int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    if (y < l || x > r)
        return 0;
    if (l >= x && r <= y)
        return tree[v][cur];

    ll res1 = getAnswer(v,left, l, mid, x, y);
    ll res2 = getAnswer(v,right, mid + 1, r, x, y);
    return max(res1,res2);
}

int n,m,k;

bool can (int l, int r)
{
    if(r < l)return true;
    ll s = 0;
    for(int i=0; i<m; i++)
        s+=getAnswer(i,1,1,N,l,r);
    return s<= k;
}

void print (int l,int r)
{
    for(int i=0; i<m; i++)
        cout << getAnswer(i,1,1,N,l,r) << " ";
}

int main()
{
    memset(arr,0,sizeof arr);
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[j][i];
    for(int i=0; i<m; i++)
        build(i,1,1,N);
    int l=1,r=1,mx= 0,mxr=0,mxl=0;
    while(r <= n)
    {
        if(can(l,r))
        {
            if(mx < r-l+1)
            {
                mx = r-l+1;
                mxr = r;
                mxl = l;
            }
            r++;
        }
        else
            l++;
    }
    print(mxl,mxr);
    return 0;
}
