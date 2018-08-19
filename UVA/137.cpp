/*
 Author: Abdulla Ashraf
 Idea:
 -https://github.com/osamahatem/CompetitiveProgramming/blob/master/UVA/137%20-%20Polygons.cpp
 */

#include <bits/stdc++.h>

using namespace std;

#define cross(A,B) ((A).x*(B).y-(A).y*(B).x)
#define VEC(a,b) ((b)-(a))
#define EPS 1e-9
#define mk make_pair
#define fi first
#define se second

typedef long double myf;

struct point {
	myf x, y;

	point() :
			x(0), y(0) {
	}
	point(myf _x, myf _y) :
			x(_x), y(_y) {
	}

	friend bool operator ==(const point& A, const point& B) {
		return fabsl(A.x - B.x) < EPS && fabsl(A.y - B.y) < EPS;
	}

	friend point operator *(const point& A, const myf& sc) {
		return point(A.x * sc, A.y * sc);
	}

	friend point operator +(const point& A, const point& B) {
		return point(A.x + B.x, A.y + B.y);
	}

	friend point operator -(const point& A, const point& B) {
		return point(A.x - B.x, A.y - B.y);
	}
};

pair<point, int> llIntersect(const point& A0, const point& A1, const point& B0,
		const point& B1) {
	myf s = cross(A0 - B0, A1 - A0) / cross(B1 - B0, A1 - A0);
	return pair<point, int>(B0 + (B1 - B0) * s, isnan(s) + isinf(s) * 2);
}

vector<point> polygonCut(const vector<point>& pnts, const point& A,
		const point& B) {
	int sz = pnts.size();
	vector<point> ret;
	for (int i = 0; i < sz; ++i) {
		int j = (i + 1) * (i < sz - 1);
		bool in1 = cross(VEC(A, B), VEC(A, pnts[i])) > EPS;
		bool in2 = cross(VEC(A, B), VEC(A, pnts[j])) > EPS;
		if (in1)
			ret.push_back(pnts[i]);
		if (in1 ^ in2) {
			auto r = llIntersect(pnts[i], pnts[j], A, B);
			if (ret.empty() || !(ret.back() == r.fi))
				ret.push_back(r.fi);
		}
	}
	if (!ret.empty() && ret.back() == ret.front())
		ret.pop_back();
	return ret;
}

vector<point> convexPolygonIntersect(const vector<point>& p,
		const vector<point>& q) {
	vector<point> res = q;
	int sz = p.size();
	for (int i = 0; i < sz; i++) {
		int j = (i + 1) % sz;
		res = polygonCut(res, p[i], p[j]);
		if (res.empty())
			return res;
	}
	return res;
}

myf polygonArea(const vector<point>& pnts) {
	int sz = pnts.size();
	myf area = 0;
	for (int i = 0; i < sz; ++i)
		area += cross(pnts[i], pnts[(i + 1) * (i < sz - 1)]);
	return fabsl(area * 0.5L);
}

int main() {
	cout << fixed << setprecision(2);

	int n, m;
	vector<point> p, q;
	while (cin >> n && n) {
		p.resize(n);
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		cin >> m;
		q.resize(m);
		for (int i = 0; i < m; i++)
			cin >> q[i].x >> q[i].y;
		reverse(p.begin(), p.end());
		reverse(q.begin(), q.end());
		if (q.size() < p.size())
			swap(p, q);
		vector<point> u = convexPolygonIntersect(p, q);
		cout << setw(8)
				<< polygonArea(p) + polygonArea(q) - 2.0L * polygonArea(u);
	}
	cout << endl;
	return 0;
}
