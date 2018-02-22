/*
 Author: Abdulla Ashraf
    Idea:
      -implementation problem , too many rules and cases to handle
      -read the string split it on + & - and store all values in a vector of pair<int,int> and an imteger ,represnting x & y Exponents and the coefficient
      -loop over vectors and multiplay every element from the first by every one in the second vector and store answer in map<pair<int,int>,ll> to sum repeated values
      -move all elemnts from the map to a vector and use custom sort to achieve required order , then convert the vector into 2 strings
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
const ll OO = (ll) 1 * 1e18;
const ll mod = 1e9 + 7;

int a[2][50], b[2][50], c[2][50], ad[2];

struct po {
	int a, b, c;

	po(int a, int b, int c) :
			a(a), b(b), c(c) {
	}

	bool operator <(const po & e) const {
		if (a == e.a)
			return b < e.b;
		return a > e.a;
	}
};

void getvec(string x, int in) {
	int j = 0;
	for (int i = 0; i <= x.length(); i++) {
		if ((i == x.length() || x[i] == '+' || x[i] == '-') && i != j) {
			string t;
			if(x[j] == '+' || x[j] == '-')
				t = x.substr(j+1, i - j -1);
			else
				t = x.substr(j, i - j);
			auto it = t.find('x');
			auto it2 = t.find('y');
			if (it == string::npos)
				a[in][ad[in]] = 0;
			else if (it + 1 == t.length() || !isdigit(t[it + 1]))
				a[in][ad[in]] = 1;
			else if (it2 == string::npos || it2 < it)
				a[in][ad[in]] = stoi(t.substr(it + 1));
			else
				a[in][ad[in]] = stoi(t.substr(it + 1, it2 - it - 1));

			if (it2 == string::npos)
				b[in][ad[in]] = 0;
			else if (it2 + 1 == t.length() || !isdigit(t[it2 + 1]))
				b[in][ad[in]] = 1;
			else if (it == string::npos || it < it2)
				b[in][ad[in]] = stoi(t.substr(it2 + 1));
			else
				b[in][ad[in]] = stoi(t.substr(it2 + 1, it - it2 - 1));

			if (it2 == string::npos && it == string::npos)
				c[in][ad[in]] = stoi(t);
			else {
				int f;
				if (it2 == string::npos)
					f = it;
				else if (it == string::npos)
					f = it2;
				else
					f = min(it2, it);
				if (f == 0 || (f == 1 && t[0] == '-'))
					c[in][ad[in]] = 1;
				else
					c[in][ad[in]] = stoi(t.substr(0, f));
			}
			if (x[j] == '-')
				c[in][ad[in]] *= -1;
			ad[in]++;
			j = i;
		}
	}

}

int main() {
	string x, y;
	while (getline(cin, x) && x != "#") {
		getline(cin, y);
		map<pair<int, int>, ll> m;
		vector<po> s;
		ad[0] = ad[1] = 0;
		getvec(x, 0);
		getvec(y, 1);
		for (int i = 0; i < ad[0]; i++)
			for (int j = 0; j < ad[1]; j++)
				m[mp(a[0][i] + a[1][j], b[0][i] + b[1][j])] += c[0][i]* c[1][j];
		for (auto it : m)
			if(it.second != 0)
				s.pb(po(it.first.first, it.first.second, it.second));
		sort(s.begin(), s.end());
		string t = "", r = "";
		if(s.empty())
			t="",r="0";

		for (auto it : s) {
			if (r.size() > 0) {
				if (it.c < 0) {
					r += " - ";
					it.c *= -1;
				} else
					r += " + ";
			}
			if(it.a == 0 && it.b == 0)
				r += to_string(it.c);
			else if(it.c == -1)
				r+='-';
			else if (it.c!= 1)
				r += to_string(it.c);
			if (it.a) {
				r += 'x';
				while (t.length() < r.length())
					t += ' ';
				if (it.a != 1)
					t += to_string(it.a);
				while (t.length() > r.length())
					r += ' ';
			}
			if (it.b) {
				r += 'y';
				while (t.length() < r.length())
					t += ' ';
				if (it.b != 1)
					t += to_string(it.b);
				while (t.length() > r.length())
					r += ' ';
			}
			while (t.length() > r.length())
					r += ' ';
			while (t.length() < r.length())
					t += ' ';
		}
		cout << t << "\n" << r << "\n";
	}
	return 0;
}
