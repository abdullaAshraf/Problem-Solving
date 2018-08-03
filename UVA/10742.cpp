/*
 Author: Abdulla Ashraf
 Idea:
 -get all primes and use binary search to find how many number can work with every other one to be less than the required number
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

vector<int> pr;
int p[1000005];

void seive(int n) {
	for (int i = 2; i <= n; i++)
		p[i] = 1;

	for (int i = 2; i * i <= n; i++)
		if (p[i])
			for (int j = i * 2; j <= n; j += i)
				p[j] = 0;

	for (int i = 2; i <= n; i++)
		if(p[i])
			pr.pb(i);
}

int main() {
	seive(1000000);
	int c,tt=1;
	while (cin >> c && c) {
		ll ans = 0;
		for (int i = 0; i+1 < pr.size()  && pr[i] <= c / 2; i++) {
			auto it = lower_bound(pr.begin(), pr.end(), c - pr[i]);
			if (it == pr.end() || *it > c - pr[i])
				it--;
			ans += (it - pr.begin()) - i;
		}
		cout << "Case " << tt++ << ": " << ans << "\n";
	}
	return 0;
}

