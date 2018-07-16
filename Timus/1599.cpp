/*
 Author: Abdulla Ashraf
 Idea:
 -https://github.com/AbdelrahmanRamadan/competitive-programming/blob/master/Timus/1599-Winding-Number.cpp
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
#define MAXN (501)
#define MAXC (500 * 499 / 2 + 1)
#define MOD 1000000007

typedef long long ll;

const int N = (1 << 19);
const ll OO = (ll) 1 * 1e9;

struct point {
	int X, Y;
	point operator -(const point & o) const {
		return point( { X - o.X, Y - o.Y });
	}
};

vector<point> v;

long long cross(const point& a, const point& b) {
	return 1LL * a.X * b.Y - 1LL * a.Y * b.X;
}

long long dot(const point & a, const point& b) {
	return 1LL * a.X * b.X + 1LL * a.Y * b.Y;
}

int winding(point p) {
	int wn = 0;
	for (int i = 0, len = v.size(); i < len; ++i) {
		int j = i == (len - 1) ? 0 : (i + 1);
		if (v[i].Y <= p.Y)
			wn += (v[j].Y > p.Y) && cross(v[j] - v[i], p - v[i]) > 0;
		else
			wn -= (v[j].Y <= p.Y) && cross(v[j] - v[i], p - v[i]) < 0;
	}
	return wn;
}

bool pointOnSegment(point a, point b, point p) {
	return !cross(a - p, b - p) && dot(p - a, b - a) >= 0
			&& dot(p - b, a - b) >= 0;
}

int main() {
	int n, q;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].X >> v[i].Y;

	cin >> q;
	while (q--) {
		point p;
		cin >> p.X >> p.Y;
		bool edge = false;
		for (int i = 0; i < n && !edge; ++i) {
			int j = (i + 1) % n;
			edge |= pointOnSegment(v[i], v[j], p);
		}

		if (edge)
			cout << "EDGE\n";
		else
			cout << winding(p) << "\n";
	}
	return 0;
}
