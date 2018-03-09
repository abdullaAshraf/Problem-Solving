/*
 Author: Abdulla Ashraf
 Idea:
 -memorize the teams still in the game so far by an int bitmask
 -use a trick to reuse the function so we have only 2 possibilites every call
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

const int N = (1 << 14);
const int OO = (ll) 1 * 1e9;
const ll mod = 1e9 + 7;

int g[16][16];
bool vis[1 << 17][9];
vector<double> mem[1 << 17][9];
string ms[16];

vector<double> go(int in, int m, int t) {
	if (in == 32) {
		vector<double> x(16);
		for (int i = 0; i < 16; i++)
			if (m & (1 << i))
				x[i] = 100;
			else
				x[i] = 0;
		return x;
	}
	if (t * in == 16)
		return go(in * 2, m, 0);
	vector<double> &ret = mem[m][t];
	if (vis[m][t])
		return ret;
	vis[m][t] = 1;
	int u = -1, v;
	for (int i = t * in; i < (t + 1) * in; i++)
		if (m & (1 << i))
			if (u == -1)
				u = i;
			else
				v = i;
	ret = go(in, m ^ (1 << u), t + 1);
	vector<double> y = go(in, m ^ (1 << v), t + 1);
	for (int i = 0; i < 16; i++)
		ret[i] = (ret[i] * g[v][u] + y[i] * g[u][v]) / 100;
	return ret;
}

int main() {
	int sz = 0;
	for (int i = 0; i < 16; i++) {
		cin >> ms[i];
		sz = max(sz, (int) ms[i].size());
	}
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			cin >> g[i][j];
	vector<double> x = go(2, (1 << 16) - 1, 0);
	for (int i = 0; i < 16; i++) {
		while (ms[i].size() < sz)
			ms[i] += " ";
		cout << ms[i] << " p=" << fixed << setprecision(2) << x[i] << "%\n";
	}
	return 0;
}
