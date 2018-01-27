/*
	Author: Abdulla Ashraf
	Idea:
        -every fence has 2 options go left or right to the next edge.
        -use a memoization to calculate the best answer among all
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

int n,s,a[50005][2];

ll mem[50005][2];

ll dp(int in, int p)
{
    if(in == n)
        return abs(s-a[in-1][p]);
    ll & ret = mem[in][p];
    if(ret != -1)
        return ret;
    return ret = min(abs(a[in][0] - a[in-1][p]) + dp(in+1,0), abs(a[in][1] - a[in-1][p]) + dp(in+1,1));
}

int main()
{
    cin >> n >> s;
    memset(mem,-1,sizeof mem);
    for(int i=1; i<=n; i++)
        scanf("%d %d",&a[i][0],&a[i][1]);
    cout << dp(1,0) << "\n";
    return 0;
}
