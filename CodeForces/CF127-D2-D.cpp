/*
 Author: Abdulla Ashraf
 Idea:
 -use Z-algorthim to check for matching prefix and suffix and if it is repeated more than 2 times it is in the middle as well
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

void getZarr(string str, int Z[]) {
	int n = str.length();
	int L, R, k;

	L = R = 0;
	for (int i = 1; i < n; ++i) {
		if (i > R) {
			L = R = i;
			while (R < n && str[R - L] == str[R])
				R++;
			Z[i] = R - L;
			R--;
		} else {
			k = i - L;

			if (Z[k] < R - i + 1)
				Z[i] = Z[k];

			else {
				L = i;
				while (R < n && str[R - L] == str[R])
					R++;
				Z[i] = R - L;
				R--;
			}
		}
	}
}

int x[1000005];

int main() {
	string s;
	cin >> s;
	int Z[s.length()];
	getZarr(s, Z);
	for (int i = 1; i < s.length(); i++)
		x[Z[i]]++;
	x[s.length() - 1]++;
	for (int i = s.length(); i > 0; i--)
		x[i] += x[i + 1];
	int mx = -1;
	for (int i = s.length() - 1; i > 0; i--)
		if (Z[i] + i == s.length() && x[s.length() - i] > 2)
			mx = s.length() - i;
	if (mx == -1)
		cout << "Just a legend";
	else
		cout << s.substr(0, mx);
	return 0;
}
