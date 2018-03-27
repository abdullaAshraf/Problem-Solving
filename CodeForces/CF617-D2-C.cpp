/*
 Author: Abdulla Ashraf
 Idea:
 -sort the flowers from r1 as nearest first, move upon n , try to reach till every point and all the other point distance from r2
 -use a cumlative max from the end
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const int N = (1 << 18);
const ll OO = (ll) 1 * 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-9;

int n,xx1,yx1,x2,y2;

ll dis(ll x, ll y) {
	return (x - xx1) * (x - xx1) + (y - yx1) * (y - yx1);
}

ll dis2(ll x, ll y) {
	return (x - x2) * (x - x2) + (y - y2) * (y - y2);
}

ll m[2005];


int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin >> n >> xx1 >> yx1 >> x2 >> y2;
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;
	sort(p.begin(), p.end(), [](pair<int,int> l , pair<int,int> r) {
		return dis(l.first ,l.second) < dis(r.first ,r.second);
	});
	m[n - 1] = dis2(p[n - 1].first, p[n - 1].second);
	for (int i = n - 2; i >= 0; i--)
		m[i] = max(m[i + 1], dis2(p[i].first, p[i].second));
	ll mn = m[0];
	for (int i = 0; i < n; i++)
		mn = min(mn, dis(p[i].first, p[i].second) + m[i + 1]);
	cout << mn;
	return 0;
}
