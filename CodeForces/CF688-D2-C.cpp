#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int OO = 1000000000;

vector<vector<int>> x;
int v[100005];

bool go(int in, int d) {
	if (v[in] == d)
		return true;
	if (v[in] != -1)
		return false;
	v[in] = d;
	bool ret = true;
	for (int i = 0; i < x[in].size(); i++)
		ret = ret && go(x[in][i], 1 - d);
	return ret;
}

int main() {
	int n, m, a, b;
	cin >> n >> m;
	memset(v, -1, sizeof v);
	x.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		x[a].push_back(b);
		x[b].push_back(a);
	}
	bool ret = true;
	for (int i = 1; i <= n; i++)
		if (v[i] == -1)
			ret = ret && go(i, 0);
	if (!ret)
		cout << -1;
	else {
		vector<int> x, y;
		for (int i = 1; i <= n; i++)
			if (v[i] == 0)
				x.push_back(i);
			else if (v[i] == 1)
				y.push_back(i);
		cout << x.size() << endl;
		for (auto it : x)
			cout << it << " ";
		cout << "\n" << y.size() << endl;
		for (auto it : y)
			cout << it << " ";
	}
	return 0;
}
