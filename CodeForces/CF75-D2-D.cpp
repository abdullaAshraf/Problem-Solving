/*
	Author: Abdulla Ashraf
	Idea:
        -keep 5 values for every array , max subarray from start ,  max subarray from end ,  max subarray ,  totoal sum of values , max number
        -when passing on an array we may do one of the following:
          -stop here and take the best sum so far + the max from start
          -take the whole array sum + the best sum so far and keep going
          -take the max subarray end and keep going with it
          -take the max subarray only in this array
        - if all "used" values where negative we take the largest one
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
const ll OO = 2ll * 1e8;

int a[5005];
ll mxs[55],mxe[55],mxt[55],mxv[55];
int mxn[55];

int main()
{
    int n,m,l,t;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        mxn[i] = INT_MIN;
        cin >> l;
        ll s=0;
        for(int j=0; j<l; j++)
        {
            cin >> a[j];
            mxn[i] = max(mxn[i],a[j]);
            mxt[i]+=a[j];
            s = max(0ll,s+a[j]);
            mxv[i] = max(mxv[i],s);
            mxs[i]=max(mxs[i],mxt[i]);
        }
        s=0;
        for(int j=l-1; j>=0; j--)
        {
            s+=a[j];
            mxe[i]=max(mxe[i],s);
        }
    }
    ll mx = 0,x=0 ;
    int to = INT_MIN;
    for(int i=0; i<m; i++)
    {
        cin >> t;
        to = max(to,mxn[t]);
        mx = max(mx,x+mxs[t]);
        x = max(x+mxt[t],mxe[t]);
        mx = max(mx,x);
        mx = max(mx,mxv[t]);
    }
    if(to <= 0)
        cout << to;
    else
        cout << mx;
    return 0;
}
