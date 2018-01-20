/*
	Author: Abdulla Ashraf
	Idea:
        -check to see which point is repeated
        -use the info that parallelogram has every 2 sides with the same slope so it is the same diff between Xs and Ys.
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

    double x1,y1,x2,y2,x3,y3,x4,y4,x,y;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
    {
        if(x1 == x3 && y1 == y3)
            x = x2+x4-x1, y = (y2+y4)-y1;
        else if(x1 == x4 && y1 == y4)
            x =  x2+x3-x1, y = y2+y3-y1;
        else if(x2 == x3 && y2 == y3)
            x = x1+x4-x2, y = y1+y4-y2;
        else
            x = x1+x3-x2, y = y1+y3-y2;
        cout << fixed << setprecision(3) << x << " " << y << "\n";
    }
    return 0;
}
