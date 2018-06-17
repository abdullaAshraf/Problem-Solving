/*
 Author: Abdulla Ashraf
 Idea:
 -map sets to integers and simulate the required
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

map<set<int>, int> m;
vector<set<int>> x;

int name(set<int> s) {
	if (m.find(s) != m.end())
		return m[s];
	m[s] = x.size();
	x.pb(s);
	return x.size() - 1;
}

int main() {
	cin.sync_with_stdio(0);
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		string s;
		stack<int> q;
		while (n--) {
			cin >> s;
			if (s == "PUSH")
				q.push(name(set<int>()));
			else if (s == "DUP")
				q.push(q.top());
			else if (s == "UNION") {
				set<int> a = x[q.top()];
				q.pop();
				set<int> b = x[q.top()];
				q.pop();
				set<int> c;
				set_union(a.begin(), a.end(), b.begin(), b.end(),
						inserter(c, c.begin()));
				q.push(name(c));
			} else if (s == "INTERSECT") {
				set<int> a = x[q.top()];
				q.pop();
				set<int> b = x[q.top()];
				q.pop();
				set<int> c;
				set_intersection(a.begin(), a.end(), b.begin(), b.end(),
						inserter(c, c.begin()));
				q.push(name(c));
			} else if (s == "ADD") {
				int a = q.top();
				q.pop();
				set<int> b = x[q.top()];
				q.pop();
				b.insert(a);
				q.push(name(b));
			}
			cout << x[q.top()].size() << "\n";
		}
		cout << "***\n";
	}
	return 0;
}
