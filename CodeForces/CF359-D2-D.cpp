/*
	Author: Abdulla Ashraf
	Idea:
        -for a sequence to to meet the required rules the min(l,r) must equal to gcd(l,r)
        -use binary search to find the highest length of a sequence that meet the rules (from tutorial)
        -segment tree is not fast enough probably must use a "sparce table"
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

const int N = (1 << 19);
const ll OO = (ll) 1 * 1e18;
ll arr[N + 2];
ll tree[2 * N];
ll gc[2 * N];
void build(int cur, int l, int r)
{
    if (l == r)
    {
        tree[cur] = gc[cur] = arr[l];
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[cur] = min(tree[left],tree[right]);
    if(gc[right] == OO)
        gc[cur] = gc[left];
    else if (gc[left] == OO)
        gc[cur] = gc[right];
    else
        gc[cur] = __gcd(gc[left],gc[right]);
}

ll getAnswer(int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    if (y < l || x > r)
        return OO;
    if (l >= x && r <= y)
        return tree[cur];

    ll res1 = getAnswer(left, l, mid, x, y);
    ll res2 = getAnswer(right, mid + 1, r, x, y);
    return min(res1,res2);
}

ll getGc(int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    if (y < l || x > r)
        return OO;
    if (l >= x && r <= y)
        return gc[cur];

    ll res1 = getGc(left, l, mid, x, y);
    ll res2 = getGc(right, mid + 1, r, x, y);
    if(res2 == OO)
        return res1;
    else if(res1 == OO)
        return res2;
    else
        return __gcd(res1,res2);
}

int n;

bool ok (int mid)
{
    for(int l=1; l+mid<=n; l++)
        if (getAnswer(1,1,N,l,l+mid) == getGc(1,1,N,l,l+mid))
            return 1;
    return 0;
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
        scanf("%d", arr+i);
    for(int i=n+1; i<=N; i++)
        arr[i] = OO;
    build(1,1,N);
    int lf = 0, rg = n;
    vector<int> mxl;
    while (rg - lf > 1)
    {
        int mid = (lf + rg) / 2;
        if (ok(mid))
            lf = mid;
        else
            rg = mid;
    }
    for(int l=1; l+lf<=n; l++)
        if (getAnswer(1,1,N,l,l+lf) == getGc(1,1,N,l,l+lf))
            mxl.pb(l);
    cout << mxl.size() << " " << lf << "\n";
    for(auto it : mxl)
        printf("%d ",it);
    return 0;
}
