/*
 Author: Abdulla Ashraf
 Idea:
 -normal floyd with path keeping but change the cost of edges to inculde the taxes
 -add every node tax to any coming edge
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
const int OO = (ll) 1 * 1e9;
const ll mod = 1e9 + 7;

int g[1005][1005], pre[1005][1005], v[1005];

int main() {
	int T,f=0;
	cin >> T;
	cin.ignore();
	cin.ignore();
	while (T--) {
		string x;
		int n = 0, a, b;
		getline(cin, x);
		stringstream ss(x);
		while (ss >> g[0][n++]) {
		}
		n--;
		for (int i = 1; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> g[i][j];
		for (int i = 0; i < n; i++)
			cin >> v[i];

		cin.ignore();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (g[i][j] == -1)
					g[i][j] = OO;
				else
					g[i][j] += v[j];
				pre[i][j] = i;
			}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (g[i][j] > g[i][k] + g[k][j]) {
						g[i][j] = g[i][k] + g[k][j];
						pre[i][j] = pre[k][j];
					}

		while (getline(cin, x) && x.size() > 2) {
			if(f++)
				puts("");
			stringstream ss(x);
			ss >> a >> b;
			printf("From %d to %d :\nPath: ", a, b);
			a--,b--;
			int t = a,q=9;
			while(t!=b && q--){
				printf("%d-->",t+1);
				t = pre[b][t];
			}
			printf("%d\nTotal cost : %d\n",t+1,g[a][b] - v[b]);
		}
	}
	return 0;
}
