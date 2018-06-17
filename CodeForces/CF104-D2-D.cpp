/*
 Author: Abdulla Ashraf
 Idea:
 -best odds for the one who starts are 0.5
 -simulate some manual cases and get the pattern
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

int main() {
	cin.sync_with_stdio(0);
	ll n, k, p, a;
	cin >> n >> k >> p;
	if (k == 0) {
		while (p--) {
			cin >> a;
			cout << '.';
		}
		return 0;
	}
	if (n % 2)
		k--, n--;
	ll s = n - k * 2, e = 2 * n - 2 * k;
	while (p--) {
		cin >> a;
		if (a <= n && (a <= s || (a < e && a % 2)))
			cout << '.';
		else
			cout << 'X';
	}
	return 0;
}
