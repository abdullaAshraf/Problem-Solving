/*
 Author: Abdulla Ashraf
 Idea:
 -use dfs to get sum of all path costs between all points in the graph and in how many every edge appear
 -simple math to calculate new total by subtracting the difference between new and old cost multiplayed by the number of appearance of the edge
 -use probabilty to get expected value
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

vector<vector<pair<int, int>>> x;
ll edge[100005];
int w[100005];
int vis[100005];
int mem[100005];
ll n;

int go(int in) {
	vis[in] = 1;

	int cnt = 1;
	for (int i = 0; i < x[in].size(); i++)
		if (!vis[x[in][i].st]){
			int v= go(x[in][i].st);
			edge[x[in][i].nd] = v*(n-v);
			cnt += v;
		}
	return cnt;
}

ll nChoosek( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main() {
	int q, a, b;
	cin >> n;
	x.resize(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> w[i];
		x[a].pb(mp(b, i));
		x[b].pb(mp(a, i));
	}
	memset(mem,-1,sizeof mem);

	go(1);

	ll total = 0;
	for(int i=1; i<n; i++)
		total += edge[i] * w[i];
	cin >> q;
	while (q--) {
		cin >> a >> b;
		total -= (w[a]-b)*edge[a];
		w[a] = b;
		double x = 6.0 * total / (n*(n-1));
		cout << fixed << setprecision(10) << x  << "\n";
	}
	return 0;
}

