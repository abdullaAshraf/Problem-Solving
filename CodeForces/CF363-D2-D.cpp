/*
 Author: Abdulla Ashraf
 Idea:
 -binary search for the number of students
 -now to check if x students can have bikes or not we use the x cheapeast bikes and the x most rich boys
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

int n, m, a;
int b[100005], p[100005];

ll ok(int x) {
	ll s = 0;
	for (int i = 0; i < x; i++)
		s += max(0, p[i] - b[x - 1 - i]);
	return s;
}

ll t(int x) {
	ll s = 0;
	for (int i = 0; i < x; i++)
		s += p[i];
	return max(0ll,s - a);
}

int main() {
	cin >> n >> m >> a;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < m; i++)
		cin >> p[i];
	sort(b, b + n, greater<int>());
	sort(p, p + m);
	int l = 0, r = min(n, m) + 1;
	while (r - l > 1) {
		ll m = (r + l) / 2;
		if (ok(m) <= a)
			l = m;
		else
			r = m;
	}
	cout << l << " " << t(l);
	return 0;
}
