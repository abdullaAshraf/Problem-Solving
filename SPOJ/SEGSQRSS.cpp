/*
 Author: Abdulla Ashraf
 Idea:
 -the sum and set all can be done with normal lazy prop but increase can not be done this simple
 -split the new value to sum of old values, if we added x to range of length l which has sum of s and square sum of ss the new values will be:
    ss = ss + x*x*l + 2*s*x
    s = s+x*l"
 */

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const double EPS = 1e-9;

const int N = (1 << 18);
const ll OO = (ll) 1 * 1e18;
const ll mod = 1e9 + 7;

ll arr[N + 2];
ll s[2 * N], ss[2 * N];
ll lazy[2 * N];
ll se[2 * N];

void build(int cur = 1, int l = 1, int r = N) {
	lazy[cur] = 0;
	se[cur] = 1001;
	if (l == r) {
		s[cur] = arr[l];
		ss[cur] = s[cur] * s[cur];
		return;
	}
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	s[cur] = s[left] + s[right];
	ss[cur] = ss[left] + ss[right];
}

void propagte(int cur, int l, int r, int left, int right) {
	if (se[cur] != 1001) {
		s[cur] = se[cur] * (r - l + 1);
		ss[cur] = se[cur] * se[cur] * (r - l + 1);
		if (l != r) {
			se[left] = se[cur];
			se[right] = se[cur];
			lazy[left] = 0;
			lazy[right] = 0;
		}
		se[cur] = 1001;
	}
	if (lazy[cur] != 0) {
		ss[cur] += lazy[cur] * lazy[cur] * (r - l + 1) + 2 * s[cur] * lazy[cur];
		s[cur] += lazy[cur] * (r - l + 1);
		if (l != r) {
			lazy[left] += lazy[cur];
			lazy[right] += lazy[cur];
		}
		lazy[cur] = 0;
	}
}

void updateRange(int cur, int l, int r, int x, int y, ll val) {
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;

	propagte(cur, l, r, left, right);

	if (l > y || x > r)
		return;

	if (l >= x && r <= y) {
		lazy[cur] += val;
		propagte(cur, l, r, left, right);
		return;
	}

	updateRange(left, l, mid, x, y, val);
	updateRange(right, mid + 1, r, x, y, val);
	s[cur] = s[left] + s[right];
	ss[cur] = ss[left] + ss[right];
}

void setRange(int cur, int l, int r, int x, int y, ll val) {
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;

	propagte(cur, l, r, left, right);

	if (l > y || x > r)
		return;

	if (l >= x && r <= y) {
		lazy[cur] = 0;
		se[cur] = val;
		propagte(cur, l, r, left, right);
		return;
	}

	setRange(left, l, mid, x, y, val);
	setRange(right, mid + 1, r, x, y, val);
	s[cur] = s[left] + s[right];
	ss[cur] = ss[left] + ss[right];
}

ll getAnswer(int cur, int l, int r, int x, int y) {
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;

	propagte(cur, l, r, left, right);

	if (y < l || x > r)
		return 0;
	if (l >= x && r <= y)
		return ss[cur];

	ll res1 = getAnswer(left, l, mid, x, y);
	ll res2 = getAnswer(right, mid + 1, r, x, y);
	return res1 + res2;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int T, n, q, t, l, r, v;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		printf("Case %d:\n", tt);
		cin >> n >> q;
		memset(arr, 0, sizeof arr);
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		build();
		while (q--) {
			cin >> t >> l >> r;
			if (t == 2)
				cout << getAnswer(1, 1, N, l, r) << "\n";
			else if (t == 1) {
				cin >> v;
				updateRange(1, 1, N, l, r, v);
			} else if (t == 0) {
				cin >> v;
				setRange(1, 1, N, l, r, v);
			}
		}
	}
	return 0;
}
