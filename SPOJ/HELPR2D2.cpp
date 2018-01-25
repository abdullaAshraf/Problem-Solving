/*
	Author: Abdulla Ashraf
	Idea:
        -the segment tree nodes is the value max of remaining in the containers
        -first build all with k then each time u need to add check if you can add at least one item in the left side if so add there first
        -if still have some to add and no container on the left child can hold it (max(left) < volume) add it to the right.
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

struct node
{
    ll s,l,r,m,mx;
};

int n,k;
int tree[2 * N];
void build(int cur, int l, int r)
{
    if (l == r)
    {
        tree[cur] = k;
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[cur] = max(tree[left],tree[right]);
}

int add(int cur, int l, int r, int x, int a)
{
    if(l == r)
    {
        int v =  min(a,tree[cur]/x);
        tree[cur] -=v*x;
        return a-v;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    if(a && tree[left] >= x)
        a=add(left, l, mid, x, a);
    if(a)
        a=add(right, mid + 1, r, x, a);
    tree[cur] = max(tree[left],tree[right]);
    return a;
}

int main()
{
    int T,a,b;
    cin >> T;
    while(T--)
    {
        cin >> k >> n;
        cin.ignore();
        build(1,1,N);
        string x;
        while(n)
        {
            getline(cin, x);
            char o;
            stringstream ss(x);
            if(x[0] == 'b')
                ss >> o >> b >> a;
            else
            {
                ss >> a;
                b =1;
            }
            n -= b;
            add(1,1,N,a,b);

        }
        int s=0,w=0;
        for(int i=N; ; i++,s++)
        {
            if(tree[i] == k)
                break;
            w += tree[i];
        }
        cout << s << " " << w << "\n";
    }
    return 0;
}
