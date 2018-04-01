/*
 Author: Abdulla Ashraf
 Idea:
  -since x is 4*10^4 we can use an easy simulation
  -at every point max of 2 circles can be there but to make easier implemtaion I will use vector
  -make an array of vector of size 4*10^4
  -get every circle and add it's id to the vector of point from c-r to c+r shifted by 2*10^4 to avoid negative index
  -make array ans and set it to -1 and func to get distance and compare it with radius
  -for every point use it's X to get to the right vector and then check the distance for every circle inside that vector and set value in ans if it's -1
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

int ans[10005], c[10005], r[10005];
vector<int> s[50000];
int sf = 20005;

bool dis(int x, int y, int in) {
	return y * y + (x - c[in]) * (x - c[in]) <= r[in] * r[in];
}

int main() {
	memset(ans, -1, sizeof ans);
	int n, m, x, y, cn = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> r[i];
		for (int j = c[i] - r[i]; j <= c[i] + r[i]; j++)
			s[j + sf].pb(i);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		for (auto it : s[x + sf])
			if (ans[it] == -1 && dis(x, y, it))
				ans[it] = i, cn++;
	}
	cout << cn << "\n";
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	return 0;
}
