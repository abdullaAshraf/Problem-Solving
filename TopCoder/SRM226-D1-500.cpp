/*
 Author: Abdulla Ashraf
 Idea:
 -simple implemtation with probabilty rules mentioned in problem
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

struct OneArmedBandit {
	vector<vector<double>> p;

	double odds(string s) {
		double pp = 1;
		for (int i = 0; i < s.length(); i++)
			if (s[i] != '-')
				pp *= p[i][s[i] - 'A'];
		return pp;
	}

	double progressiveJackpot(vector<string> wheels, string jackpotLine,
			vector<string> payoffTable) {

		p.clear();

		for (auto it : wheels) {
			vector<double> v = vector<double>(26);
			for (int i = 0; i < 26; i++)
				v[i] = 1.0 * count(it.begin(), it.end(), (char) ('A' + i))
						/ it.length();
			p.pb(v);
		}

		double exp = 0;
		for (auto it : payoffTable) {
			string s = it.substr(0, p.size());
			int v = stoi(it.substr(p.size() + 1));
			exp += v * odds(s);
		}
		
		if(exp + EPS >= 1)
			return 0;
		if(odds(jackpotLine) == 0)
			return -1;
		return (1-exp) / odds(jackpotLine);

	}
};
