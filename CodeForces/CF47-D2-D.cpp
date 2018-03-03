/*
 Author: Abdulla Ashraf
 Idea:
    -use recursion to get all valid answers for the first one
    -then use brute force to check for the rest
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

int n, m, a[10];
vector<string> x, v(10);

void go(string h, int t) {
	if (h.size() == n) {
		if (t == a[0])
			x.pb(h);
		return;
	}
	int y = (v[0][h.size()] - '0');
	if (t < a[0])
		go(h + (char)(y + '0'), t + 1);
	if (n + t >= a[0] + h.size())
		go(h + (char)(1 - y + '0'), t);
}

bool match(string r, int u) {
	int s = 0;
	for (int i = 0; i < n; i++)
		if (r[i] == v[u][i])
			if (++s > a[u])
				return 0;
	if (s == a[u])
		return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> v[i] >> a[i];
	go("", 0);
	for (int i = 1; i < m; i++) {
		vector<string> t = x;
		x = vector<string>();
		for (auto it : t)
			if (match(it, i))
				x.pb(it);
	}
	cout << x.size();
	return 0;
}
