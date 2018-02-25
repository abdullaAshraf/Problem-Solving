/*
 Author: Abdulla Ashraf
 Idea:
    -try every possible combinations of red and green at each level by using dp loops to reduce time & memory
    -note that by using the current level and one color remiender you can calculate the 2nd one, but I keep it as a value to reduce time required fro calculations
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

int h = 1, d = 1, dp[2][200005], re[2][200005], g, r;

int main() {
	ios::sync_with_stdio(false);
	cin >> r >> g;
	for (int i = 0; i < 200005; i++)
		dp[0][i] = 0;
	dp[0][r] = 1;
	re[0][r] = g;
	bool f = 1;
	for (; f; h++, d ^= 1) {
		f = 0;
		memset(dp[d],0,sizeof dp[d]);
		for (int i = 0; i <= r; i++)
			if (dp[d ^ 1][i]) {
				if (i >= h) {
					dp[d][i - h] = (dp[d][i - h] + dp[d ^ 1][i]) % mod;
					re[d][i - h] = re[d ^ 1][i];
					f = 1;
				}
				if (re[d ^ 1][i] >= h) {
					dp[d][i] = (dp[d][i] + dp[d ^ 1][i]) % mod;
					re[d][i] = re[d ^ 1][i] - h;
					f = 1;
				}
			}
	}
	int s = 0;
	for (int i = 0; i < h; i++)
		s = (s + dp[d][i]) % mod;
	cout << s;
	return 0;
}
