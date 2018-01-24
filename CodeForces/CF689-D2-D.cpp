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

const int N = (1 << 18);
const ll OO = (ll) 1 * 1e18;
ll arr[N + 2][2];
ll tree[2 * N][2];
void build(int cur, int l, int r)
{
    if (l == r)
    {
        tree[cur][0]  = arr[l][0];
        tree[cur][1]  = arr[l][1];
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[cur][0] = max(tree[left][0],tree[right][0]);
    tree[cur][1] = min(tree[left][1],tree[right][1]);
}

ll getAnswer(int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    if (y < l || x > r)
        return OO;
    if (l >= x && r <= y)
        return tree[cur][1];

    ll res1 = getAnswer(left, l, mid, x, y);
    ll res2 = getAnswer(right, mid + 1, r, x, y);
    return min(res1,res2);
}

ll getAnswer2(int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    if (y < l || x > r)
        return 0;
    if (l >= x && r <= y)
        return tree[cur][0];

    ll res1 = getAnswer2(left, l, mid, x, y);
    ll res2 = getAnswer2(right, mid + 1, r, x, y);
    return max(res1,res2);
}

int n;

int getRight(int it)
{
    int l = it, r = n+1;
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        //cout << getAnswer2(1,1,N,it, m-1) << " " << getAnswer(1,1,N,it, m-1)<< endl;
        if (getAnswer(1,1,N,it, m-1) >= getAnswer2(1,1,N,it, m-1))
            l = m;
        else
            r = m;
    }
    return r;
}
int getLeft(int it)
{
    int l = it, r = n+1;
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        //cout << getAnswer2(1,1,N,it, m-1) << " " << getAnswer(1,1,N,it, m-1)<< endl;
        if (getAnswer(1,1,N,it, m-1) > getAnswer2(1,1,N,it, m-1))
            l = m;
        else
            r = m;
    }
    return r;
}

int main()
{
    ll ans = 0;
    cin >> n;
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i][0]);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i][1]);
    for(int i=n+1; i<=N; i++)
        arr[i][1] = OO;
    build(1,1,N);
    for(int l=1; l<=n; l++)
    {
        //cout << l << " " << getRight(l) << " "  << getLeft(l) << endl;
        ans += getRight(l)-getLeft(l);
    }
    cout << ans << endl;
    return 0;
}
