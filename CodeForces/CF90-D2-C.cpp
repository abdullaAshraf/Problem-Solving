/*
	Author: Abdulla Ashraf
	Idea:
        - to get 1 diamond you have to move one from every cell with an odd number to the next one and take one from the last.
        - minimize number of diamonds in every odd cell and the number of times u can preform that task.
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
    ll n,m,k,t,mn=1000000;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
    {
        cin >> t;
        if(i%2 == 0)
            mn = min(mn,t);
    }
    if(n%2 == 0)
        cout << 0;
    else
        cout << min(mn,m/((n+1)/2) * k);
    return 0;
}
