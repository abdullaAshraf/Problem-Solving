#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll OO = (ll) 1e9;

struct edge {
	int from, to, t;
	ll w;

	edge(int from, int to, int w, int t) :
			from(from), to(to), w(w), t(t) {
	}

	bool operator <(const edge & e) const {
		if (w == e.w)
			return t > e.t;
		return w > e.w;
	}
};

int main() {
	ios::sync_with_stdio(false);
	int n, m, k, a, b, c, an = 0;
	cin >> n >> m >> k;
	vector<vector<edge>> x(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge e = edge(a, b, c, 0);
		x[a].push_back(e);
		e = edge(b, a, c, 0);
		x[b].push_back(e);
	}
	priority_queue<edge> q;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		edge e = edge(1, a, b, 1);
		q.push(e);
	}
	vector<bool> vis(n + 1, 0);

	q.push(edge(-1, 1, 0, 0));

	while (!q.empty()) {
		edge e = q.top();
		q.pop();

		if (vis[e.to] && e.t == 1)
			an++;

		if (vis[e.to])
			continue;

		vis[e.to] = 1;

		for (int j = 0; j < x[e.to].size(); j++) {
			edge ne = x[e.to][j];
			q.push(edge(ne.from, ne.to, ne.w + e.w, 0));
		}
	}

	cout << an << endl;
	return 0;
}
