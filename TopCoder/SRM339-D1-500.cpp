/*
 Author: Abdulla Ashraf
 Idea:
 -memorize current sum and round
 -we must stroe losing streak as well from 0 to 10
 -2 Basecases , if u reach goal sum return 1,else if u reaced last round or can not pay round value return 0
 -at every point  go to next round with 1 of the 2 following options, increase sum with 2^losing and set losing to 0 , or decrease sum with 2^losing and add 1 to losing
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

int gs;
double pro;
double mem[51][1001][11];
bool v[51][1001][11];

double go(int r, int c, int b) {
	if (c >= gs)
		return 1;
	if (r == 0 || c < (1 << b))
		return 0;
	if (v[r][c][b])
		return mem[r][c][b];
	v[r][c][b] = 1;
	return mem[r][c][b] = pro * go(r - 1, c + (1 << b), 0)
			+ (1 - pro) * go(r - 1, c - (1 << b), b + 1);
}

struct TestBettingStrategy {

	double winProbability(int initSum, int goalSum, int rounds, int prob) {
		gs = goalSum;
		pro = prob / 100.0;
		return go(rounds, initSum, 0);
	}

};
