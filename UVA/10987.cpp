/*
 Author: Abdulla Ashraf
 Idea:
  -reverse what you do in floyd and check if it is valid
  -first put all costs and assume that all is connected with a direct edge
  -then if there is a path shorter than the direct link between 2, invalid state
  -if the direct path is shorter we leave it ,if equal remove it
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
const int OO = (ll) 1 * 1e9;
const ll mod = 1e9 + 7;

int g[105][105], e[105][105];
int T, n, c;

int main() {
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		bool f = 0;
		printf("Case #%d:\n", tt);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				e[i][j] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				scanf("%d", &c);
				g[i][j] = g[j][i] = c;
			}
			g[i][i] = 0;
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++) {
					if (g[i][k] + g[k][j] < g[i][j])
						f = 1;

					if (i != k && j != k && g[i][k] + g[k][j] == g[i][j])
						e[i][j] = 0;
				}

		if (f) {
			puts("Need better measurements.\n");
			continue;
		}
		c = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (e[i][j])
					c++;
		printf("%d\n", c);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (e[i][j])
					printf("%d %d %d\n", i, j, g[i][j]);
		puts("");
	}
	return 0;
}
