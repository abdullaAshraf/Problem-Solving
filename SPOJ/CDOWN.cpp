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
const ll OO = (ll) 1 * 1e9;

int T, n, c, v, k;
vector<int> x[1005];
vector<pair<int, string>> ans;
string its[1005];
map<string, int> sti;
int f[1005];

vector<int> go(int in) {
	vector<int> h(v + 5, 0);
	for (auto it : x[in]) {
		vector<int> g = go(it);
		for (int i = 1; i <= c; i++)
			h[i + 1] += g[i];
	}
	h[1] = 1;
	ans.pb(mp(h[c + 1], its[in]));
	return h;
}
int main() {
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> n >> c;
		for (int i = 0; i < 1005; i++)
			x[i].clear();
		ans.clear();
		sti.clear();
		memset(f, 0, sizeof f);
		string s;
		v = 1;
		for (int i = 0; i < n; i++) {
			cin >> s;
			if (sti.find(s) == sti.end()) {
				sti[s] = v;
				its[v++] = s;
			}
			int p = sti[s];
			cin >> k;
			while (k--) {
				cin >> s;
				if (sti.find(s) == sti.end()) {
					sti[s] = v;
					its[v++] = s;
				}
				x[p].pb(sti[s]);
				f[sti[s]]++;
			}
		}
		cout << "Tree " << tt << ":\n";
		for (int i = 1; i < v; i++)
			if (!f[i])
				go(i);
		sort(ans.begin(), ans.end(),
				[](pair<int, string> l , pair<int, string> r) {
					if(l.first == r.first)
					return l.second < r.second;
					return l.first > r.first;
				});
		for (int i = 0; i < min(3, (int) ans.size()) && ans[i].first > 0; i++)
			cout << ans[i].second << " " << ans[i].first << "\n";
		for (int i = 3;
				i < ans.size() && ans[i].first > 0
						&& ans[i].first == ans[2].first; i++)
			cout << ans[i].second << " " << ans[i].first << "\n";
		if (tt != T)
			cout << "\n";
	}
	return 0;
}
