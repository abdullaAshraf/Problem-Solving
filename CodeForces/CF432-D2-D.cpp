/*
 Author: Abdulla Ashraf
 Idea:
 -use Z-algorthim to constract Z-array
 -compare Z-array value with length to end to get the suffix that match a prefix
 -use cummltive sum on appearance array to get answer
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

int x[100005];

int main() {
	string s;
	cin >> s;
	int Z[s.length()];
	getZarr(s, Z);
	for (int i = 1; i < s.length(); i++)
		x[Z[i]]++;
	x[s.length()-1]++;
	for (int i = s.length(); i > 0; i--)
		x[i] += x[i + 1];
	int c = 1;
	for (int i = s.length() - 1; i > 0; i--)
		if (Z[i] + i == s.length())
			c++;
	cout << c << "\n";
	for (int i = s.length() - 1; i > 0; i--)
		if (Z[i] + i == s.length())
			cout << s.length() - i << " " << x[s.length() - i] << "\n";
	cout << s.length() << " " << 1;
	return 0;
}

