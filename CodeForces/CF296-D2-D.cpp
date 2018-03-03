#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int x[505][505], vi[505];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> x[i][j];
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	reverse(a.begin(), a.end());
	vector<ll> res(n);
	memset(vi, 0, sizeof vi);
	for (int h = 0; h < n; h++) {
		int i = a[h];
		vi[i] = 1;

		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				x[j][k] = min(x[j][k], x[j][i] + x[i][k]);

		for (int j = 0; j < n; j++)
			if (vi[j])
				for (int k = 0; k < n; k++)
					if (vi[k] && j != k)
						res[h] += x[j][k];
	}
	for(int i=res.size()-1; i>=0; i--)
		cout << res[i] << " ";
	return 0;
}
