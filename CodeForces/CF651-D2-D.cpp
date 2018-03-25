/*
 Author: Abdulla Ashraf
 Idea:
 -we can not use dp , try to find a greedy approach
 -since we can not skip images we can only go to right till some point and to the left till some point
 -calculate cumlitve time required to reach every point to the right , then move to the left while using binary search to find the point to the right
 -moving on a watched photo doesnot take watching or rotating time but it takes flipping time
 -now we need to handle going forward then backward and vice versa
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
const double PI = acos(-1.0);
const double EPS = 1e-9;

vector<ll> x, y;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n, a, b, t;
	string s;
	cin >> n >> a >> b >> t >> s;
	x.resize(n);
	y.resize(n);
	x[0] = y[0] = 1;
	if (s[0] == 'w')
		y[0] = x[0] += b;
	for (int i = 1; i < n; i++) {
		x[i] = x[i - 1] + 1 + a;
		y[i] = y[i - 1] + 1 + 2 * a;
		if (s[i] == 'w') {
			x[i] += b;
			y[i] += b;
		}
	}
	if (t >= x[n - 1]) {
		cout << n;
		return 0;
	}
	ll ss = 0, ss2 = 0;
	int mx = 0;
	for (int i = n - 1; i >= 0 && ss <= t; i--) {
		auto it = lower_bound(x.begin(), x.end(), t - ss2 + 1);
		auto it2 = lower_bound(y.begin(), y.end(), t - ss + 1);
		if (it > x.begin())
			mx = max(mx, n - 1 - i + (int) (it - x.begin()));
		if (it2 > y.begin())
			mx = max(mx, n - 1 - i + (int) (it2 - y.begin()));
		ss += 1 + a;
		ss2 += 1 + 2 * a;
		if (s[i] == 'w') {
			ss += b;
			ss2 += b;
		}
	}
	cout << mx;
	return 0;
}
