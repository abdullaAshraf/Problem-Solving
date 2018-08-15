/*
 Author: Abdulla Ashraf
 Idea:
 -find every last postion a charchtchter can fit in from the front and the first position it can fit in from back
 -if they do not intersect there is no solutaion
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
#define MAXN (101)
#define MAXC (500 * 499 / 2 + 1)

typedef long long ll;
typedef complex<double> point;
#define X real()
#define Y imag()

const int N = (1 << 19);
const int OO = 1 * 1e9;

vector<int> p[24];
int f[200005];

int main() {
	string s, t;
	cin >> s >> t;
	int c = 1;
	for (int i = 0; i < t.length(); i++)
		p[t[i] - 'a'].pb(i + 1);
	for (int i = 0; i < s.length(); i++) {
		int a = s[i] - 'a';
		auto it = lower_bound(p[a].begin(), p[a].end(), c);
		if (p[a].empty() || (*it > c && it == p[a].begin())) {
			cout << "No";
			return 0;
		}
		if (*it == c)
			c++;
		else
			it--;
		f[i] = *it;
	}
	c = t.length();
	for (int i = s.length() - 1; i >= 0; i--) {
		int a = s[i] - 'a';
		auto it = lower_bound(p[a].begin(), p[a].end(), c);
		if (it == p[a].end()) {
			cout << "No";
			return 0;
		}
		if (*it == c)
			c--;
		if (f[i] < *it) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}

