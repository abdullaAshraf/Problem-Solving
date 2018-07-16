/*
 Author: Abdulla Ashraf
 Idea:
 -https://discuss.codechef.com/questions/47247/seaeq-editorial
 -https://www.codechef.com/viewsolution/4325326
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
#define MAXN (501)
#define MAXC (500 * 499 / 2 + 1)
#define MOD 1000000007

typedef long long ll;

const int N = (1 << 19);
const ll OO = (ll) 1 * 1e9;

ll c[MAXN][MAXN], fact[MAXN];

int dp[MAXN][MAXC];

int solve(int n, int e) {
	int total = 0;
	for (int m = n; m >= 1; m--) {
		e = min(e, m * (m - 1) / 2);
		ll cnt = ((((c[n][m] * c[n][m]) % MOD * (fact[n - m] * fact[n - m])
				% MOD) % MOD * (n - m + 1)) % MOD * dp[m][e]) % MOD;
		total = (total + cnt) % MOD;
	}
	return total;
}

int main() {
	c[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
	}

	fact[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = (fact[i - 1] * i) % MOD;

	dp[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < i; j++) {
			int k = min(j, (i - 1) * (i - 2) / 2);
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][k]) % MOD;
		}
		for (int j = i; j <= i * (i - 1) / 2; j++) {
			int k1 = min(j, (i - 1) * (i - 2) / 2);
			int k2 = min(j - i, (i - 1) * (i - 2) / 2);
			dp[i][j] = (dp[i][j - 1]
					+ (dp[i - 1][k1] - dp[i - 1][k2] + MOD) % MOD) % MOD;
		}
	}

	int T, n, e;
	cin >> T;
	while (T--) {
		cin >> n >> e;
		cout << solve(n, e) << "\n";
	}
}
