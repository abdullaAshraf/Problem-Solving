/*
 Author: Abdulla Ashraf
 Idea:
 -build normal tree and insert only wanted nodes in the sequence in revrse order
 -use dfs with visited to travrse everynode ones and find which node the man will gift in this sequence then compare it with the required one
 */

#include <bits/stdc++.h>

using namespace std;

#define l first
#define r second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
const double PI = acos(-1.0);
const double EPS = 1e-9;

typedef long long ll;

const int MOD = 7 + 1e9;
const ll OO = (ll) 1 * 1e9;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector<vector<int>> x;
vector<int> q;
int s[100005], g[100005], w[100005], ans[100005];

void topo(int in) {
	for (int i = 0; i < x[in].size(); i++)
		topo(x[in][i]);
	if (w[in])
		q.push_back(in);
}

void go(int in, int p) {
	ans[in] = p;
	for (int i = 0; i < x[in].size(); i++)
		if (!ans[x[in][i]])
			go(x[in][i], p);
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	x.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		x[a].push_back(b);
		s[b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		cin >> g[i];
		w[g[i]] = 1;
	}
	for (int i = 1; i <= n; i++)
		if (!s[i])
			topo(i);
	for (auto it : q)
		go(it, it);
	for (int i = 1; i <= n; i++)
		if (g[i] != ans[i]) {
			cout << -1;
			return 0;
		}
	cout << q.size() << "\n";
	for(auto it : q)
		cout << it << "\n";
}
