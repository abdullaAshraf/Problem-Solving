/*
 Author: Abdulla Ashraf
 Idea:
 -https://github.com/simonlindblad/uva/blob/master/10088.cpp
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
#define INF 1000000007

const int mod = 7 + 1e9;
const int N = (1 << 19);
const ll OO = (ll) 1 * 1e9;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

long long boundary_points(ll x1, ll y1, ll x2, ll y2) {
	return gcd(abs(x2 - x1), abs(y2 - y1));
}

long long points[1001][2];
int n;

long long area() {
	long long area = 0;
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		area += points[i][0] * points[j][1] - points[i][1] * points[j][0];
	}
	return abs(area) / 2;
}

int main() {
	cin.sync_with_stdio(0);
	while (cin >> n && n) {
		for (int i = 0; i < n; i++)
			cin >> points[i][0] >> points[i][1];
		ll sum = 0;
		for (int i = 0; i < n; i++)
			sum += boundary_points(points[i][0], points[i][1],
					points[(i + 1) % n][0], points[(i + 1) % n][1]);
		cout << area() - (sum / 2) + 1 << "\n";
	}
	return 0;
}
