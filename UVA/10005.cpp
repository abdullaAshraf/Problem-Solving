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
const double EPS = 1e-9;

typedef long long ll;

const int N = 10005;

double r;

bool k(ll x1, ll y1, ll x2, ll y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= 4 * r * r + EPS;
}

ll x[100], y[100];

int main() {
	int n;
	while (cin >> n && n) {
		bool f = 1;
		for (int i = 0; f && i < n; i++)
			cin >> x[i] >> y[i];
		cin >> r;
		for (int i = 0; f && i < n; i++)
			for (int j = 0; f && j < i; j++)
				if (!k(x[i], y[i], x[j], y[j]))
					f = 0;
		if (f)
			cout << "The polygon can be packed in the circle.\n";
		else
			cout << "There is no way of packing that polygon.\n";
	}
	return 0;
}
