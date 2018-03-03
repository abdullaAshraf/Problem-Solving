/*
 Author: Abdulla Ashraf
 Idea:
 -
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
const int OO = (ll) 1 * 1e9;
const ll mod = 1e9 + 7;

struct seq {
	ll x, y, z;

	seq() :
			x(0), y(0), z(0) {
	}

	seq(int x, int y, int z) :
			x(x), y(y), z(z) {
	}

	bool operator <(const seq & e) const {
		return mp(x, y) > mp(e.x, e.y);
	}

};

int main() {
	string x;
	while (getline(cin, x)) {
		vector<seq> v;
		int f = -1, c = 0;
		priority_queue<seq> p;
		while (x.size() < 3)
			getline(cin, x);
		do {
			stringstream ss(x);
			seq s;
			ss >> s.x >> s.y >> s.z;
			v.pb(s);
			p.push(s);
		} while (getline(cin, x) && x.size() > 3);
		while (p.size() > 1) {
			seq a = p.top();
			p.pop();
			seq b = p.top();
			p.pop();
			if (a.x != b.x) {
				f = a.x;
				break;
			}
			ll t = a.z * b.z / __gcd(a.z, b.z);
			if ((a.y - a.x - a.z) / t
					< (min(a.y, a.x + t - 1) - a.x + a.z) / a.z)
				for (int i = a.x + a.z; i <= a.y / t; i += t)
					p.push(seq(i, min(a.y, i + t - 1), a.z));
			else
				for (int i = a.x + a.z; i <= min(a.y, a.x + t - 1); i += a.z)
					p.push(seq(i, a.y, t));
			if ((b.y - b.x - b.z) / t
					< (min(b.y, b.x + t - 1) - b.x + b.z) / b.z)
				for (int i = b.x + b.z; i <= b.y / t; i += t)
					p.push(seq(i, min(b.y, i + t - 1), b.z));
			else
				for (int i = b.x + b.z; i <= min(b.y, b.x + t - 1); i += b.z)
					p.push(seq(i, b.y, t));
		}
		if (p.size())
			f = p.top().x;
		if (f == -1) {
			puts("no corruption");
			continue;
		}
		for (auto it : v)
			if (f >= it.x && f <= it.y && (f - it.x) % it.z == 0)
				c++;
		printf("%d %d\n", f, c);
	}
	return 0;
}
