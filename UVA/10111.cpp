/*
 Author: Abdulla Ashraf
 Idea:
  -use base3 intger bit mask to cover the 3 states of the node (. , x , o)
  -pass the board as 2 base2 intgers for easier navigation one tell if the cell is free or not and the other if it is x or o
  -use simple game theory rules for determining the winner
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
const ll OO = (ll) 1 * 1e9;

int mem[130000000];

void print(int s, int x) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (s & (1 << 4 * i + j)) {
				if (x & (1 << 4 * i + j))
					cout << 'x';
				else
					cout << 'o';
			} else
				cout << '.';
		}
		cout << "\n";
	}
	cout << "\n";
}

bool win(int board, int sp) {
	int c3 = 0, c4 = 0;
	for (int i = 0; i < 4; i++) {
		int c1 = 0, c2 = 0;
		if (sp & (1 << (i * 4 + i)))
			c3 += (board & (1 << (i * 4 + i)) ? 1 : -1);
		if (sp & (1 << (i * 4 + (3 - i))))
			c4 += (board & (1 << (i * 4 + (3 - i))) ? 1 : -1);
		for (int j = 0; j < 4; j++) {
			if (sp & (1 << (i * 4 + j)))
				c1 += (board & (1 << (i * 4 + j)) ? 1 : -1);
			if (sp & (1 << (j * 4 + i)))
				c2 += (board & (1 << (j * 4 + i)) ? 1 : -1);
		}
		if (abs(c1) == 4 || abs(c2) == 4)
			return 1;
	}
	if (abs(c3) == 4 || abs(c4) == 4)
		return 1;
	return 0;
}

inline int base3(int s, int x) {
	int v = 1, t = 0;
	for (int i = 0; i < 16; i++, v *= 3)
		t += v * (((x & (1 << i) ? 1 : 0) + 1) * (s & (1 << i) ? 1 : 0));
	return t;
}

const int MAX2 = (1 << 16) - 1;

int go(int s, int x, int t) {
	int & ret = mem[base3(s, x)];
	if (ret != -1)
		return ret;
	if (win(x, s)) {
		if (!t)
			return 1;
		else
			return 17;
	}
	if (s == MAX2)
		return 17;
	if (!t) {
		for (int i = 0; i < 16; i++)
			if (!(s & (1 << i)))
				if (go(s | (1 << i), x, 1) == 17)
					return ret = 17;
		return ret = 0;
	} else {
		for (int i = 0; i < 16; i++)
			if (!(s & (1 << i)))
				if (go(s | (1 << i), x | (1 << i), 0) < 17)
					return ret = i;
		return ret = 17;
	}
}

int main() {
	char s;
	memset(mem, -1, sizeof mem);
	while (cin >> s && s == '?') {
		int s = 0, x = 0;
		char c;
		for (int i = 0; i < 16; i++) {
			cin >> c;
			if (c != '.') {
				s |= 1 << i;
				if (c == 'x')
					x |= 1 << i;
			}
		}
		int ans = go(s, x, 1);
		if (ans == 17)
			cout << "#####\n";
		else
			cout << "(" << ans / 4 << "," << ans % 4 << ")\n";

	}
	return 0;
}
