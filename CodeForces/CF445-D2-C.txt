/*
	Author: Abdulla Ashraf

	Idea:
        - getting any 1 node will lead to answer of 0
        - if we currently have fracture of (a+b)/c and we consider (a+b+x)/(c+y) then we have 2 options
        - x < y then this add will lead to lower the current fracture
        - x > y it may increase the fracture (a+b)/c , but (x+a)/y alone will be bigger.
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


int v[505];
int main()
{
    int n,m,a,b,c;
    double mx = 0;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> v[i];
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        mx = max(mx,(v[a]+v[b])/(1.0*c));
    }
    cout << fixed << setprecision(15) << mx ;
    return 0;
}
