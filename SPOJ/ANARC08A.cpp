/*
 Author: Abdulla Ashraf
 Idea:
 -BFS to get all possible strings
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
const ll OO = (ll) 1 * 1e9;

#define val m[h[0]-'1'][h[1]-'1'][h[2]-'1'][h[3]-'1'][h[4]-'1'][h[5]-'1'][h[6]-'1'][h[7]-'1']

string A(string x) {
	char v = x[0];
	x[0] = x[3];
	x[3] = x[4];
	x[4] = x[1];
	x[1] = v;
	return x;
}

string AA(string x) {
	char v = x[0];
	x[0] = x[1];
	x[1] = x[4];
	x[4] = x[3];
	x[3] = v;
	return x;
}

string B(string x) {
	char v = x[1];
	x[1] = x[4];
	x[4] = x[5];
	x[5] = x[2];
	x[2] = v;
	return x;
}

string BB(string x) {
	char v = x[1];
	x[1] = x[2];
	x[2] = x[5];
	x[5] = x[4];
	x[4] = v;
	return x;
}

string C(string x) {
	char v = x[3];
	x[3] = x[6];
	x[6] = x[7];
	x[7] = x[4];
	x[4] = v;
	return x;
}

string CC(string x) {
	char v = x[3];
	x[3] = x[4];
	x[4] = x[7];
	x[7] = x[6];
	x[6] = v;
	return x;
}

string D(string x) {
	char v = x[4];
	x[4] = x[7];
	x[7] = x[8];
	x[8] = x[5];
	x[5] = v;
	return x;
}

string DD(string x) {
	char v = x[4];
	x[4] = x[5];
	x[5] = x[8];
	x[8] = x[7];
	x[7] = v;
	return x;
}

/*
 012
 345
 678
 */

int m[9][9][9][9][9][9][9][9];

void go() {
	queue<string> q;
	q.push("123456789");
	m[0][1][2][3][4][5][6][7] = 0;
	int v = 1;
	for (int y = 1; y <= 9; y++, v = q.size())
		while (v--) {
			string x = q.front(), h;
			q.pop();
			h = A(x);
			if (val == -1) {
				val = y;
				if (y != 9)
					q.push(h);
			}
			h = AA(x);
			if (val == -1) {
				val = y;
				if (y != 9)
					q.push(h);
			}
			h = B(x);
			if (val == -1) {
				val = y;
				if (y != 9)
					q.push(h);
			}
			h = BB(x);
			if (val == -1) {
				val = y;
				if (y != 9)
					q.push(h);
			}
			h = C(x);
			if (val == -1) {
				val = y;
				if (y != 9)
					q.push(h);
			}
			h = CC(x);
			if (val == -1) {
				val = y;
				if (y != 9)
					q.push(h);
			}
			h = D(x);
			if (val == -1) {
				val = y;
				if (y != 9)
					q.push(h);
			}
			h = DD(x);
			if (val == -1) {
				val = y;
				if (y != 9)
					q.push(h);
			}
		}
}

int main() {
	string h;
	char v;
	int tt = 1;
	memset(m, -1, sizeof m);
	go();
	while (cin >> v >> h && h[0] != '0') {
		int y = v - '0';
		cout << tt++ << ". ";
		if(val > y)
			cout << "-1\n";
		else
			cout << val << "\n";
	}
}
