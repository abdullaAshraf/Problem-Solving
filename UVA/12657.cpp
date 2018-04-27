/*
 Author: Abdulla Ashraf
 Idea:
 -double linked list
 -first 3 queries can be done in O(1) for the forth one just keep if it is done odd or even number of times
 */

#include <bits/stdc++.h>

using namespace std;

#define l first
#define r second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
const double PI = acos(-1.0);
const double EPS = 1e-9;

typedef long long ll;

const int MOD = 7 + 1e9;
const ll OO = (ll) 1 * 1e9;

pair<int, int> v[100005];

int main() {
	int n, m, tt = 1, t, x, y;
	while (cin >> n >> m) {
		int rev = 0;
		for (int i = 0; i <= n + 2; i++)
			v[i] = mp(i - 1, i + 1);
		while (m--) {
			cin >> t;
			if (t == 4)
				rev = 1 - rev;
			else if (t == 3) {
				cin >> x >> y;
				pair<int, int> h = v[x];
				if (v[x].r == y) {
					v[x].r = v[y].r;
					v[x].l = y;
					v[y].r = x;
					v[y].l = h.l;
				} else if (v[y].r == x) {
					v[x].l = v[y].l;
					v[x].r = y;
					v[y].l = x;
					v[y].r = h.r;
				} else {
					v[x] = v[y];
					v[y] = h;
				}
				v[v[x].l].r = x;
				v[v[x].r].l = x;
				v[v[y].l].r = y;
				v[v[y].r].l = y;
			} else {
				cin >> x >> y;
				if (rev)
					t = 3 - t;
				v[v[x].r].l = v[x].l;
				v[v[x].l].r = v[x].r;
				if (t == 1) {
					v[x].r = y;
					v[x].l = v[y].l;
					v[v[y].l].r = x;
					v[y].l = x;
				} else {
					v[x].l = y;
					v[x].r = v[y].r;
					v[v[y].r].l = x;
					v[y].r = x;
				}
			}
		}
		ll s = 0;
		if (rev) {
			int c = v[n + 1].l;
			while (c > 0) {
				s += c;
				c = v[v[c].l].l;
			}
		} else {
			int c = v[0].r;
			while (c <= n) {
				s += c;
				c = v[v[c].r].r;
			}
		}
		cout << "Case " << tt++ << ": " << s << "\n";
	}
	return 0;
}
