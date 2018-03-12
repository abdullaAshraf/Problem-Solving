/*
 Author: Abdulla Ashraf
 Idea:
 -memorize number of remaining subcomponents x (0,1000) and number of remaining Catogries y (0,1000)
 -go(x,y) = ((x/n * (s-y)/s) * go(x-1,y) + (y/s * (n-x)/n) * go(x,y-1) + (y/s * x/n) * go(x-1,y-1) + 1) /(1-(s-y)/s * (n-x)/n)
 */

#include <iostream>
#include <iomanip>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const double EPS = 1e-9;

const int N = (1 << 14);
const int OO = (ll) 1 * 1e9;
const ll mod = 1e9 + 7;

double n, s;
bool vis[1001][1001];
double mem[1001][1001];

double go(int x, int y) {
	if (x < 0 || y < 0)
		return 0;
	if (x == 0 && y == 0)
		return 0;
	double &ret = mem[x][y];
	if (vis[x][y])
		return ret;
	vis[x][y] = 1;
	return ret = ((x/n * (s-y)/s) * go(x-1,y) + (y/s * (n-x)/n) * go(x,y-1) + (y/s * x/n) * go(x-1,y-1) + 1) /(1-(s-y)/s * (n-x)/n);
}

int main() {
	cin >> n >> s;
	cout << fixed << setprecision(4) << go(n - 1, s - 1) + 1;
	return 0;
}
