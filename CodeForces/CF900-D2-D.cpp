/*
 Author: Abdulla Ashraf
 Idea:
 -https://github.com/MedoN11/CompetitiveProgramming/blob/master/CodeForces/CF450-D2-D.cpp
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

ll pow2(ll n) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 2;
	ll h = pow2(n >> 1);
	h *= h;
	h %= mod;
	if (n & 1)
		h *= 2;
	h %= mod;
	return h % mod;
}

map<int, int> mem;

int go(int x) {
	if (x == 1)
		return 1;
	if (mem.find(x) != mem.end())
		return mem[x];
	ll ret = pow2(x - 1) - 1;
	for (ll i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			ret = (ret - go(i) + mod) % mod;
			if (i * i != x)
				ret = (ret - go(x / i) + mod) % mod;
		}
	return mem[x] = ret;
}

int main() {
	cin.sync_with_stdio(0);
	int x, y;
	cin >> x >> y;
	if (y % x) {
		cout << 0;
		return 0;
	}
	cout << go(y / x);
	return 0;
}
