/*
 Author: Abdulla Ashraf
 Idea:
 - handle special case k = 1
 - start from every point on x-axis and try every line that passes at least 2 grid points
 - use number if combiation with inverse mod to calcualte the number of possible signals on each line
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

ll f[100001];

ll pow(ll a, ll b, ll MOD) {
	ll x = 1, y = a;
	while (b > 0) {
		if (b % 2 == 1) {
			x = (x * y);
			if (x > MOD)
				x %= MOD;
		}
		y = (y * y);
		if (y > MOD)
			y %= MOD;
		b /= 2;
	}
	return x;
}

ll InverseEuler(ll n, ll MOD) {
	return pow(n, MOD - 2, MOD);
}

ll C(ll n, ll r, ll MOD) {

	return (f[n]
			* ((InverseEuler(f[r], MOD) * InverseEuler(f[n - r], MOD)) % MOD))
			% MOD;
}

void setup() {
	f[0] = 1;
	for (int i = 1; i <= 100000; i++)
		f[i] = (f[i - 1] * i) % INF;
}

int v[205][205];

struct SpacetskE {
	int countsets(int L, int H, int k) {
		setup();
		ll ans = 0;
		if (k == 1)
			return (L + 1) * (H + 1);

		for (int l = 0; l <= L; l++) {
			memset(v, 0, sizeof v);
			for (int i = 1; i <= H; i++)
				for (int j = 0; j <= L; j++)
					if (!v[i][j]) {
						int x = j, y = i, c = 1;
						while (y <= H && x <= L && x >= 0) {
							v[y][x] = 1;
							c++;
							x += j - l;
							y += i;
						}
						if (c >= k)
							ans = (ans+C(c, k, INF))%INF;
					}
		}
		return ans;
	}
};
