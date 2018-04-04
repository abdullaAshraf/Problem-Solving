/*
 Author: Abdulla Ashraf
 Idea:
  -since it is guaranteed that the ball hits the door there is no infinte case
  -and since all numbers are integers the ball will move at least 1 step forward towards the door at each step
  -notice that max values are 100 then we can assume simulating the ball movement as brute force will give the answer in short time
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)
const double EPS = 1e-9;

typedef long long ll;

const int N = 10005;

struct point {
	double x, y, z;
	point(double x = 0, double y = 0, double z = 0) :
			x(x), y(y), z(z) {
	}
	point operator -(point other) {
		return point(x - other.x, y - other.y, z - other.z);
	}
	point operator +(point other) {
		return point(x + other.x, y + other.y, z + other.z);
	}
	point operator *(point other) {
		return point(y * other.z - z * other.y, z * other.x - x * other.z,
				x * other.y - y * other.x);
	}

	double dot(point other) {
		return x * other.x + y * other.y + z * other.z;
	}
	point operator *(double f) {
		return point(x * f, y * f, z * f);
	}

};

struct plane {
	point n; // normal
	double d; // distance from origin

	plane();
	plane(point n, double d) :
			n(n), d(d) {
	}
	point intersectLine(point a, point v) {
		double nDotA = n.dot(a);
		double nDotBA = n.dot(v);

		return a + (v * ((d - nDotA) / nDotBA));
	}
};

point dir(point v, point n) {
	if (n.x == 1)
		v.x *= -1;
	else if (n.y == 1)
		v.y *= -1;
	else
		v.z *= -1;
	return v;
}

int main() {
	double a, b, m;
	point v, c;
	cin >> a >> b >> m;
	c.x = a / 2, c.y = m;
	cin >> v.x >> v.y >> v.z;
	plane dr = plane(point(0, 1, 0), 0), rw = plane(point(1, 0, 0), 0), lw =
			plane(point(1, 0, 0), a), cl = plane(point(0, 0, 1), b), fl = plane(
			point(0, 0, 1), 0);
	while (true) {
		//cout << c.x << " " << c.y << " " << c.z << endl;
		//cout << v.x << " " << v.y << " " << v.z << endl;
		if (dr.intersectLine(c, v).x > a) {
			if (lw.intersectLine(c, v).z < 0) {
				c = fl.intersectLine(c, v);
				v = dir(v, fl.n);
			} else if (lw.intersectLine(c, v).z > b) {
				c = cl.intersectLine(c, v);
				v = dir(v, cl.n);
			} else {
				c = lw.intersectLine(c, v);
				v = dir(v, lw.n);
			}
		} else if (dr.intersectLine(c, v).x < 0) {
			if (rw.intersectLine(c, v).z < 0) {
				c = fl.intersectLine(c, v);
				v = dir(v, fl.n);
			} else if (rw.intersectLine(c, v).z > b) {
				c = cl.intersectLine(c, v);
				v = dir(v, cl.n);
			} else {
				c = rw.intersectLine(c, v);
				v = dir(v, rw.n);
			}
		} else if (dr.intersectLine(c, v).z < 0) {
			c = fl.intersectLine(c, v);
			v = dir(v, fl.n);
		} else if (dr.intersectLine(c, v).z > b) {
			c = cl.intersectLine(c, v);
			v = dir(v, cl.n);
		} else {
			c = dr.intersectLine(c, v);
			v = dir(v, dr.n);
			break;
		}
	}
	cout << fixed << setprecision(10) << c.x << " " << c.z;
	return 0;
}
