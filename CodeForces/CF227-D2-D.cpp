/*
 Author: Abdulla Ashraf
 Idea:
    -the largest pile won't be added at all , the next k large piles will be moved once , the next k*k twice and so on
    -use accumlative sum on the sorted piles to know sum of each amount
    -for every k > 1 we will loop max of log k to know the answer
    -handle k == 1 manually 
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

ll a[100005], ss;

int main() {
	ios::sync_with_stdio(false);
	int n, q, k;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++) {
		ss += (i - 1) * a[i];
		a[i] += a[i - 1];
	}
	cin >> q;
	while (q--) {
		cin >> k;
		if (k == 1) {
			cout << ss << " ";
			continue;
		}
		ll s = 0;
		ll l, r = 1, v = 0;
		while (r < n) {
			l = r;
			r = min(r * k + 1, (ll) n);
			v++;
			s += v * (a[r] - a[l]);
		}
		cout << s << " ";
	}
	return 0;
}
