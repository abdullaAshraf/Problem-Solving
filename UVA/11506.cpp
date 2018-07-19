/*
 Author: Abdulla Ashraf
 Idea:
 -max flow with vertex spliting on all but source and sink
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
#define MAXN (101)
#define MAXC (500 * 499 / 2 + 1)

typedef long long ll;
typedef complex<double> point;
#define X real()
#define Y imag()

const int N = (1 << 19);
const int OO = 1 * 1e9;

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

	while ((newflow = getPath(src, sink))) {
		for (int i = pathLength - 1; i > 0; i--) {
			m = path[i], n = path[i - 1];
			cap[m][n] -= newflow;
			cap[n][m] += newflow;
		}
		tf += newflow;
	}
	return tf;
}

int main() {
	int links;

	while (cin >> n >> links && (n || links)) {
		src = 0;
		sink = n - 1;

		for (int i = 0; i < n * 2; i++)
			for (int j = 0; j < n * 2; j++)
				cap[i][j] = 0;

		int a, b;
		for (int i = 1; i < n - 1; i++) {
			cin >> a >> b;
			a--;
			cap[a][a + n] = b;
		}

		for (int i = 0; i < links; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			a--;
			b--;
			cap[a == 0 || a == n - 1 ? a : a + n][b] = cap[
					b == 0 || b == n - 1 ? b : b + n][a] = c;
		}

		n *= 2;

		cout << maxFlow() << "\n";
	}
	return 0;
}
