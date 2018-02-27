/*
 Author: Abdulla Ashraf
 Idea:
  -we need only the sum of the edges used to connect the graph, use MST to get those
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

const int N = (1 << 18);
const ll OO = (ll) 1 * 1e18;
const ll mod = 1e9 + 7;

struct TimeTravellingSalesman {

	struct edge {
		int from, to, w;

		edge(int from, int to, int w) :
				from(from), to(to), w(w) {
		}

		bool operator <(const edge & e) const {
			return w > e.w;
		}
	};

	vector<int> rank, parent;
	int forests;

	void init(int n) {
		rank = vector<int>(n);
		parent = vector<int>(n);
		forests = n;
		for (int i = 0; i < n; i++)
			parent[i] = i, rank[i] = 1;
	}

	int find_set(int x) {
		if (x == parent[x])
			return x;
		return parent[x] = find_set(parent[x]);
	}

	void link(int x, int y) {
		if (rank[x] > rank[y])
			swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y])
			rank[y]++;
	}

	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {
			link(x, y);
			forests--;
		}
		return x != y;
	}

	ll determineCost(int n, vector<string> s) {
		ll mstCost = 0;
		init(n);
		priority_queue<edge> q;

		vector<int> v;
		int a;
		string x = "",token;
		for (auto it : s)
			x += it;

		stringstream ss(x);
		while (getline(ss, token, ',')) {
			stringstream ss2(token);
			while (ss2 >> a)
				v.pb(a);
		}
		for (int i = 0; i < v.size(); i += 3)
			q.push(edge(v[i], v[i + 1], v[i + 2]));

		while (!q.empty()) {
			edge e = q.top();
			q.pop();

			if (union_sets(e.from, e.to))
				mstCost += e.w;
		}
		if (forests > 1)
			return -1;
		else
			return mstCost;
	}

}
;
