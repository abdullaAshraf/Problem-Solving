/*
 Author: Abdulla Ashraf
 	 Idea:
     -do not care about numbers only , odd , even or missing
     -odd sum = odd number of odd numbers in every consecutive n numbers in a column and every consecutive m numbers in a row
     -every m numbers in a row must follow the same pattern of odds & evens, so we can check possibilities for only the first m number
     -for every number in the first m we can check the whole (w / m) number that must share the same parity, if they differ some odd some even we get 0 possibilities
     -if all (odd or missing)  or (all even or missing) we get (5 or 4) ^ number of missing  possibilities
     -if all missing we try both
 	 	 -http://d.hatena.ne.jp/komiyam/20110816/1313420655
 	 	 -http://kenkoooo.hatenablog.com/entry/2015/08/26/145748
 	 	 -https://pstopia.github.io/src/tc/srm514d1-2/
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

ll g[NN][NN][2];

ll pat[NN][1 << NN];
ll dp[NN + 1][1 << NN];

struct MagicalGirlLevelTwoDivOne {

	int theCount(vector<string> palette, int n, int m) {
		int h = palette.size(), w = palette[0].length();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				g[i][j][0] = g[i][j][1] = 1;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				if (palette[i][j] == '.') {
					g[i % n][j % m][1] = (g[i % n][j % m][1] * 5) % MOD;
					g[i % n][j % m][0] = (g[i % n][j % m][0] * 4) % MOD;
				} else {
					if (palette[i][j] % 2)
						g[i % n][j % m][0] = 0;
					else
						g[i % n][j % m][1] = 0;
				}
			}

		for (int i = 0; i < n; i++) {
			for (int bit = 0; bit < (1 << m); bit++)
				if (__builtin_parity(bit)) {
					pat[i][bit] = 1;
					for (int j = 0; j < m; j++) {
						if ((bit >> j) & 1)
							pat[i][bit] = (pat[i][bit] * g[i][j][1]) % MOD;
						else
							pat[i][bit] = (pat[i][bit] * g[i][j][0]) % MOD;
					}
				}
		}

		dp[0][0] = 1;
		for (int i = 0; i < n; i++)
			for (int bit1 = 0; bit1 < (1 << m); bit1++)
				for (int bit2 = 0; bit2 < (1 << m); bit2++)
					if (__builtin_parity(bit2))
						dp[i + 1][bit1 ^ bit2] = (dp[i + 1][bit1 ^ bit2] + dp[i][bit1] * pat[i][bit2]) % MOD;

		return (int) dp[n][(1 << m) - 1];
	}

};
