/*
	Author: Abdulla Ashraf
	Idea:
        -make another sorted array of the same elements
        -when u reach a point where both sub arrays have the same elements consider this a block.
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
    int n,a[100005],b[100005],c = 0,v=0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    map<int,int> x;
    while(v < n)
    {
        if(++x[a[v]] == 0)
            x.erase(a[v]);
        if(--x[b[v]] == 0)
            x.erase(b[v]);
        v++;
        if(x.empty())
            c++;
    }
    cout << c;
    return 0;
}
