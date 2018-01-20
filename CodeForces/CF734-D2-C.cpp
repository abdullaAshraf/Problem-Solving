/*
	Author: Abdulla Ashraf
	Idea:
        -try every possible first spell (include not using one at all)
        -for everyone binary search on the other second type spell and minimize the total cost
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const int N = 10005;

ll a[200005],b[200005],c[200005];
vector<ll> d;

int main()
{
    int n,m,k,x,s,t;
    cin >> n >> m >> k >> x >> s;
    a[0] = x;
    b[0] = 0;
    d.resize(k);
    for(int i=1; i<=m; i++)
        cin >> a[i];
    for(int i=1; i<=m; i++)
        cin >> b[i];
    for(int i=0; i<k; i++)
        cin >> c[i];
    for(int i=0; i<k; i++)
        cin >> d[i];
    ll ans = 4000000000000000002;
    for(int i=0; i<=m; i++)if(s >= b[i])
    {
        auto it  = upper_bound(d.begin(),d.end(),s-b[i]);
        if(it != d.begin())
            it--;
        if(*it > s-b[i])
            ans = min(ans,n*a[i]);
        else
            ans = min(ans,max(0ll,n-c[it-d.begin()])*a[i]);
    }
    cout << ans;
    return 0;
}
