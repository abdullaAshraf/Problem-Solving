/*
 Author: Abdulla Ashraf
 Idea:
 -sort points on angel and maximize the angel between every 2 consegative points
 -the answer is 360 - max
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

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	cin.sync_with_stdio(0);
	int n;
	double x, y;
	vector<double> p;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		double a = atan(fabs(y / x)) * 180 / PI;
		if (x < 0 && y >= 0)
			a = 180 - a;
		else if (x < 0)
			a = 180 + a;
		else if (y < 0)
			a = 360 - a;
		p.pb(a);
	}
	sort(p.begin(), p.end());
	double mx;
	if (p.size() == 1)
		mx = 360;
	else
		mx = 360 - (p[p.size() - 1] - p[0]);
	for (int i = 1; i < p.size(); i++)
		mx = max(mx, p[i] - p[i - 1]);
	cout << fixed << setprecision(10) << 360 - mx;
	return 0;
}
