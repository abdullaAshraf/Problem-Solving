/*
	Author: Abdulla Ashraf
	Idea:
        -using bitmasks to store the current grid
        -use dp to try every possible move in the current grid
        -use simple game theory rules of winning and losing positions
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int OO = 100000007;

int mem[150000];

inline bool cl(int m, int i, int j) {
	if (i > 3 || j > 3)
		return 0;
	return (m & (1 << (j + 4 * i))) == 0;
}

void cn(int m) {
	string s = bitset<16>(m).to_string();
	cout << s.substr(0, 4) << "\n" << s.substr(4, 4) << "\n" << s.substr(8, 4)
			<< "\n" << s.substr(12, 4) << "\n\n";
}

int go(int m) {
    if(m == (1<<16)-1)
        return 1;
	int &ret = mem[m];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (cl(m, i, j)) {
				ret = ret && go(m | 1 << (j + 4 * i));
				if (cl(m, i + 1, j)) {
					if ((i == 0 || i == 2))
						ret = ret
								&& go(
										m | 1 << (j + 4 * i)
												| 1 << (j + 4 * (i + 1)));
					if (cl(m, i + 2, j))
						ret = ret
								&& go(
										m | 1 << (j + 4 * i)
												| 1 << (j + 4 * (i + 1))
												| 1 << (j + 4 * (i + 2)));
				}
				if (cl(m, i, j + 1)) {
					if ((j == 0 || j == 2))
						ret = ret
								&& go(
										m | 1 << (j + 4 * i)
												| 1 << (j + 1 + 4 * i));
					if (cl(m, i, j + 2))
						ret = ret
								&& go(
										m | 1 << (j + 4 * i)
												| 1 << (j + 1 + 4 * i)
												| 1 << (j + 2 + 4 * i));
				}
			}
	return ret = 1 - ret;
}

int main() {
	int T, m;
	cin >> T;
	cin.ignore();
	memset(mem, -1, sizeof mem);
	for (int tt = 1; tt <= T; tt++) {
		m = 0;
		cin.ignore();
		string x;
		for (int i = 0; i < 4; i++) {
			getline(cin,x);
			for (int j = 0; j < 4; j++)
				if (x[j] == 'X')
					m |= 1 << (j + i * 4);
		}
		if (go(m))
			cout << "WINNING\n";
		else
			cout << "LOSING\n";
	}
	return 0;
}
