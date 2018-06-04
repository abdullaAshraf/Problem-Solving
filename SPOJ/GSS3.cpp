/*
 Author: Abdulla Ashraf
 Idea:
 -
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

ll arr[N + 2];
ll mx[2 * N], mxl[2 * N], mxr[2 * N], sum[2 * N];

struct node {
	ll mx, mxl, mxr, sum;
	node(ll a, ll b, ll c, ll d) :
			mx(a), mxl(b), mxr(c), sum(d) {

	}
};

void push(int cur) {
	int left = 2 * cur;
	int right = 2 * cur + 1;
	mxl[cur] = max(mxl[left], sum[left] + mxl[right]);
	mxr[cur] = max(mxr[right], sum[right] + mxr[left]);
	sum[cur] = sum[left] + sum[right];
	mx[cur] = max(mxr[left] + mxl[right], max(mx[left], mx[right]));
}

void build(int cur, int l, int r) {
	if (l == r) {
		mx[cur] = mxl[cur] = mxr[cur] = sum[cur] = arr[l];
		return;
	}
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	push(cur);
}

void update(int cur, int l, int r, int x, int v) {
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;

	if (l > x || r < x)
		return;

	if (l == r) {
		mx[cur] = mxl[cur] = mxr[cur] = sum[cur] = v;
		return;
	}

	update(left, l, mid, x, v);
	update(right, mid + 1, r, x, v);
	push(cur);
}

node getAnswer(int cur, int l, int r, int x, int y) {
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;

	if (y < l || x > r)
		return node(-OO, -OO, -OO, -OO);
	if (l >= x && r <= y)
		return node(mx[cur], mxl[cur], mxr[cur], sum[cur]);

	node r1 = getAnswer(left, l, mid, x, y);
	node r2 = getAnswer(right, mid + 1, r, x, y);
	node ans = node(0, 0, 0, 0);
	ans.mxl = max(r1.mxl, r1.sum + r2.mxl);
	ans.mxr = max(r2.mxr, r2.sum + r1.mxr);
	ans.sum = r1.sum + r2.sum;
	ans.mx = max(r1.mxr + r2.mxl, max(r1.mx, r2.mx));
	return ans;
}

int main() {
	cin.sync_with_stdio(0);
	int n, q, t, a, b;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);
	cin >> q;
	while (q--) {
		cin >> t >> a >> b;
		if (t) {
			if (a > b)
				swap(a, b);
			cout << getAnswer(1, 1, n, a, b).mx << "\n";
		} else
			update(1, 1, n, a, b);
	}
	return 0;
}
