/*
	Author: Abdulla Ashraf
	Idea:
        -consider adding camera as removing edge from a graph to remove all cycles we need a "tree"
        -get maxiumum spanning tree and count the sum of edges "we didn't use)
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
        if(rank[x] == rank[y]) rank[y]++;
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

    int same_set(int x,int y)
    {
        return find_set(x) == find_set(y);
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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,n,m,a,b,c;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        UnionFind uf(n);
        priority_queue<edge> q;
        while(m--)
        {
            scanf("%d %d %d",&a, &b, &c);
            q.push(edge(a-1,b-1,c));
        }
        int mstCost = 0;
        while( !q.empty() )
        {
            edge e = q.top();
            q.pop();

            if(!uf.union_sets(e.from, e.to))
                mstCost += e.w;
        }
        cout << mstCost << "\n";
    }
    cin >> T;
    return 0;
}
