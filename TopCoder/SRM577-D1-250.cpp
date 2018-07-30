/*
 Author: Abdulla Ashraf
 Idea:
 -use expected value rules to get the answer and handle special cases
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

struct EllysRoomAssignmentsDiv1 {
	double getAverage(vector<string> ratings) {
		stringstream ss;
		for (auto it : ratings)
			ss << it;
		int p, t;
		vector<int> x;
		ss >> p;
		x.pb(p);
		while (ss >> t)
			x.pb(t);
		sort(x.begin(), x.end(), greater<int>());
		double exp = p;
		int g = (x.size() + 19) / 20;
		int mn = x.size() / g;
		int add = x.size() % g;

		for (int i = 0; i < mn; i++) {
			double avg = 0;
			bool f = 0;
			for (int j = i * g; j < (i + 1) * g; j++) {
				avg += x[j];
				if (x[j] == p)
					f = 1;
			}
			if (!f)
				exp += avg / g;
		}
		double avg = 0;
		bool f = 0;
		for (int i = x.size() - add; i < x.size(); i++) {
			avg += x[i];
			if (x[i] == p)
				f = 1;
		}
		if (f)
			exp /= (mn + 1);
		else {
			if (add)
				exp = (1.0 * (g - add) / g) * exp / mn
						+ (1.0 * add / g) * (exp + (avg / add)) / (mn + 1);
			else
				exp = (1.0 * (g - add) / g) * exp / mn;

		}
		return exp;
	}
};
