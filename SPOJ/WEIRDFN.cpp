/*
 Author: Abdulla Ashraf
 	 Idea:
 	 	 -iterate over n and get F[i] for every number and sum them we only need a fast way to get median of some numbers
     -use 2 prioirty queues to keep all the pervious numbers and get the median in o(1) add new number in logn
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

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll a, b, c, n, ans = 1, f = 1;
		priority_queue<int, vector<int>, greater<int> > q;
		priority_queue<int> p;
		p.push(1);
		cin >> a >> b >> c >> n;
		for (int i = 2; i <= n; i++) {
			ans += f = (a * p.top() + b * i + c) % mod;
			if (f >= p.top()) {
				q.push(f);
				if (q.size() > p.size()) {
					p.push(q.top());
					q.pop();
				}
			} else {
				p.push(f);
				if (q.size()+1 < p.size()) {
					q.push(p.top());
					p.pop();
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
