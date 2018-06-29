/*
 Author: Abdulla Ashraf
 Idea:
 -for every number check in it ancestors for the first one that can remove it and maximize the time
 -calculate the time using a stack to detect time between every possible ancestor and remove the smaller if 2 will get to a point at the same time
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

int main() {
	cin.sync_with_stdio(0);
	int n, mx = 0, a;
	stack<pair<int, int>> x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		while (!x.empty())
			if (x.top().first > a) {
				mx = max(mx, x.top().second);
				break;
			} else {
				x.pop();
				if (x.size()) {
					while (x.size() > 1) {
						pair<int, int> t = x.top();
						x.pop();
						if (x.top().second > t.second) {
							x.push(t);
							break;
						}
					}
					x.top().second++;
				}
			}
		x.push(mp(a, 1));
	}
	cout << mx;
	return 0;
}
