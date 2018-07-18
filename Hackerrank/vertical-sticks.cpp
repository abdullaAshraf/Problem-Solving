/*
 Author: Abdulla Ashraf
 Idea:
 -split the problem and solve for every number sepratly
 -use normal recurssive dp to get expected value
 -at every state u can use a number which will block , won't block or use the number you are calculating for itself
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
#define MOD 1000000007

typedef long long ll;
typedef complex<double> point;
#define X real()
#define Y imag()

const int N = (1 << 19);
const int OO = 1 * 1e9;

int n, arr[1005], c;
bool v[51][51][51];
double mem[51][51][51];

double go(int a, int b, int p) {
	if (!a && !b)
		return n - p;
	if (v[a][b][p])
		return mem[a][b][p];
	v[a][b][p] = 1;
	double &ret = mem[a][b][p];
	ret = n - a - b - p;
	if (a)
		ret += a * go(a - 1, b, p);
	if (b)
		ret += b * go(a, b - 1, n - a - b);

	return ret /= (a + b + 1);
}

int main() {
	int T, t[51];
	cin >> T;
	while (T--) {
		cin >> n;
		memset(arr, 0, sizeof arr);
		for (int i = 0; i < n; i++) {
			cin >> t[i];
			arr[t[i]]++;
		}
		for (int i = 0; i <= 1000; i++)
			arr[i] += arr[i - 1];
		double ans = 0;
		for (int i = 0; i < n; i++) {
			memset(v, 0, sizeof v);
			c = t[i];
			ans += go(arr[c - 1], n - arr[c - 1] - 1, 0);
		}
		cout << fixed << setprecision(2) << ans << "\n";
	}
	return 0;
}
