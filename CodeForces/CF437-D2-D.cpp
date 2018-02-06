/*
	Author: Abdulla Ashraf
	Idea:
        -give a value to every edge which is min of the values on the nodes it contects
        -sort edges decreasingly and use a modifed kruskal algorthim to find how many nodes are connected using every new edge
        -use simple math equations to calculate the answer
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
const int OO = 200000;

struct edge
{
    int from, to, w;

    edge(int from, int to, int w): from(from), to(to), w(w) {}

    bool operator < (const edge & e) const
    {
        return w < e.w;
    }
};

struct UnionFind
{
    vector<int> rank,parent;
    int forests;

    UnionFind(int n)
    {
        rank = vector<int>(n);
        parent = vector<int>(n);
        int forests = n;
        for(int i=0; i<n; i++) parent[i]  = i, rank[i] = 1;
    }

    int find_set(int x)
    {
        if(x == parent[x]) return x;
        return parent[x] = find_set(parent[x]);
    }

    void link(int x,int y)
    {
        if(rank[x] > rank[y]) swap(x,y);
        parent[x] = y;
        rank[y] += rank[x];
    }

    bool union_sets(int x,int y)
    {
        x = find_set(x), y = find_set(y);
        if(x != y)
        {
            link(x,y);
            forests--;
        }
        return x != y;
    }

    ll same_set(int x,int y)
    {
        x = find_set(x), y = find_set(y);
        if(x == y)
            return 0;
        ll t = (ll)rank[x] * rank[y];
        link(x,y);
        forests--;
        return t;
    }

    vector<vector<int>> connected_components()
    {
        vector<vector<int>> list(sz(parent));
        for(int i=0; i<sz(parent); i++)
        {
            list[find_set(i)].push_back(i);
        }
        return list;
    }
};

vector<edge> edgeList;

ll a[100005];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n,m,b,c;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<m; i++)
    {
        cin >> b >> c;
        edgeList.pb(edge(b-1,c-1,min(a[b-1],a[c-1])));
    }
    UnionFind uf(n);
    double mstCost = 0;
    priority_queue<edge> q;
    for(int i=0; i<edgeList.size(); i++) q.push(edgeList[i]);

    while( !q.empty() )
    {
        edge e = q.top();
        q.pop();

        mstCost += uf.same_set(e.from, e.to) * e.w;
    }
    cout << fixed << setprecision(6) << 2*mstCost/(n*(n-1));
    return 0;
}
