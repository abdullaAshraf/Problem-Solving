/*
 Author: Abdulla Ashraf
 Idea:
 -we need to keep the index of current segment and remaining blocks to put and a bool to say if the number of ways so far is odd or even dp[555][555][2]
 -we also need another int to count the number of consegitve clear segments so far MOD 4 and another number for blocks
 -now at every point as long as r is positive we have 2 choices , set next segment as clear or as blocked
    -if we put 2 blocked after each other then there is 0 ways to take this road (even)
    -if we put 3*x clear after each other then we multiplay the number of ways to pass this road so far by 2 which will always make it even"
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
const ll MOD = 555555555;

int n;
ll mem[555][555][5][2];

ll go(int in, int r, int c, int done) {
	if (in == n) {
		if (!r && (done || c == 2))
			return 1;
		return 0;
	}
	ll &ret = mem[in][r][c][done];
	if (ret != -1)
		return ret;
	ret = go(in + 1, r, (c == 4 ? 2 : c + 1), done);
	if (r)
		ret += go(in + 1, r - 1, 0, done || !c || c == 3);
	return ret%MOD;
}

struct MuddyRoad2 {

	int theCount(int N, int muddyCount) {
		n = N;
		memset(mem, -1, sizeof mem);
		return go(2, muddyCount, 1, 0);
	}

};
