/*
 Author: Abdulla Ashraf
 Idea:
 -split the total distance by k-1 to know the space between every two treea
 -loop over the road and put tree every space u calculated before
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

typedef complex<double> point;

#define X real()
#define Y imag()

double dist(point a, point b) {
	return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}

point p[105];

int main() {
	int T, n, k;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cout << "Road #" << tt << ":\n";
		cin >> n >> k;
		double x, y;
		cin >> x >> y;
		p[0] = point(x, y);
		double sum = 0;
		for (int i = 1; i < n; i++) {
			cin >> x >> y;
			p[i] = point(x, y);
			sum += dist(p[i], p[i - 1]);
		}
		sum /= (k - 1);
		cout << fixed << setprecision(2) << p[0].X << " " << p[0].Y << "\n";
		double r = sum;
		for (int i = 1; i < n; i++) {
			while (dist(p[i], p[i - 1]) + EPS >= r) {
				double t = r / dist(p[i], p[i - 1]);
				double xx = p[i - 1].X + t * (p[i].X - p[i - 1].X);
				double yy = p[i - 1].Y + t * (p[i].Y - p[i - 1].Y);
				cout << xx << " " << yy << "\n";
				p[i - 1] = point(xx, yy);
				r = sum;
			}
			r -= dist(p[i], p[i - 1]);
		}
		cout << "\n";
	}
	return 0;
}
