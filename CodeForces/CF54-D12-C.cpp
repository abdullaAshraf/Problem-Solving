/*
 Author: Abdulla Ashraf
 Idea:
 -memeorize mem[n][n] we stop when in == n and return 1 if second value/n >= k and 0 otherwise
 -at every state we check how many numbers starts with 1 and multiplay that with go(in+1,v+1) , and the 1-those * go(in+1,v)
 -to calculate the number of number starting with 1 in a range we can do a loop over numbers digets values or use a preprocssing to get rid of that 18 loop at worst case
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

int n, k;
bool vis[1001][1001];
double mem[1001][1001];
double prob[1001];
ll one[20], a, b;

double go(int in, int v) {
	if (in == n) {
		if (v >= k)
			return 1;
		return 0;
	}
	double &ret = mem[in][v];
	if (vis[in][v])
		return ret;
	vis[in][v] = 1;
	return ret = prob[in] * go(in + 1, v + 1) + (1 - prob[in]) * go(in + 1, v);
}

int numofD(ll x) {
	int c = 0;
	while (x) {
		x /= 10;
		c++;
	}
	return c;
}

int main() {
	memset(vis, 0, sizeof vis);
	cin >> n;
	for (int j = 0; j < n; j++) {
		cin >> a >> b;
		ll k = 1, v = 1;
		for (int i = 1; i <= 19; i++, k = k * 10 + 9, v *= 10)
			if (numofD(a) <= i) {
				if (numofD(a) == i) {
					if (k >= a)
						prob[j] += min(b, k) - a + 1;
				} else if (numofD(b) == i)
					prob[j] += min(b, k) - v + 1;
				else if (numofD(b) < i)
					break;
				else
					prob[j] += v;
			}
		prob[j] /= b - a + 1;

	}
	cin >> k;
	k = (k * n + 99) / 100;
	cout << fixed << setprecision(12) << go(0, 0);
	return 0;
}
