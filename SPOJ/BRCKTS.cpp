/*
	Author: Abdulla Ashraf
	Idea:
        -keep 2 paramters for every node in the segment tree , how many unmatched left and right facing bracktes
        -when conecting 2 segments match as much unmatched bracktes as possible
        -answer is the answer for the whole segmet tree which exist at 1.
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
char w[N+2];
int n,m,t;
int tree[2 * N][2];
void build(int cur, int l, int r)
{
    if (l == r)
    {
        if(l > n)
            tree[cur][0] = tree[cur][1] = 0;
        else
        {
            tree[cur][0] = (w[l-1] == ')' ? 1 : 0);
            tree[cur][1] = 1 - tree[cur][0];
        }
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[cur][0] = tree[left][0]+ max(0,tree[right][0]-tree[left][1]);
    tree[cur][1] = tree[right][1]+ max(0,tree[left][1]-tree[right][0]);
}

void update(int cur, int l, int r, int ind)
{
    if (ind < l || ind > r)
        return;
    if (l == r && ind == l)
    {
        tree[cur][0] = 1 - tree[cur][0];
        tree[cur][1] = 1 - tree[cur][1];
        return;
    }
    int left = 2 * cur;
    int right = 2 * cur + 1;
    int mid = (l + r) / 2;
    update(left, l, mid, ind);
    update(right, mid + 1, r, ind);
    tree[cur][0] = tree[left][0]+ max(0,tree[right][0]-tree[left][1]);
    tree[cur][1] = tree[right][1]+ max(0,tree[left][1]-tree[right][0]);
}

int main()
{
    for(int tt =1 ; tt<=10; tt++)
    {
        printf("Test %d:\n",tt);
        scanf("%d",&n);
        scanf("%s", &w);
        scanf("%d",&m);
        build(1,1,N);
        while(m--)
        {
            scanf("%d",&t);
            if(t)
                update(1,1,N,t);
            else if(tree[1][0] == 0 && tree[1][1] == 0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
