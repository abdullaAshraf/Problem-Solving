/*
 Author: Abdulla Ashraf
 Idea:
 -
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
const int NN = 10;
const ll MOD = 1e9 + 7;

int c, b;
char un, so;
ll mem[8][101];

ll go(int p, int l) {
	if (p == b)
		return 1;
	ll &ret = mem[p][l];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = l; i <= c; i++)
		ret += go(p + 1, i);
	return ret;
}

ll nCk(ll n, ll k) {
	if (k > n)
		return 0;
	if (k * 2 > n)
		k = n - k;
	if (k == 0)
		return 1;

	int result = n;
	for (int i = 2; i <= k; ++i) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}

ll nPk(ll n, ll k) {
	return n * nPk(n - 1, k - 1);
}

ll power(ll x, ll y) {
	if (y == 0)
		return 1;
	else if (y % 2 == 0)
		return power(x, y / 2) * power(x, y / 2);
	else
		return x * power(x, y / 2) * power(x, y / 2);
}

struct Lottery {

	vector<string> sortByOdds(vector<string> rules) {
		vector<pair<ll, string>> x;
		for (int i = 0; i < rules.size(); i++) {
			string nam = rules[i].substr(0, rules[i].find(':'));
			stringstream s(rules[i].substr(rules[i].find(':') + 1));
			s >> c >> b >> un >> so;
			if (un == 'T' && so == 'T')
				x.pb(mp(nCk(c, b), nam));
			else if (un == 'T' && so == 'F')
				x.pb(mp(nPk(c, b), nam));
			else if (un == 'F' && so == 'F')
				x.pb(mp(power(c, b), nam));
			else {
				memset(mem, -1, sizeof mem);
				x.pb(mp(go(0, 0), nam));
			}
		}
		sort(x.begin(), x.end());
		for (int i = 0; i < rules.size(); i++)
			rules[i] = x[i].first;
		return rules;
	}

};
