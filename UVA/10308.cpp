/*
 Author: Abdulla Ashraf
 Idea:
 -get weighted tree diameter
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

vector<vector<pair<int, int>>> x;

pair<int, int> diameter(int i, int par = -1) {
	int diam = 0;
	int mxHeights[3] = { 0, 0, 0 };

	for (int j = 0; j < x[i].size(); j++)
		if (x[i][j].first != par) {
			pair<int, int> p = diameter(x[i][j].first, i);
			diam = max(diam, p.first);

			mxHeights[0] = p.second + x[i][j].second;
			sort(mxHeights, mxHeights + 3);
		}

	diam = max(diam, mxHeights[1] + mxHeights[2]);

	return make_pair(diam, mxHeights[2]);
}

int main() {
	string s;
	int a, b, c;
	while (getline(cin, s)) {
		x = vector<vector<pair<int, int>>>(10000);
		stringstream ss(s);
		ss >> a >> b >> c;
		x[a].pb(mp(b, c));
		x[b].pb(mp(a, c));
		while (getline(cin, s) && s.length() > 3) {
			stringstream ss(s);
			ss >> a >> b >> c;
			x[a].pb(mp(b, c));
			x[b].pb(mp(a, c));
		}
		cout << diameter(1).first << "\n";
	}
	return 0;
}
