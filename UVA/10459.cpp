/*
 Author: Abdulla Ashraf
 Idea:
 -get the tree centers those are the best roots
 -get the most far points from the centers those are the worst roots
 */

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const double EPS = 1e-9;

const int N = (1 << 14);
const int OO = (ll) 1 * 1e9;
const ll mod = 1e9 + 7;

vector<vector<int>> x;

vector<int> BFS2(int s) {
	vector<int> len(sz(x), OO);
	queue<int> q;
	q.push(s), len[s] = 0;

	int dep = 0, cur = s, sz = 1;
	for (; !q.empty(); ++dep, sz = q.size()) {
		while (sz--) {
			cur = q.front(), q.pop();
			for (int i = 0; i < x[cur].size(); i++)
				if (len[x[cur][i]] == OO)
					q.push(x[cur][i]), len[x[cur][i]] = dep + 1;
		}
	}
	vector<int> w;
	for (int i = 1; i <= sz(x); i++)
		if (len[i] == dep - 1)
			w.pb(i);
	return w;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int n, k, t;
	while (cin >> n) {
		x = vector<vector<int>>(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> k;
			while (k--) {
				cin >> t;
				x[i].pb(t);
			}
		}
		queue<int> LeafNodes;
		vector<int> deg(n+1, -1);
		int remNodes = n;
		for (int i = 1; i <= n; i++)
			if (sz(x[i]) <= 1)
				LeafNodes.push(i);
			else
				deg[i] = sz(x[i]);

		while (remNodes > 2)  // bfs-like
		{
			int sz = sz(LeafNodes);
			while (sz--) // level by level
			{
				int v = LeafNodes.front();
				LeafNodes.pop();

				for (int j = 0; j < x[v].size(); j++) {
					int to = x[v][j];
					if (--deg[to] == 1)
						LeafNodes.push(to);
				}
				--remNodes;
			}
		}

		set<int> w;
		// what remains are tree centers
		int v1 = LeafNodes.front();
		LeafNodes.pop();
		int v2 = LeafNodes.empty() ? -1 : LeafNodes.front();
		if (v1 > v2)
			swap(v1, v2);
		cout << "Best Roots  :";
		if (v1 != -1) {
			vector<int> h = BFS2(v1);
			for (auto it : h)
				w.insert(it);
			cout << " " << v1;
		}
		vector<int> h = BFS2(v2);
		for (auto it : h)
			w.insert(it);
		cout << " " << v2 << "\n";
		cout << "Worst Roots :";
		for (auto it : w)
			cout << " " << it;
		cout << "\n";
	}
	return 0;
}
