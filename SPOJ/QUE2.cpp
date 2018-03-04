/*
 Author: Abdulla Ashraf
 Idea:
 -sort the people depending on their height then start assigning them from the shortest
 -for every number we need to assign it to the kth first clear place
 -use segmant tree to get the kth free place in logn for each number
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

const int N = (1 << 14);
const ll OO = (ll) 1 * 1e18;
const ll mod = 1e9 + 7;

int tree[2 * N];
void build(int cur, int l, int r) {
	if (l == r) {
		tree[cur] = 1;
		return;
	}
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;
	build(left, l, mid);
	build(right, mid + 1, r);
	tree[cur] = tree[left] + tree[right];
}

int update(int cur, int l, int r, int ind) {
	if (l == r) {
		tree[cur] = 0;
		return l;
	}
	int left = 2 * cur;
	int right = 2 * cur + 1;
	int mid = (l + r) / 2;
	int v;
	if (tree[left] >= ind)
		v = update(left, l, mid, ind);
	else
		v = update(right, mid + 1, r, ind - tree[left]);
	tree[cur] = tree[left] + tree[right];
	return v;
}

int res[N], a[N];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<pair<int, int>> x(n);
		for (int i = 0; i < n; i++)
			cin >> x[i].first;
		for (int i = 0; i < n; i++)
			cin >> x[i].second;
		sort(x.begin(), x.end());
		memset(a, 0, sizeof a);
		for (int i = n - 1; i > 0; i--)
			if (x[i].first == x[i - 1].first)
				a[i - 1] = a[i] + 1;
		build(1, 1, N);
		for (int i = 0; i < n; i++)
			res[update(1, 1, N, n - i  - a[i] - x[i].second)] = x[i].first;
		for(int i=n; i>0; i--)
			cout << res[i] << " ";
		cout << "\n";
	}
	return 0;
}
