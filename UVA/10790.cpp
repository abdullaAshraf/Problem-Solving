/*
 Author: Abdulla Ashraf
 Idea:
  -1st value will be (a-1) * b*(b-1)/2 , 2nd will be (a-2) *b*(b-1)/2 and so on
  -so the sum will be a*(a-1)/2 * b*(b-1)/2
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = (1 << 17);
const ll OO = (ll) 1 * 1e18;

int main() {
	cin.sync_with_stdio(0);
	ll a,b,c=1;
	while(cin >> a >> b && a)
		cout << "Case " << c++ <<": " << (a*(a-1)/2) * (b*(b-1)/2) << "\n";
	return 0;
}
