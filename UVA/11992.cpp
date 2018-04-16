/*
 Author: Abdulla Ashraf
 Idea:
 -
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

#define INF (1 << 31)

/* 2D Segment Tree node */
struct Point {
	int mx, mn, sum, lset, ladd, set;
	Point() {
		mx = mn = sum = ladd = lset = set = 0;
	}
};

const int MAX = 8000005;
Point T[MAX];

struct Segtree2d {
	int n, m;

	// initialize and construct segment tree
	void init(int n, int m) {
		this->n = n;
		this->m = m;
		build(1, 1, 1, n, m);
	}

	// build a 2D segment tree from data [ (a1, b1), (a2, b2) ]
	// Time: O(n logn)
	Point build(int node, int a1, int b1, int a2, int b2) {
		// out of range
		if (a1 > a2 or b1 > b2)
			return def();

		// if it is only a single index, assign value to node
		if (a1 == a2 and b1 == b2)
			return T[node] = Point();

		// split the tree into four segments
		T[node] = def();
		T[node] = push(T[node],
				build(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2));
		T[node] = push(T[node],
				build(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2));
		T[node] = push(T[node],
				build(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2));
		T[node] = push(T[node],
				build(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2,
						b2));
		return T[node];
	}

	void down(int p, int x1, int y1, int x2, int y2) {
		if (T[p].ladd) {
			T[p].sum += (x2 - x1 + 1) * (y2 - y1 + 1) * T[p].ladd;
			T[p].mx += T[p].ladd;
			T[p].mn += T[p].ladd;
			for (int c = 4 * p - 2; c <= 4 * p + 1; c++)
				if (c < MAX) {
					if (T[c].set)
						T[c].lset += T[p].ladd;
					else
						T[c].ladd += T[p].ladd;
				}
			T[p].ladd = 0;
		}
		if (T[p].set) {
			T[p].sum = (x2 - x1 + 1) * (y2 - y1 + 1) * T[p].lset;
			T[p].mx = T[p].lset;
			T[p].mn = T[p].lset;
			for (int c = 4 * p - 2; c <= 4 * p + 1; c++)
				if (c < MAX) {
					T[c].set = 1;
					T[c].lset = T[p].lset;
					T[c].ladd = 0;
				}
			T[p].set = T[p].lset = 0;
		}
	}

	// helper function for query(int, int, int, int);
	Point query(int node, int a1, int b1, int a2, int b2, int x1, int y1,
			int x2, int y2) {
		// if we out of range, return dummy
		if (x1 > a2 or y1 > b2 or x2 < a1 or y2 < b1 or a1 > a2 or b1 > b2)
			return def();

		down(node, a1, b1, a2, b2);

		// if it is within range, return the node
		if (x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2)
			return T[node];

		// split into four segments
		Point val = def();
		val = push(val,
				query(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1,
						y1, x2, y2));
		val = push(val,
				query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2,
						x1, y1, x2, y2));
		val = push(val,
				query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2,
						x1, y1, x2, y2));
		val = push(val,
				query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2,
						b2, x1, y1, x2, y2));
		return val;
	}

	// query from range [ (x1, y1), (x2, y2) ]
	// Time: O(logn)
	Point query(int x1, int y1, int x2, int y2) {
		return query(1, 1, 1, n, m, x1, y1, x2, y2);
	}

	// helper function for update(int, int, int);
	Point update(int node, int a1, int b1, int a2, int b2, int x1, int y1,
			int x2, int y2, int value, int t) {
		if (a1 > a2 or b1 > b2)
			return def();

		down(node, a1, b1, a2, b2);

		if (x1 > a2 or y1 > b2 or x2 < a1 or y2 < b1 or a1 > a2 or b1 > b2)
			return T[node];

		if (x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2) {
			if (t == 1)
				T[node].ladd += value;
			else {
				T[node].set = 1;
				T[node].lset = value;
			}
			down(node, a1, b1, a2, b2);
			return T[node];
		}

		Point val = def();
		val = push(val,
				update(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1,
						y1, x2, y2, value, t));
		val = push(val,
				update(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2,
						x1, y1, x2, y2, value, t));
		val = push(val,
				update(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2,
						x1, y1, x2, y2, value, t));
		val = push(val,
				update(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2,
						b2, x1, y1, x2, y2, value, t));
		return T[node] = val;
	}

	// update the value of (x, y) index to 'value'
	// Time: O(logn)
	Point update(int x1, int y1, int x2, int y2, int value, int t) {
		return update(1, 1, 1, n, m, x1, y1, x2, y2, value, t);
	}

	// utility functions; these functions are virtual because they will be overridden in child class
	Point push(Point a, Point b) {
		a.mx = max(a.mx, b.mx);
		a.mn = min(a.mn, b.mn);
		a.sum = a.sum + b.sum;
		return a;
	}

	// dummy node
	Point def() {
		Point p;
		p.sum = 0;
		p.mx = -INF;
		p.mn = INF;
		return p;
	}
};

int main(void) {
	int r, c, m, t, x1, x2, y1, y2, v;
	while (cin >> r >> c >> m) {
		Segtree2d sg;
		sg.init(r, c);
		while (m--) {
			cin >> t >> x1 >> y1 >> x2 >> y2;
			if (t < 3) {
				cin >> v;
				sg.update(x1, y1, x2, y2, v, t);
			} else {
				Point ans = sg.query(x1, y1, x2, y2);
				cout << ans.sum << " " << ans.mn << " " << ans.mx << "\n";
			}
		}
	}
	return 0;
}
