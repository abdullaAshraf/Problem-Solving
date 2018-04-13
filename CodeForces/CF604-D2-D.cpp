/*
 Author: Abdulla Ashraf
 Idea:
 -we have p links between nodes
 -some observation to inputs and dedcation it has something to do with the number of connected groups
 -handle k=1 since all possible permtiantions is allowed and 0 since all from 1 to p-1 is allowed
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)
const double PI = acos(-1.0);
const double EPS = 1e-9;

typedef long long ll;

const int N = (1 << 17);
const ll MOD = 7 + 1e9;
const ll OO = (ll) 1 * 1e18;

struct UnionFind {
	vector<int> size, parent;
	int forests;

	UnionFind(int n) {
		size = vector<int>(n);
		parent = vector<int>(n);
		forests = n;
		for (int i = 0; i < n; i++)
			parent[i] = i, size[i] = 1;
	}

	int find_set(int x) {
		if (x == parent[x])
			return x;
		return parent[x] = find_set(parent[x]);
	}

	void link(int x, int y) {
		if (size[x] > size[y])
			swap(x, y);
		parent[x] = y;
		size[y] += size[x];
	}

	bool union_sets(int x, int y) {
		x = find_set(x), y = find_set(y);
		if (x != y) {
			link(x, y);
			forests--;
		}
		return x != y;
	}

	int same_set(int x, int y) {
		return find_set(x) == find_set(y);
	}

	vector<vector<int>> connected_components() {
		vector<vector<int>> list(sz(parent));
		for (int i = 0; i < sz(parent); i++) {
			list[find_set(i)].push_back(i);
		}
		return list;
	}
};

int main() {
	ll p, k;
	cin >> p >> k;
	ll s = 1;
	if (!k)
		for (int i = 1; i < p; i++)
			s = (s * p) % MOD;
	else if (k == 1) {
		for (int i = 0; i < p; i++)
			s = (s * p) % MOD;
	} else {
		UnionFind u = UnionFind(p);
		for (int x = 0; x < p; x++)
			u.union_sets(x, (k * x) % p);

		for (int i = 0; i < p; i++)
			if (u.parent[i] == i && u.size[i] > 1)
				s = (s * p) % MOD;
	}
	cout << s;
	return 0;
}
