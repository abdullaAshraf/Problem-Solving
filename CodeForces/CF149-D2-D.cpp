/*
 Author: Abdulla Ashraf
 Idea:
  -give every bracket pair a number depending on it's first apperance
  -make an array of vectors represent the first level brackets inside each bracket pair
  -assume one big pair numbered 0 include this string
  -add level number to the dp parameters so dp[350][350][2][2]
  -call go(0,0,0,0) which means level 0 , element 0 in it with prev color 0(none) and end color 0(none)
  -since we only want the number the color it self doesn't matter so we can put 0 or 1 for colored or not
  -now at each state go(x,in,c,ec) we have 4 options , 2 can always be done 2*go(x,in+1,1,ec)  and 2 depend on the previous if prev is 0, 2*go(x,in+1,0,ec) if prev is 1 go(x,in+1,0,ec)
  -at the last one if end is colored 1 we return 1 otherwise we return 2
  -at every state multiplay the answer so far by the answer of this bracket level as well if it's not empty
  -take MOD after every opreation and use long long in multiplcation
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
const ll MOD = 1e9 + 7;

vector<int> x[351];
int mem[351][351][2][2];

int go(int lvl, int in, int p, int e) {
	if (in == x[lvl].size())
		return 1;
	int &ret = mem[lvl][in][p][e];
	if (ret != -1)
		return ret;
	ll rs = go(lvl, in + 1, 1, e);
	ll es = go(lvl, in + 1, 0, e);
	if (in + 1 < x[lvl].size() || !e)
		rs += go(lvl, in + 1, 1, e);
	if (!p)
		es += go(lvl, in + 1, 0, e);
	if (x[x[lvl][in]].size()) {
		rs = (rs * go(x[lvl][in], 0, 0, 1)) % MOD;
		es = (es * go(x[lvl][in], 0, 1, 0)) % MOD;
	}
	return ret = (rs + es) % MOD;
}

int main() {
	memset(mem, -1, sizeof mem);
	string s;
	cin >> s;
	int c = 1;
	stack<int> sc;
	sc.push(0);
	for (auto it : s) {
		if (it == '(') {
			x[sc.top()].pb(c);
			sc.push(c++);
		} else
			sc.pop();
	}
	cout << go(0, 0, 0, 0);
	return 0;
}
