/*
	Author: Abdulla Ashraf
	Idea:
       -split components into m group by name now go over every group and pick a component from the group then move to next
       -sort each group upward depending on quality and we remove any thing more expensive and less quality from the group
       -now binary search over quality and we check the cheapest we can get a pc with this quality
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
const int OO = INT_MAX;

int m,r;
map<pair<int,int>,int>x;
vector<vector<pair<int,int>>> g;
int p[1005],q[1005];

bool f(int v)
{
    ll s = 0;
    for(int in=0; in<m; in++)
    {
        auto it = lower_bound(g[in].begin(),g[in].end(),mp(v,0));
        s += (*it).second;
    }
    return s <= r;
}

int bs(int a, int b)
{
    while (b - a > 1)
    {
        int m = (a + b) / 2;
        if (!f(m))
        {
            b = m;
        }
        else
        {
            a = m;
        }
    }
    if(f(b))return b;
    return a;
}

int clean()
{
    int mx=OO;
    for(int in=0; in<m; in++)
    {
        sort(g[in].begin(),g[in].end(),[](pair<int,int> l,pair<int,int> r)
        {
            if(l.first == r.first)
                return l.second > r.second;
            return l.first < r.first;
        });
        mx = min(mx,g[in][g[in].size()-1].first);
        vector<pair<int,int>> t;
        int mn = OO;
        for(int i=g[in].size()-1; i>=0; i--)if(mn > g[in][i].second)
            {
                t.pb(g[in][i]);
                mn = g[in][i].second;
            }
        g[in].clear();
        for(int i=t.size()-1; i>=0; i--)
            g[in].pb(t[i]);
    }
    return mx;
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,n;
    cin >> T;
    while(T--)
    {
        x.clear();
        g.clear();
        map<string,int> d;
        cin >> n >> r;
        int c= 0;
        while(n--)
        {
            string s,u;
            cin >> s >> u >> p[n] >> q[n];
            if(d.find(s) == d.end())
            {
                d[s] = c++;
                g.pb(vector<pair<int,int>>());
            }
            g[d[s]].pb(mp(q[n],p[n]));
        }
        m = g.size();
        cout << bs(0,clean()) << "\n";
    }
    return 0;
}
