/*
 Author: Abdulla Ashraf
 Idea:
 -sort on one paramter desc
 -loop and for each one add axes that match that paramter to a set
 -use binary search to pick the lowest one on 2nd paramter that fits
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

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int a[2000005], b[200005], in[200005], ans[200005];

int main() {
	int n, m, u, v;
	cin >> n;
	iota(in, in + n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	sort(in, in + n, [](int l , int r) {
		return a[l] > a[r];
	});
	cin >> m;
	vector<pair<int, pair<int, int>>> x;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		x.pb(mp(i + 1, mp(u, v)));
	}
	sort(x.begin(), x.end(),
			[](pair<int, pair<int, int>> l , pair<int, pair<int, int>> r) {
				return l.nd.st > r.nd.st;
			});
	set<pair<int, int>> q;
	int p = 0;
	for (int i = 0; i < n; i++) {
		while (p < x.size() && x[p].nd.st >= a[in[i]]) {
			q.insert(mp(x[p].nd.nd, x[p].st));
			p++;
		}
		if (q.empty()) {
			cout << -1;
			return 0;
		}
		auto it = q.lower_bound(mp(b[in[i]], 0));
		if (it == q.end()) {
			cout << -1;
			return 0;
		}
		ans[in[i]] = (*it).nd;
		q.erase(it);
	}
	for(int i=0; i<n; i++)
		cout << ans[i] << " ";
}
