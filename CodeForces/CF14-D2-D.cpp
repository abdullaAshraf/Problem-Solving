/*
 Author: Abdulla Ashraf
 Idea:
 -at every node try to take every subtree diameter with the max 2 heights not passing through this point
 - try to split the diamter to half and take it and try to merge the top 3 subtree heights
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

pair<pair<int, int>, int> diameter(int i, int par = -1) {
	int diam = 0, d[205], h[205], mx2 = 0;
	int mxHeights[4] = { 0, 0, 0, 0 };

	for (int j = 0; j < x[i].size(); j++)
		if (x[i][j] != par) {
			pair<pair<int, int>, int> p = diameter(x[i][j], i);
			d[j] = p.first.second;
			h[j] = p.second + 1;
			diam = max(diam, p.first.second);
			mx2 = max(mx2, p.first.first);
			mxHeights[0] = p.second + 1;
			sort(mxHeights, mxHeights + 4);
		}
	for (int j = 0; j < x[i].size(); j++)
		if (x[i][j] != par) {
			int v;
			if (mxHeights[3] == h[j])
				v = mxHeights[1] + mxHeights[2];
			else if (mxHeights[2] == h[j])
				v = mxHeights[3] + mxHeights[1];
			else
				v = mxHeights[3] + mxHeights[2];
			mx2 = max(mx2, d[j] * v);
		}
	mx2 = max(mx2, (mxHeights[2] + mxHeights[1]) * (mxHeights[3] - 1));
	diam = max(diam, mxHeights[2] + mxHeights[3]);
	mx2 = max(mx2, (diam / 2) * ((diam - 1) / 2));
	return make_pair(mp(mx2, diam), mxHeights[3]);
}

int main() {
	int n, a, b;
	cin >> n;
	x = vector<vector<int>>(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		x[a].pb(b);
		x[b].pb(a);
	}
	int mx = 0;
	for (int i = 1; i <= n; i++)
		mx = max(mx, diameter(i).first.first);
	cout << mx << "\n";
	return 0;
}
