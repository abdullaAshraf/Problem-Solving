/*
	Author: Abdulla Ashraf
	Idea:
        -answer and shift just as requested but using segment tree and fast I/O to save time 
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
const int OO = 200000;
int tree[2 * N];
int arr[2 + N];
void build(int cur, int l, int r)
{
    if (l == r)
    {
        tree[cur] = arr[l];
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[cur] = min(tree[left],tree[right]);
}

void update(int cur, int l, int r, int ind, int val)
{
    if (ind < l || ind > r)
        return;
    if (l == r && ind == l)
    {
        tree[cur] = val;
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, ind, val);
    update(right, mid + 1, r, ind, val);
    tree[cur] = min(tree[left],tree[right]);
}

int getAnswer(int cur, int l, int r, int x, int y)
{
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;

    if (y < l || x > r)
        return OO;
    if (l >= x && r <= y)
        return tree[cur];

    int r1 = getAnswer(left, l, mid, x, y);
    int r2 = getAnswer(right, mid + 1, r, x, y);
    return min(r1,r2);
}

int main()
{
    int n,m,a,b;
    char c;
    scanf("%d %d",&n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d",arr+i);
    arr[0] = OO;
    for(int i=n+1; i<N+2; i++)
        arr[i] = OO;
    build(1,1,N);
    cin.ignore();
    while(m--)
    {
        string c;
        getline(cin,c);
        string x = c.substr(c.find('(')+1);
        stringstream ss(x);
        char t;
        if(c[0] == 'q')
        {
            ss >> a >> t >> b;
            printf("%d\n",getAnswer(1,1,N,a,b));
        }
        else
        {
            ss >> a >> t;
            int v = arr[a];
            while(ss >> b >> t)
            {
                arr[a] = arr[b];
                update(1,1,N,a,arr[a]);
                a = b;
            }
            arr[a] = v;
            update(1,1,N,a,v);
        }
    }
    return 0;
}
