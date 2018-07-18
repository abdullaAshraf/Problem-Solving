/*
 Author: Abdulla Ashraf
 Idea:
 -https://github.com/MeGaCrazy/CompetitiveProgramming/blob/ff934b5231a55818d401805db5e0caa0720a1fa4/Codeforces/CF801-D2-D.cpp
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
#define MAXN (41)
#define MAXC (500 * 499 / 2 + 1)
#define MOD 1000000007

typedef long long ll;
typedef complex<double> point;
#define X real()
#define Y imag()

const int N = (1 << 19);
const int OO = 1 * 1e9;


#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

int dcmp(double x, double y) {
	return fabs(x - y) < EPS ? 0 : x > y ? 1 : -1;
}

double toDegreeFromMinutes(double minutes) {
	return (minutes / 60);
}
double toRad(double deg) {
	return (deg * PI / 180.0);
}
double toDegree(double rad) {
	if (rad < 0)
		rad += 2 * PI;
	return rad * 180 / PI;
}

double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}

double getAngle_A_abc(double a, double b, double c) {
	return acos(fixAngle((b * b + c * c - a * a) / (2 * b * c)));
}

//triAreaMedians = 4/3 * triArea
double triArea(double a, double b, double c) {
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

point reflect(point p, point p0, point p1) {
	point z = p - p0, w = p1 - p0;
	return conj(z / w) * w + p0; // Refelect point p1 around p0p1
}

double angleO(point a, point O, point b) {
	point v1(a - O), v2(b - O);
	return acos(fixAngle( dp(v1, v2) / length(v1) / length(v2)));
}

double getAng(point &a, point &b, point &c) // find angle abc, anticlock bc to ba
		{
	double ang = angle( vec(b, c)) - angle(vec(b, a));
	if (dcmp(ang, 0) < 0)
		ang += 2 * PI;
	return ang;
}

bool isCollinear(point a, point b, point c) {
	return fabs(cp(b - a, c - a)) < EPS;
}

bool isPointOnRay(point a, point b, point c) {	// not tested?
	if (!isCollinear(a, b, c))
		return false;
	return dcmp(dp(b - a, c - a), 0) == 1;
}

bool isPointOnSegment(point a, point b, point c) {
	return isPointOnRay(a, b, c) && isPointOnRay(b, a, c);
}

double distToLine(point p0, point p1, point p2) {
	return fabs(cp(p1-p0, p2-p0) / length(p0 - p1)); // area = 0.5*b*h
}

//distance from point p2 to segment p0-p1
double distToSegment(point p0, point p1, point p2) {
	double d1, d2;
	point v1 = p1 - p0, v2 = p2 - p0;
	if ((d1 = dp(v1, v2)) <= 0)
		return length(p2 - p0);
	if ((d2 = dp(v1, v1)) <= d1)
		return length(p2 - p1);
	double t = d1 / d2;
	return length(p2 - (p0 + v1 * t));
}

point p[1005];

int main() {
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		p[i] = point(x, y);
	}
	double dis = 1e18;
	for (int i = 0; i < n; i++) {
		int prv = (i - 1 + n) % n;
		int nxt = (i + 1) % n;
		double tmp = distToSegment(p[prv], p[nxt], p[i]);
		if (dcmp(tmp, dis) == -1)
			dis = tmp;
	}
	cout << fixed << setprecision(10) << dis / 2;
	return 0;
}
