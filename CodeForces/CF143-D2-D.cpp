/*
 Author: Abdulla Ashraf
 Idea:
 -http://codeforces.com/blog/entry/3651
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

int main() {
	cin.sync_with_stdio(0);
	ll n, m;
	cin >> n >> m;
	if (n < m)
		swap(n, m);
	if (m == 1)
		cout << n;
	else if (n == 3 && m == 2)
		cout << 4;
	else if (m == 2)
		cout << 2 * (2 * (n / 4) + min(n % 4, 2ll));
	else
		cout << (n * m + 1) / 2;
	return 0;
}
