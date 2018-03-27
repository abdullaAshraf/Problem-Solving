/*
 Author: Abdulla Ashraf
 Idea:
 -try to form a square form every 4 point in every possible order and form a rectangle with the other 4 points in every possible order as well
 -use recursion to get all the 4 out of 8 combinations
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const int N = (1 << 18);
const ll OO = (ll) 1 * 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;

typedef complex<long long> point;

#define X real()
#define Y imag()

ll dis(point p1, point p2) {
	return (p1.X - p2.X) * (p1.X - p2.X) + (p1.Y - p2.Y) * (p1.Y - p2.Y);
}

bool IsOrthogonal(point a, point b, point c) {
	return (b.X - a.X) * (b.X - c.X) + (b.Y - a.Y) * (b.Y - c.Y) == 0;
}

bool rect(point a, point b, point c, point d) {
	return IsOrthogonal(a, b, c) && IsOrthogonal(b, c, d)
			&& IsOrthogonal(c, d, a);
}

bool square(point a, point b, point c, point d) {
	return rect(a, b, c, d) && dis(a, b) == dis(a, d);
}

point p[9];
vector<int> ans;
vector<int> pp, pp2;
bool go(int in) {
	if (in == 9) {
		if (pp.size() == 4) {
			bool f = 0;
			do {
				if (square(p[pp[0]], p[pp[1]], p[pp[2]], p[pp[3]]))
					f = 1;
			} while (!f && next_permutation(pp.begin() + 1, pp.end()));
			if (f) {
				f = 0;
				do {
					if (rect(p[pp2[0]], p[pp2[1]], p[pp2[2]], p[pp2[3]]))
						f = 1;
				} while (!f && next_permutation(pp2.begin() + 1, pp2.end()));
				if (f) {
					ans = pp;
					return 1;
				}
			}
		}
		return 0;
	}
	bool ret = 0;
	if (pp2.size() < 4) {
		pp2.pb(in);
		ret = ret || go(in + 1);
		pp2.pop_back();
	}
	if (pp.size() < 4) {
		pp.pb(in);
		ret = ret || go(in + 1);
		pp.pop_back();
	}
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int a, b;
	for (int i = 1; i <= 8; i++) {
		cin >> a >> b;
		p[i] = point(a, b);
	}
	if (go(1)) {
		cout << "YES\n";
		for (auto it : ans)
			cout << it << " ";
		cout << endl;
		for (int i = 1; i < 9; i++)
			if (find(ans.begin(), ans.end(), i) == ans.end())
				cout << i << " ";
	} else
		cout << "NO";
	return 0;
}
