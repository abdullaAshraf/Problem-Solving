/*
 Author: Abdulla Ashraf
 Idea:
 -for the graph part using normal dijkstera will solve it, but to count the edge costs we must find shortest path between every 2 polygons
 -to get the shortest distance between 2 polygons we can split this into an easier problem getting the shortest distance between every 2 edges of those polygons
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
const ll OO = (ll) 1 * 1e18;

typedef complex<double> point;

#define X real()
#define Y imag()
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

struct edge {
	int from, to;
	double w;

	edge(int from, int to, double w) :
			from(from), to(to), w(w) {
	}

	bool operator <(const edge & e) const {
		return w > e.w;
	}
};

vector<vector<edge> > x;

double Dijkstra2() {
	int n = sz(x);
	vector<double> dist(n);
	dist[0] = 0;

	for (int i = 1; i < n; i++)
		dist[i] = OO;
	priority_queue<edge> q;
	q.push(edge(-1, 0, 0));

	while (!q.empty()) {
		edge e = q.top();
		q.pop();

		for (int j = 0; j < x[e.to].size(); j++) {
			edge ne = x[e.to][j];
			if (dist[ne.to] > dist[ne.from] + ne.w) {
				ne.w = dist[ne.to] = dist[ne.from] + ne.w;
				q.push(ne);
			}
		}
	}

	return dist[n - 1];
}

vector<vector<point>> g;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int r1, r2, n, k, a, b;
		cin >> r1 >> r2 >> n;
		x.clear();
		g.clear();
		x.resize(n + 2);
		g.resize(n + 2);
		for (int i = 0; i < r1; i++) {
			cin >> a >> b;
			g[0].pb(point(a, b));
		}
		for (int i = 0; i < r2; i++) {
			cin >> a >> b;
			g[n + 1].pb(point(a, b));
		}
		for (int i = 1; i <= n; i++) {
			cin >> k;
			while (k--) {
				cin >> a >> b;
				g[i].pb(point(a, b));
			}
			g[i].pb(g[i][0]);
		}
		for (int i = 0; i < n + 2; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				double c = OO;
				for (int k = 1; k < g[i].size(); k++)
					for (auto it : g[j])
						c = min(c, distToSegment(g[i][k - 1], g[i][k], it));
				for (int k = 1; k < g[j].size(); k++)
					for (auto it : g[i])
						c = min(c, distToSegment(g[j][k - 1], g[j][k], it));
				x[i].pb(edge(i, j, c));
				x[j].pb(edge(j, i, c));
			}
		}
		cout << fixed << setprecision(3) << Dijkstra2() << "\n";
	}
	return 0;
}
