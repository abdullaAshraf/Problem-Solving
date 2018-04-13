/*
 Author: Abdulla Ashraf
 Idea:
  -use dp to cover all states and the current string length to determine which turn it is
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
const ll OO = (ll) 1 * 1e18;

typedef complex<double> point;

#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))

map<vector<int>, int> m;

int SG(vector<int> x) {
	if (m.find(x) != m.end())
		return m[x];
	int s = 0;
	for (int i = 1; i < 7; i++)
		s += i * x[i];
	if (s > 31)
		return 1;
	bool w = 0;
	for (int i = 1; i < 7; i++)
		if (x[i] < 4) {
			x[i]++;
			w = w || !SG(x);
			x[i]--;
		}
	return m[x] = w;
}

int main() {
	string s;
	while (getline(cin,s)) {
		vector<int> x(7);
		for (auto it : s)
			x[it - '0']++;
		if(SG(x) ^ s.size()%2)
			cout << s << " A\n";
		else
			cout << s << " B\n";
	}
	return 0;
}
