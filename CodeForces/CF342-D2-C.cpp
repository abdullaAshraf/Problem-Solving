/*
 Author: Abdulla Ashraf
 Idea:
 -the depth is useless as it will always fit 1 ballon
 -we start from the bottom fill with 2 ballons per level till h is over and calculate how much of the half cycle the last circles took
if they took less than a r - r sin60 we can fit another ballon at top
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const int N = 10005;
const double PI = acos(-1.0);
const double EPS = 1e-9;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int r, h;
	cin >> r >> h;
	double t = r;
	t = (t - t * sqrt(3) / 2.0);
	if ((r - h % r) <= t)
		cout << 3 + 2 * (h / r);
	else if ((r - h % r) <= r / 2.0)
		cout << 2 + 2 *  (h / r);
	else
		cout << 1 + 2 * (h / r);
	return 0;
}
