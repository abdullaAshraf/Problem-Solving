/*
 Author: Abdulla Ashraf
 Idea:
 -dp on the tree to find best way
 -keep the point the parent and bool if u picked the parent
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

const int MOD = 7 + 1e9;
const ll OO = (ll) 1 * 1e9;

int n, mem[100005][2];

vector<vector<int>> x;

int go(int in, int p, int v) {
	int & ret = mem[in][v];
	if (ret != -1)
		return ret;
	ret = 1;
	for (auto it : x[in])
		if (it != p)
			ret += go(it, in, 1);
	if (v) {
		int ret2 = 0;
		for (auto it : x[in])
			if (it != p)
				ret2 += go(it, in, 0);
		ret = min(ret, ret2);
	}
	return ret;
}

int main() {
	cin >> n;
	x.resize(n + 1);
	memset(mem, -1, sizeof mem);
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		x[a].pb(b);
		x[b].pb(a);
	}
	cout << go(1, 0, 1);
	return 0;
}
