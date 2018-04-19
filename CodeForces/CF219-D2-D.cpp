/*
 Author: Abdulla Ashraf
 Idea:
 -start from any node do a dfs and count edges to reverse to reach every node in my subtree
 -now for all values but the root the answer is equal to the answer of the parent with only 1 edge differance "the edge between them"
 -both dfs must start from top to bottom so we can not do them both in 1 dfs
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

int n, t[200005];
vector<vector<int>> x;

void go(int in, int p) {
	for (auto it : x[in])
		if (abs(it) != p) {
			if (it < 0)
				t[in]++;
			go(abs(it), in);
			t[in] += t[abs(it)];
		}
}

void go2(int in, int p) {
	for (auto it : x[in])
		if (abs(it) != p) {
			if (it < 0)
				t[abs(it)] = t[in] - 1;
			else
				t[it] = t[in] + 1;
			go2(abs(it), in);
		}
}

int main() {
	cin >> n;
	int a, b;
	x.resize(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		x[a].pb(b);
		x[b].pb(-a);
	}
	go(1, 0);
	go2(1, 0);
	int mn = INT_MAX;
	for (int i = 1; i <= n; i++)
		mn = min(mn, t[i]);
	cout << mn << "\n";
	for (int i = 1; i <= n; i++)
		if (mn == t[i])
			cout << i << " ";
	return 0;
}
