/*
 Author: Abdulla Ashraf
 Idea:
 	-sort rules by starting point , in case of tie put shorter end first
	-use dp memorizing the index of point and the number of done rules
	-at each node if we added a wolf here loop over the current rule and keep increasing the number until u found a rule that starts after this point
	-if we did not add a wolf just move to next wit hthe same rule count
	-at anypoint if the end of the rule is shorter than the current index return 0
	-if we reached last index return 1
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

int n, mem[305][55];
vector<pair<int, int>> x;

ll power(ll x, ll y) {
	if (y == 0)
		return 1;
	else if (y % 2 == 0)
		return (power(x, y / 2) * power(x, y / 2)) % MOD;
	else
		return (x * power(x, y / 2) * power(x, y / 2)) % MOD;
}

int go(int in, int r) {
	if (in > n)
		return 1;
	if (x.size() == r)
		return power(2, n - in);
	if (x[r].second < in)
		return 0;
	int & ret = mem[in][r];
	if (ret != -1)
		return ret;
	ret = go(in+1,r);
	while(r <x.size() && x[r].first <= in)
		r++;
	ret += go(in+1,r);
	return ret;
}

struct WolfInZooDivTwo {

	int count(int N, vector<string> L, vector<string> R) {
		n = N;
		memset(mem, -1, sizeof mem);
		for (int i = 0; i < L.size(); i++)
			x.pb(mp(L[i], R[i]));
		sort(x.begin(), x.end());
		return go(1,0);
	}

};
