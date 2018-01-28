/*
	Author: Abdulla Ashraf
	Idea:
        -a building can cover another building which is taller than it so if 2 building have the same height to be able to ocunt them as a single one there must be 0 shorter buildings between them
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
void build(int cur, int l, int r)
{
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

void update(int cur, int l, int r, int ind)
{
    if (ind < l || ind > r)
        return;
    if (l == r && ind == l)
    {
        tree[cur] = 1;
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, ind);
    update(right, mid + 1, r, ind);
    tree[cur] = tree[left]+ tree[right];
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
    return res1+ res2;
}

int main()
{
    int n,a,t = 1;
    while(cin >> n)
    {
        vector<pair<int,int>> x;
        int ans = 1;
        build(1,1,N);
        for(int i=1; i<=n; i++)
        {
            cin >> a;
            if(a == 0)
                update(1,1,N,i);
            else
                x.pb(mp(a,i));
        }
        if(x.size() == 0)
        {
            cout << "Case " << t++ << ": " << 0 << "\n";
            continue;
        }
        else if(x.size() == 1)
        {
            cout << "Case " << t++ << ": " << 1 << "\n";
            continue;
        }
        sort(x.begin(),x.end());
        for(int i=1; i<x.size(); i++)
        {
            if(x[i].first != x[i-1].first || getAnswer(1,1,N,x[i-1].second,x[i].second))
                ans++;
            update(1,1,N,x[i-1].second);
        }
        cout << "Case " << t++ << ": " << ans << "\n";
    }
    return 0;
}
