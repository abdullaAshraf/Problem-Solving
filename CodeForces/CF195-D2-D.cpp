/*
 Author: Abdulla Ashraf
 Idea:
 -loop over the n values, for each one calculate the change point (-b/k)
 -the answer is the number of unique change points
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-9;

const int N = (1 << 18);
const ll OO = (ll) 1 * 1e18;
const ll mod = 1e9 + 7;

int n, c, k, b;

set<pair<int, int>> x;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &k, &b);
		if (k != 0) {
			if (b == 0) {
				x.insert(mp(0, 0));
				continue;
			}
			int t = __gcd(abs(k), abs(b));
			int r = (k / abs(k)) * (b / abs(b));
			x.insert(mp(r * abs(b) / t, abs(k) / t));
		}
	}
	cout << x.size();
	return 0;
}
