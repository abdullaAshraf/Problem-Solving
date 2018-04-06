/*
 Author: Abdulla Ashraf
 Idea:
   -use modified segmant tree to smiplify queries to change maximization to set and how many less than to length
   -store min and max value at each range and add simple logic checks to the break and tag conditions
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)
const double EPS = 1e-9;

typedef long long ll;

const int N = (1 << 17);
const ll OO = (ll) 1 * 1e18;

ll mn[N * 2];
ll mx[N * 2];
ll lazy[2 * N];

void propagte(int cur, int l, int r, int left, int right) {
	if (lazy[cur]) {
		mn[cur] = lazy[cur];
		mx[cur] = lazy[cur];
		if (l != r) {
			lazy[left] = lazy[cur];
			lazy[right] = lazy[cur];
		}
		lazy[cur] = 0;
	}
}

void updateRange(int cur, int l, int r, int x, int y, ll val) {
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;

	propagte(cur, l, r, left, right);

	if (l > y || x > r || mn[cur] >= val)
		return;

	if (l >= x && r <= y && mx[cur] <= val) {
		//cout << "up" << l << " " << r << "  " << mx[cur] << " " << mn[cur] << endl;
		lazy[cur] = val;
		propagte(cur, l, r, left, right);
		return;
	}

	updateRange(left, l, mid, x, y, val);
	updateRange(right, mid + 1, r, x, y, val);
	mn[cur] = min(mn[left], mn[right]);
	mx[cur] = max(mx[left], mx[right]);
}

ll getAnswer(int cur, int l, int r, int x, int y, ll v) {
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;

	propagte(cur, l, r, left, right);

	if (y < l || x > r || mn[cur] > v)
		return 0;
	if (l >= x && r <= y && mx[cur] <= v) {
		//cout << "ret" <<  l << " " << r << "  " << mx[cur] << " " << mn[cur] << endl;
		return r - l + 1;
	}

	ll res1 = getAnswer(left, l, mid, x, y, v);
	ll res2 = getAnswer(right, mid + 1, r, x, y, v);
	return res1 + res2;
}

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		int ans = 0, a, b, c;
		memset(mn, 0, sizeof mn);
		memset(mx, 0, sizeof mx);
		memset(lazy, 0, sizeof lazy);
		while (n--) {
			cin >> a >> b >> c;
			b--;
			ans += getAnswer(1, 1, N, a, b, c);
			updateRange(1, 1, N, a, b, c);
		}
		cout << ans << "\n";
	}
	return 0;
}
