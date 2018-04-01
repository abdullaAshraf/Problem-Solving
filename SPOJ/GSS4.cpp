/*
 Author: Abdulla Ashraf
 Idea:
  -every number we can take square root for it a limited time untill it become 1
  -so if the range is all 1 we avoid it since no changes will be done, otherwise we split it till we reach the number and change it
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = (1 << 17);
const ll OO = (ll) 1 * 1e18;
ll arr[N + 2];
ll tree[2 * N];
void build(int cur, int l, int r) {
	if (l == r) {
		tree[cur] = arr[l];
		return;
	}
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	tree[cur] = tree[left] + tree[right];
}

void updateRange(int cur, int l, int r, int x, int y) {
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;

	if (l > y || x > r || tree[cur] == (r - l + 1))
		return;

	if (l == r) {
		tree[cur] = floor(sqrt(tree[cur]));
		return;
	}

	updateRange(left, l, mid, x, y);
	updateRange(right, mid + 1, r, x, y);
	tree[cur] = tree[left] + tree[right];
}

ll getAnswer(int cur, int l, int r, int x, int y) {
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;

	if (y < l || x > r)
		return 0;
	if (l >= x && r <= y)
		return tree[cur];

	ll res1 = getAnswer(left, l, mid, x, y);
	ll res2 = getAnswer(right, mid + 1, r, x, y);
	return res1 + res2;
}

int main() {
	cin.sync_with_stdio(0);
	int n, q, t, a, b, c = 1;
	while (cin >> n) {
		cout << "Case #" << c++ << ":\n";
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		build(1, 1, n);
		cin >> q;
		while (q--) {
			cin >> t >> a >> b;
			if (a > b)
				swap(a, b);
			if (t)
				cout << getAnswer(1, 1, n, a, b) << "\n";
			else
				updateRange(1, 1, n, a, b);
		}
		cout << "\n";
	}
	return 0;
}
