/*
 Author: Abdulla Ashraf
 Idea:
    -store the last occuarence of every prime factor of the number in an array to access it in O(1)
    -check every prime factor position to know the best position to add the current number
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

int p[100005];

int main() {
	int n, t;
	cin >> n;
	while (n--) {
		cin >> t;
		int mx = 0;
		vector<int> pr;
		for (int i = 2; i * i <= t; i++) {
			if (t % i == 0) {
				pr.pb(i);
				while (t % i == 0)
					t /= i;
				mx = max(mx,p[i]+1);
			}
		}
		if(t != 1){
			pr.pb(t);
			mx = max(mx,p[t]+1);
		}
		for(auto it : pr)
			p[it] = mx;
	}
	int ans = 1;
	for(int i=2; i<=100000; i++)
		ans = max(ans,p[i]);
	cout << ans;
	return 0;
}
