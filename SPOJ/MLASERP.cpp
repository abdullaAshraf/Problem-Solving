/*
 Author: Abdulla Ashraf
 Idea:
 -normal grid min path find but add one when u change direction only
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
const ll OO = (ll) 1 * 1e9;

int w, h, mem[105][105][4];
int sx, sy;
char g[105][105];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int go(int x, int y, int p) {
	if (x < 0 || y < 0 || x == h || y == w || g[x][y] == '*')
		return OO;
	if (g[x][y] == 'C' && (x != sx || y != sy))
		return 0;
	int & ret = mem[x][y][p];
	if (ret != -1)
		return ret;
	ret = OO;
	for (int i = 0; i < 4; i++)
		ret = min(ret, (i != p ? 1 : 0) + go(x + dx[i], y + dy[i], i));
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin >> w >> h;
	memset(mem, -1, sizeof mem);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'C')
				sx = i, sy = j;
		}
	cout << go(sx, sy, -1) - 1;
	return 0;
}
