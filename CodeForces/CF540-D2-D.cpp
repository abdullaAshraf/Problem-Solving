/*
 Author: Abdulla Ashraf
 Idea:
 -dp with probabilty
 -memeorize mem[r][s][p] we stop when one of them reach 0 and consider the one next to it the 100% winner in that state
 -at a state if 2 same people met it won't affect the probabilty so we can ignore it
 -we can return a pair and the 3rd value can be calculated at any point
 -at every state try the state of r-1 and p-1 and s-1 each one multipled by the probabilty of it divided by the totoal porbabilty of 2 different people meeting
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

const int N = (1 << 14);
const int OO = (ll) 1 * 1e9;
const ll mod = 1e9 + 7;

bool vis[101][101][101];
pair<double, double> mem[101][101][101];

pair<double, double> go(int r, int s, int p) {
	if (r == 0)
		return mp(0, 1);
	if (s == 0)
		return mp(0, 0);
	if (p == 0)
		return mp(1, 0);
	pair<double, double> &ret = mem[r][s][p];
	if (vis[r][s][p])
		return ret;
	vis[r][s][p] = 1;
	double sum = r + s + p;
	double pr = r / sum * p / sum, ps = r / sum * s / sum, pp = s / sum * p
			/ sum;
	double pt = pr + ps + pp;
	auto it = go(r - 1, s, p);
	auto it2 = go(r, s - 1, p);
	auto it3 = go(r, s, p - 1);
	return ret = {(pr*it.first + ps*it2.first + pp*it3.first)/pt , (pr*it.second + ps*it2.second + pp*it3.second)/pt};
}

int main() {
	int r, s, p;
	cin >> r >> s >> p;
	memset(vis, 0, sizeof vis) ;
	auto it = go(r, s, p);
	cout << fixed << setprecision(12) << it.first << " " << it.second << " "
			<< 1 - it.first - it.second;
	return 0;
}
