/*
 Author: Abdulla Ashraf
 Idea:
 -use recusrion to try every possible move
 -use char array instead of string to save time
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
#define INF 1000000007

const int mod = 7 + 1e9;
const int N = (1 << 19);
const ll OO = (ll) 1 * 1e9;

char a[200005], b[200005];
int lvl[20];

bool go(int v, int x, int y) {
	if (lvl[v] & 1) {
		for (int i = 0; i < lvl[v]; i++)
			if (a[x + i] != b[y + i])
				return 0;
		return 1;
	}
	return (go(v + 1, x, y) && go(v + 1, x + lvl[v + 1], y + lvl[v + 1]))
			|| (go(v + 1, x, y + lvl[v + 1]) && go(v + 1, x + lvl[v + 1], y));
}

int main() {
	cin.sync_with_stdio(0);
	scanf("%s", a);
	scanf("%s", b);
	lvl[0] = strlen(a);
	for (int i = 1; i < 20; i++) {
		if (lvl[i - 1] & 1)
			break;
		lvl[i] = lvl[i - 1] / 2;
	}
	if (go(0, 0, 0))
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
