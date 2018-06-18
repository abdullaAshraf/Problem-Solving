/*
 Author: Abdulla Ashraf
 Idea:
 -just loop over segments and rectangles and check for required output
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
const int N = (1 << 19);
const ll OO = (ll) 1 * 1e18;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))

vector<int> cnt(2);
typedef complex<double> point;

bool intersectSegments(point a, point b, point c, point d) {
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	if (fabs(d1) < EPS)
		return false;

	double t1 = d2 / d1, t2 = d3 / d1;

	if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS || t1 > 1 + EPS)
		return false;
	return true;
}

struct seg {
	int x1, y1, x2, y2;
	seg(int x1, int y1, int x2, int y2) :
			x1(x1), y1(y1), x2(x2), y2(y2) {
	}
};

struct rect {
	int x1, y1, x2, y2, a;
	rect(int x1, int y1, int x2, int y2) :
			x1(x1), y1(y1), x2(x2), y2(y2) {
		a = (x2 - x1) * (y2 - y1);
	}
	bool ins(int x, int y) {
		return x > x1 && x < x2 && y > y1 && y < y2;
	}
	bool inter(seg s) {
		return intersectSegments(point(s.x1, s.y1), point(s.x2, s.y2),
				point(x1, y1), point(x1, y2))
				|| intersectSegments(point(s.x1, s.y1), point(s.x2, s.y2),
						point(x2, y1), point(x2, y2))
				|| intersectSegments(point(s.x1, s.y1), point(s.x2, s.y2),
						point(x1, y1), point(x2, y1))
				|| intersectSegments(point(s.x1, s.y1), point(s.x2, s.y2),
						point(x1, y2), point(x2, y2));
	}
};

vector<seg> s;

struct RectangleCrossings {

	vector<int> countAreas(vector<string> rectangles, vector<string> segments) {

		for (auto it : segments) {
			stringstream ss(it);
			int a, b, c, d;
			ss >> a >> b >> c >> d;
			s.pb(seg(a, b, c, d));
		}

		for (auto it : rectangles) {
			stringstream ss(it);
			int a, b, c, d;
			ss >> a >> b >> c >> d;
			rect r = rect(a, b, c, d);
			bool f = 0;
			for (auto it2 : s)
				if (r.ins(it2.x1, it2.y1) || r.ins(it2.x2, it2.y2)) {
					f = 1;
					cnt[0] += r.a;
					break;
				}
			if (!f) {
				for (auto it2 : s)
					if (r.inter(it2)) {
						cnt[1] += r.a;
						break;
					}
			}
		}
		return cnt;
	}

};
