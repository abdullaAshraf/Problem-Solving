/*
 Author: Abdulla Ashraf
 Idea:
 -Max flow min cut straight forward implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
const double PI = acos(-1.0);
const double EPS = 1e-9;

typedef long long ll;
#define INF 1000000007

const int mod = 7 + 1e9;
const int N = (1 << 19);
const ll OO = (ll) 1 * 1e9;

const int MAXN = 51;
int cap[MAXN][MAXN], path[MAXN], prv[MAXN], ds[MAXN];

bool visited[MAXN];
int n, src, sink, pathLength;

int min(int a, int b) {
	return a < b ? a : b;
}
/* Dijkstra's varient[MaxiMin] to augmenting path */
int getPath(int StartNode, int TargetNode) {
	int i, maxd, maxi, cur;
	memset(visited, 0, sizeof(bool) * n);
	memcpy(ds, &cap[StartNode][0], sizeof(int) * n);

	cur = StartNode, visited[cur] = true;

	for (i = 0; i < n; i++)
		prv[i] = cur;

	while (1) {
		maxd = 0, maxi = -1;

		for (i = 0; i < n; i++) {
			if (!visited[i] && ds[i] > maxd)
				maxd = ds[i], maxi = i;
		}

		if (maxd == 0)
			break;
		if (maxi == TargetNode)
			break;
		cur = maxi, visited[cur] = true;

		for (i = 0; i < n; i++) {
			if (min(ds[cur], cap[cur][i]) > ds[i]) /* MaxiMin */
				ds[i] = min(ds[cur], cap[cur][i]), prv[i] = cur;
		}
	}
	int pi = TargetNode;
	pathLength = 0;

	while (1) {
		path[pathLength++] = pi;
		if (pi == StartNode)
			break;
		pi = prv[pi];
	}
	//reverse(path,path+pathLength);

	return ds[TargetNode];
}

int maxFlow() {
	int newflow, m, n, tf = 0;

	while (newflow = getPath(src, sink)) {
		for (int i = pathLength - 1; i > 0; i--) {
			m = path[i], n = path[i - 1];
			cap[m][n] -= newflow;
			cap[n][m] += newflow;
		}
		tf += newflow;
	}
	return tf;
}

void flood_fill(int src) {
	visited[src] = 1;
	for (int i = 0; i < n; i++)
		if (!visited[i] && cap[src][i] > 0)
			flood_fill(i);
}

struct edge {
	int from, to;
	edge() {
	}
	edge(int f, int t) {
		from = f, to = t;
	}
};
edge e[501];

int main() {
	int i, j, links;

	while (cin >> n >> links && (n || links)) {
		src = 0;
		sink = 1;

		for (i = 0; i < n + 2; i++)
			for (j = 0; j < n + 2; j++)
				cap[i][j] = 0;

		for (i = 0; i < links; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			cap[a - 1][b - 1] = cap[b - 1][a - 1] = c;

			e[i] = edge(a - 1, b - 1);
		}

		int max_ = maxFlow();
		//cout<<max_<<"\n";

		memset(visited, 0, sizeof(bool) * n);

		/* find all nodes reachable from src */
		flood_fill(src);

		for (i = 0; i < links; i++) { /* any edge that is reachable from u but not v is mincut edge */
			if (visited[e[i].from] && !visited[e[i].to])
				cout << e[i].from + 1 << " " << e[i].to + 1 << "\n";
			else if (visited[e[i].to] && !visited[e[i].from])
				cout << e[i].from + 1 << " " << e[i].to + 1 << "\n";
		}
		cout << "\n";
	}
	return 0;
}
