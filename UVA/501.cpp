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

const int N = (1 << 15);
const int OO = 200000;

int tree[2 * N];

void update(int cur, int l, int r, int ind)
{
    if (ind < l || ind > r)
        return;
    if (l == r && ind == l)
    {
        tree[cur]++;
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, ind);
    update(right, mid + 1, r, ind);
    tree[cur] = tree[left] + tree[right];
}

int getAnswer(int cur, int l, int r, int k)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    if(l == r)
        return l;

    if(tree[left] >= k)
        return getAnswer(left, l, mid, k);
    else
        return getAnswer(right, mid + 1, r, k-tree[left]);
}

int a[N],b[N];
map<int,int> x;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        memset(tree,0,sizeof tree);
        int n,m,t,r=0;
        cin >> n >> m;
        for(int i=0; i<n; i++)
        {
            scanf("%d",a+i);
            b[i] = a[i];
        }
        sort(b,b+n);
        for(int i=0; i<n; i++)
            x[b[i]] = i;

        for(int i=0; i<m; i++)
        {
            cin >> t;
            while(r < t)
                update(1,1,N,x[a[r++]]+1);
           printf("%d\n",b[getAnswer(1,1,N,i+1)-1]);
        }
        if(T)
            printf("\n");
    }
    return 0;
}
