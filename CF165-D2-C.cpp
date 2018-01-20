/*
	Author: Abdulla Ashraf

	Idea:
        -if k is 0 we have to count number of substrings for every 0 string in the full string
        -else it is something like sliding windows the number of different ways to represent a string that contain k ones is the number of zeros before the first one and the zeros after the last one in that substring
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

map<ll,int> s;
map<ll,int> e;
map<ll,queue<int>> sv;
vector<ll> x;
vector<int> vis;

ll v[1000005];

int main()
{
    int k,vx=0,c=0;
    string x;
    cin >> k >> x;
    for(auto cr : x)
    {
        if(cr == '0')
            c++;
        else
        {
            v[vx++] = c+1;
            c = 0;
        }
    }
    if(c || x[x.length()-1] == '1')
        v[vx++] = c+1;
    ll ans = 0;
    if(k == 0)
    {
        for(int i=0; i<vx; i++)
            ans += (v[i]-1)*v[i]/2;
    }

    else
    {
        for(int i=k; i<vx; i++)
            ans += v[i] * v[i-k];
    }
    cout << ans ;
    return 0;
}
