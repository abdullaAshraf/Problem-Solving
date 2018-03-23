/*
 Author: Abdulla Ashraf
 Idea:
 -the start and the end path will be navigated once , all other will be navigated twice
 -so at every point we can cosider 3 options take the 2 paths from this sub tree , only 1 from here , none from it
 -return pair , the amount I save if took 1 and the save if took 2
 -at each node maximize for taking both from every child, or take one from here and one from there
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

pair<int, int> dfs(int in, int p) {
	int mx[3] = { 0, 0, 0 };
	pair<int, int> ret = mp(0, 0);
	for (int i = 0; i < x[in].size(); i++)
		if (x[in][i] != p) {
			auto it = dfs(x[in][i], in);
			ret.second = max(ret.second, it.second);
			mx[0] = it.first;
			sort(mx, mx + 3);
		}
	ret.first = mx[2] + 1;
	ret.second = max(ret.second, mx[1] + mx[2] + 1);
	//cout << in << " " << ret.first << " " << ret.second << endl;
	return ret;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int T, n, k, t;
	cin >> T;
	while (T--) {
		cin >> n;
		x = vector<vector<int>>(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> k;
			while (k--) {
				cin >> t;
				x[i].pb(t);
			}
		}
		cout <<  2*n - 1 - dfs(1, 0).second << "\n";
	}
	return 0;
}
