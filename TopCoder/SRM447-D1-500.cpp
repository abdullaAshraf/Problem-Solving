/*
 Author: Abdulla Ashraf
 Idea:
 -use 2 dijksteras to determine all paths between the 2 people that needs to be removed
 -use max_flow to determine how many points needs to be removed
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
#define MAXN (41)
#define MAXC (500 * 499 / 2 + 1)
#define MOD 1000000007

typedef long long ll;

const int N = (1 << 19);
const int OO = 1 * 1e9;

int n, adjMax[MAXN][MAXN];
int cap[MAXN][MAXN], path[MAXN], prv[MAXN], ds[MAXN];
bool visited[MAXN];
int src, sink, pathLength;

pair<vector<int>, vector<int>> Dijkstra1(int src) {
	vector<int> vis(n, 0), dist(n, OO), prev(n, -1);
	dist[src] = 0;
	while (true) {
		int val = OO, idx = -1;
		for (int i = 0; i < n; i++)
			if (!vis[i] && dist[i] < val)
				val = dist[i], idx = i;

		if (idx == -1)
			break;
		vis[idx] = 1;

		for (int i = 0; i < n; i++)
			if (dist[i] > (val = dist[idx] + adjMax[idx][i]))
				dist[i] = val, prev[i] = idx;
	}
	return mp(dist, prev);
}

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

struct PeopleYouMayKnow {

	int maximalScore(vector<string> friends, int p1, int p2) {
		n = friends.size();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (friends[i][j] == 'Y')
					adjMax[i][j] = 1;
				else
					adjMax[i][j] = OO;
		src = p1, sink = p2;
		pair<vector<int>, vector<int>> t = Dijkstra1(src);
		vector<int> len = t.first, pr1 = t.second;
		t = Dijkstra1(sink);
		for (int i = 0; i < n; i++)
			len[i] += t.first[i];
		vector<int> pr2 = t.second;
		for (int i = 0; i < n; i++)
			if (len[i] <= 3) {
				int k = i;
				while (k != src) {
					cap[pr1[k]][k] = 1;
					k = pr1[k];
				}
				k = i;
				while (k != sink) {
					cap[k][pr2[k]] = 1;
					k = pr2[k];
				}
			}
		return maxFlow();
	}
};
