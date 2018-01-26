/*
	Author: Abdulla Ashraf
	Idea:
        -
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
ll tree[2 * N];
ll lazy[2 * N];
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
    tree[cur] = tree[left] + tree[right];
}

void propagte(int cur, int l, int r, int left, int right)
{
    if (lazy[cur] != 0)
    {
        tree[cur] += lazy[cur] * (r-l+1);
        if (l != r)
        {
            lazy[left] += lazy[cur];
            lazy[right] += lazy[cur];
        }
        lazy[cur] = 0;
    }
}

void updateRange(int cur, int l, int r, int x, int y, ll val)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    propagte(cur, l, r, left, right);

    if (l > y || x > r)
        return;

    if (l >= x && r <= y)
    {
        lazy[cur] += val;
        propagte(cur, l, r, left, right);
        return;
    }

    updateRange(left, l, mid, x, y, val);
    updateRange(right, mid + 1, r, x, y, val);
    tree[cur] = tree[left] + tree[right];
}

ll getAnswer(int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    propagte(cur, l, r, left, right);

    if (y < l || x > r)
        return 0;
    if (l >= x && r <= y)
        return tree[cur];

    ll res1 = getAnswer(left, l, mid, x, y);
    ll res2 = getAnswer(right, mid + 1, r, x, y);
    return res1+ res2;
}

int main()
{
    int T,a,b,c,n,m,q;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        build(1,1,N);
        while(m--)
        {
            cin >> q >> a >> b;
            if(!q)
            {
                cin >> c;
                updateRange(1,1,N,a,b,c);
            }
            else
                cout << getAnswer(1,1,N,a,b) << "\n";

        }
    }
    return 0;
}
