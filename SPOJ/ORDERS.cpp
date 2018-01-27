/*
	Author: Abdulla Ashraf
	Idea:
        -First calculate the posion where every one will end after his turn by using (his postion - the stepes he move)
        -everyone will end in the postion he wanted or after it no one can end up before the disired value.
        -only the ones after someone can affect him not the ones before him.
        -so the last one no one will affect him but him self the one before him only the last one and so on, so we start from the end
        -give everyone the position he wants but instead of absoulte place he will have the a[i]th free place now since he must have a[i] persons before him after his own move
        -using the idea of finding the kth element in a segment tree we can find the a[i]th free spot for everyone.         
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
int tree[2 * N];
void build(int cur, int l, int r)
{
    if (l == r)
    {
        tree[cur] = 1;
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[cur] = tree[left] + tree[right];
}

int update(int cur, int l, int r, int ind)
{
    if (l == r)
    {
        tree[cur] = 0;
        return l;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    int v;
    if(tree[left] >= ind)
        v = update(left, l, mid, ind);
    else
        v = update(right, mid + 1, r, ind - tree[left]);
    tree[cur] = tree[left] + tree[right];
    return v;
}

int a[200005],b[200005];

int main()
{
    int T,n,t;
    cin >> T;
    while(T--)
    {
        cin >> n;
        build(1,1,N);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&t);
            a[i] = max(1,i-t);
        }
        for(int i=n; i>0; i--)
        {
            b[i] = update(1,1,N,a[i]);
        }
        for(int i=1; i<=n; i++)
            printf("%d ",b[i]);
        printf("\n");
    }
    return 0;
}
