/*
 Author: Abdulla Ashraf
 Idea:
 -use Z-algorthim to determine the allowed postions in the pattern to start a new one by matchin prefix with suffix
 -check if a pattern should start in an invaild postion the answer is 0
 -count the number of free spots for charchter the answer is 26 pow that number
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
#define MAXN (41)
#define MAXC (500 * 499 / 2 + 1)

typedef long long ll;
typedef complex<double> point;
#define X real()
#define Y imag()

const int N = (1 << 19);
const int OO = 1 * 1e9;

void getZarr(string str, int Z[]) {
	int n = str.length();
	int L, R, k;

	L = R = 0;
	for (int i = 1; i < n; ++i) {
		if (i > R) {
			L = R = i;
			while (R < n && str[R - L] == str[R])
				R++;
			Z[i] = R - L;
			R--;
		} else {
			k = i - L;

			if (Z[k] < R - i + 1)
				Z[i] = Z[k];

			else {
				L = i;
				while (R < n && str[R - L] == str[R])
					R++;
				Z[i] = R - L;
				R--;
			}
		}
	}
}

ll pow(ll a, ll b, ll MOD) {
	ll x = 1, y = a;
	while (b > 0) {
		if (b % 2 == 1) {
			x = (x * y);
			if (x > MOD)
				x %= MOD;
		}
		y = (y * y);
		if (y > MOD)
			y %= MOD;
		b /= 2;
	}
	return x;
}

int x[1000005], p[1000005], va[1000005];

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	string s;
	cin >> s;
	int Z[s.length()];
	getZarr(s, Z);
	for (int i = 1; i < s.length(); i++)
		x[Z[i]]++;
	x[s.length() - 1]++;
	for (int i = s.length(); i > 0; i--)
		x[i] += x[i + 1];
	for (int i = s.length() - 1; i > 0; i--)
		if (Z[i] + i == s.length())
			p[i] = 1;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	int ar = 0, v = s.length(), l = 0;
	for (int i = 0; i < m; i++) {
		if (i == 0)
			ar += v;
		else
			ar += v - max(0, (v + a[i - 1]) - a[i]);
		if (va[a[i]]) {
			cout << 0;
			return 0;
		}
		for (int j = max(l, a[i] + 1); j < a[i] + v; j++)
			if (!p[j - a[i]])
				va[j] = 1;

		l = a[i] + v;
	}
	cout << pow(26, n - ar, 1000000007);
	return 0;
}
