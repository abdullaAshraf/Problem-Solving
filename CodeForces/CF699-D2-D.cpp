/*
 Author: Abdulla Ashraf
 Idea:
 -transform every cycle to connected component with a root
 -assign all roots under one main root
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

const int MOD = 7 + 1e9;
const int N = (1 << 19);
const ll OO = (ll) 1 * 1e18;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int n, p[200005], c = 0, r = 0, v[200005];

int main() {
	cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		if (p[i] == i)
			r = i;
	}
	for (int i = 1; i <= n; i++)
		if (!v[i]) {
			int j = i;
			while (1) {
				if (v[j] == i) {
					p[j] = j;
					break;
				}
				if (v[j])
					break;
				v[j] = i;
				if (j == p[j])
					break;
				j = p[j];
			}
		}
	for (int i = 1; i <= n; i++)
		if (p[i] == i) {
			if (r) {
				p[i] = r;
				if (r != i)
					c++;
			} else{
				r = i;
				c++;
			}
		}
	cout << c << "\n";
	for (int i = 1; i <= n; i++)
		cout << p[i] << " ";
	return 0;
}
