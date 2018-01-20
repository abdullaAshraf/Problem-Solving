/*
	Author: Abdulla Ashraf
	Idea:
        -maximize the start point and minimize the end point
        -now get the area of the common rectangle.
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

int main()
{
    int T;
    cin >> T;
    for(int tt =1; tt<=T; tt++)
    {
        int n,x,y,u,v,mx = -100000,my = -100000,mu = 100000,mv = 100000;
        cin >> n;
        while(n--)
        {
            cin >> x >> y >> u >> v;
            mx = max(mx,x);
            my = max(my,y);
            mu = min(mu,u);
            mv = min(mv,v);
        }
        cout << "Case " << tt << ": " << max(0,mu-mx) * max(0,mv-my) <<"\n";
    }
    return 0;
}
