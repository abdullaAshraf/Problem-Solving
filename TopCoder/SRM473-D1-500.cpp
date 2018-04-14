/*
 Author: Abdulla Ashraf
 Idea:
 -use Disjoint sets to get the next free point in o(n) total
 -for a circle to contain a right tringle the largest edge must be on the circle diamter so the places must be even and the 2 points with places/2 differance then any other point will make a right triangle
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)
const double PI = acos(-1.0);
const double EPS = 1e-9;

typedef long long ll;

const int N = (1 << 17);
const ll MOD = 7 + 1e9;
const ll OO = (ll) 1 * 1e18;

int p[1000002];

int find_set(int x) {
	if (x == p[x])
		return x;
	return p[x] = find_set(p[x]);
}

struct RightTriangle {
	ll triangleCount(int places, int points, int a, int b, int c) {
		if (places % 2 || points < 3)
			return 0;
		if (points == places)
			return (ll) points / 2 * (points - 2);
		for (int i = 0; i < places; i++)
			p[i] = i;
		for (ll i = 0; i < points; i++) {
			int v = find_set((a * i * i + b * i + c) % places);
			p[v] = p[(v + 1) % places];
		}
		ll s = 0;
		for (int i = 0; i < places / 2; i++)
			if (p[i] != i && p[i + places / 2] != i + places / 2)
				s++;
		return s * (points - 2);
	}

};
