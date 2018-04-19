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

#define INF (1 << 30)

struct Point {
	int mx, mn, sum, lset, ladd;
	Point() {
		mx = mn = sum = ladd = lset = 0;
	}
};

struct seg {
	vector<Point> T;

	seg(int n) {
		n = 2 * n;
		T.resize(4 * n, Point());
	}

	void down(int p, int l, int r) {
		if (T[p].ladd) {
			T[p].sum += (r - l + 1) * T[p].ladd;
			T[p].mx += T[p].ladd;
			T[p].mn += T[p].ladd;
			if (l != r) {
				if (T[2 * p].lset)
					T[2 * p].lset += T[p].ladd;
				else
					T[2 * p].ladd += T[p].ladd;
				if (T[2 * p + 1].lset)
					T[2 * p + 1].lset += T[p].ladd;
				else
					T[2 * p + 1].ladd += T[p].ladd;
			}
			T[p].ladd = 0;
		}
		if (T[p].lset) {
			T[p].sum = (r - l + 1) * T[p].lset;
			T[p].mx = T[p].lset;
			T[p].mn = T[p].lset;
			if (l != r) {
				T[2 * p].lset = T[2 * p + 1].lset = T[p].lset;
				T[2 * p].ladd = T[2 * p + 1].ladd = 0;
			}
			T[p].lset = 0;
		}
	}

	void up(int p) {
		T[p].sum = T[2 * p + 1].sum + T[2 * p].sum;
		T[p].mx = max(T[2 * p + 1].mx, T[2 * p].mx);
		T[p].mn = min(T[2 * p + 1].mn, T[2 * p].mn);
	}

	void updateRange(int cur, int l, int r, int x, int y, ll val, int t) {
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;

		down(cur, l, r);

		if (l > y || x > r)
			return;

		if (l >= x && r <= y) {
			if (t == 1)
				T[cur].ladd += val;
			else
				T[cur].lset = val;
			down(cur, l, r);
			return;
		}

		updateRange(left, l, mid, x, y, val, t);
		updateRange(right, mid + 1, r, x, y, val, t);
		up(cur);
	}

	Point getAnswer(int cur, int l, int r, int x, int y) {
		int left = 2 * cur;
		int right = 2 * cur + 1;
		int mid = (l + r) / 2;

		down(cur, l, r);

		if (y < l || x > r)
			return def();
		if (l >= x && r <= y)
			return T[cur];

		Point r1 = getAnswer(left, l, mid, x, y);
		Point r2 = getAnswer(right, mid + 1, r, x, y);
		Point ans;
		ans.sum = r1.sum + r2.sum;
		ans.mx = max(r1.mx, r2.mx);
		ans.mn = min(r1.mn, r2.mn);
		return ans;
	}

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
		vector<seg> sg;
		for (int i = 0; i < c + 5; i++)
			sg.push_back(seg(r + 5));
		while (m--) {
			cin >> t >> x1 >> y1 >> x2 >> y2;
			if (t < 3) {
				cin >> v;
				for (int i = y1; i <= y2; i++)
					sg[i].updateRange(1, 1, c, x1, x2, v, t);
			} else {
				Point ans;
				ans.mx = INT_MIN;
				ans.mn = INT_MAX;
				for (int i = y1; i <= y2; i++) {
					Point v = sg[i].getAnswer(1, 1, c, x1, x2);
					ans.sum += v.sum;
					ans.mx = max(ans.mx, v.mx);
					ans.mn = min(ans.mn, v.mn);
				}
				cout << ans.sum << " " << ans.mn << " " << ans.mx << "\n";
			}
		}
	}
	return 0;
}
