/*
 Author: Abdulla Ashraf
 Idea:
 -sort using l[i]*p[i]/(1-p[i]) in decreasing order to get optimal order for max expected value
 -use dp returning 2 values (expected so far , repeat expected value)
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
#define MAXN (101)
#define MAXC (500 * 499 / 2 + 1)

typedef long long ll;
typedef complex<double> point;
#define X real()
#define Y imag()

const int N = (1 << 19);
const int OO = 1 * 1e9;

int n;
vector<pair<int, int>> p;
double x[50000], y[50000];

pair<double, double> go(int in) {
	if (in == n)
		return mp(0, 0);
	if (x[in] - EPS >= 0)
		return mp(x[in], y[in]);
	pair<double, double> v = go(in + 1);
	double rep = v.nd + ((100 - p[in].nd) / 100.0);
	double exp = v.st + p[in].st * (v.nd + 1) * (p[in].nd / 100.0)
			+ p[in].st * ((100 - p[in].nd) / 100.0);
	return mp(exp, rep);
}

int main() {
	for (int i = 0; i < 50000; i++)
		x[i] = -1;
	cin >> n;
	p.resize(n);

	for (int i = 0; i < n; i++)
		cin >> p[i].st >> p[i].nd;

	sort(p.begin(), p.end(), [](pair<int, int> l, pair<int, int> r) {
		double lp = l.nd/100.0, rp = r.nd/100.0;
		return l.st*lp/(1-lp) > r.st*rp/(1-rp);
	});
	cout << fixed << setprecision(9) << go(0).st;
	return 0;
}


