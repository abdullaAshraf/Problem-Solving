/*
 Author: Abdulla Ashraf
 Idea:
  -use dfs to split girls to groups then use dynamic programming
  -memorize the group number and the remaining wieght so far mem[1000][1000]
  -for each group store the sum of it's weight , sum of it is beauty , and the members of this group
  -at dp we can take the whole group , or none or take only 1 from it
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

const int N = (1 << 20);
const ll OO = (ll) 1 * 1e18;

int n, m, w, a[1005], b[1005], vis[1005], ta[1005], tb[1005], mem[1005][1005];
vector<vector<int>> x, g;

void dfs(int in) {
	vis[in] = 1;
	g[g.size() - 1].pb(in);
	ta[g.size() - 1] += a[in];
	tb[g.size() - 1] += b[in];
	for (int i = 0; i < x[in].size(); i++)
		if (!vis[x[in][i]])
			dfs(x[in][i]);
}

int go(int in, int r) {
	if (in == g.size())
		return 0;
	int & ret = mem[in][r];
	if (ret != -1)
		return ret;
	ret = go(in + 1, r);
	if (r >= ta[in])
		ret = max(ret, tb[in] + go(in + 1, r - ta[in]));
	for (auto it : g[in])
		if (r >= a[it])
			ret = max(ret, b[it] + go(in + 1, r - a[it]));
	return ret;
}

int main() {
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
	cin >> n >> m >> w;
	x.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		x[u].pb(v);
		x[v].pb(u);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			vector<int> h;
			g.pb(h);
			dfs(i);
		}
	memset(mem, -1, sizeof mem);
	/*cout << g.size() << endl;
	for(int i=0; i<g.size(); i++){
		cout << ta[i] << " " << tb[i] << endl;
		for(auto it : g[i])
			cout << it << " ";
		cout << endl;
	}*/
	cout << go(0, w);
	return 0;
}
