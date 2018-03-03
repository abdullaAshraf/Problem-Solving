/*
 Author: Abdulla Ashraf
 Idea:
 -use a dp recurance here every time we split the array into 2 parts and we calculate each one then multiplay them
 -keep left & right to know the current set we are trying to solve and return the number of multiplaction done so far
 -base case when we have 1 matrix return 0
 -every time we loop over the array and try to split at each point with the cost go(left,mid) + go(mid+1,right) + left.x * right.y * mid.y and we minimize on them
 -after we done with the number we do another recusive function to trace the dp and get the path we used
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

const int N = (1 << 18);
const ll OO = (ll) 1 * 1e18;
const ll mod = 1e9 + 7;

int n, t = 1;
ll mem[10][10];
ll x[10], y[10];
ll go(int l, int r) {
	if (l == r)
		return 0;
	ll &ret = mem[l][r];
	if (ret != -1)
		return ret;
	ret = OO;
	for (int i = l; i < r; i++)
		ret = min(ret, go(l, i) + go(i + 1, r) + x[l] * y[i] * y[r]);
	return ret;
}

string trace(int l, int r) {
	if (l == r)
		return "A" + to_string(l+1);
	ll ret = mem[l][r];
	for (int i = l; i < r; i++)
		if (ret == go(l, i) + go(i + 1, r) + x[l] * y[i] * y[r])
			return "(" + trace(l, i) + " x " + trace(i + 1, r) + ")";
	return "none";
}

int main() {
	while (scanf("%d", &n) && n) {
		printf("Case %d: ", t++);
		memset(mem, -1, sizeof mem);
		for (int i = 0; i < n; i++)
			scanf("%d %d", x + i, y + i);
		go(0, n - 1);
		printf("%s\n",trace(0,n-1).c_str());
	}
	return 0;
}
