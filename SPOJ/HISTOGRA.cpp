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
ll arr[N + 2];
ll tree[2 * N];
void build(int cur, int l, int r)
{
    if (l == r)
    {
        tree[cur] = l;
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    if(arr[tree[left]] < arr[tree[right]])
        tree[cur] = tree[left];
    else
        tree[cur] = tree[right];
}

ll getAnswer(int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    if (y < l || x > r)
        return 0;
    if (l >= x && r <= y)
        return tree[cur];

    ll res1 = getAnswer(left, l, mid, x, y);
    ll res2 = getAnswer(right, mid + 1, r, x, y);
    if(arr[res1] < arr[res2])
        return res1;
    else
        return res2;
}

ll ans (int l, int r)
{
    ll x = getAnswer(1,1,N,l,r);
    ll ret = arr[x]*(r-l+1);
    if(x > l)
        ret = max(ret,ans(l,x-1));
    if(x < r)
        ret = max(ret,ans(x+1,r));
    return ret;
}

int main()
{
    int n;
    while(cin >> n && n)
    {
        memset(arr,0,sizeof arr);
        arr[0] = OO;
        for(int i=1; i<=n; i++)
            cin >> arr[i];
        build(1, 1, N);
        cout << ans(1,n) << "\n";
    }
    return 0;
}
