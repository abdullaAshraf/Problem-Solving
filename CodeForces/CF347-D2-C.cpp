/*
 Author: Abdulla Ashraf
 Idea:
    -no matter what stpes they choose we will always end with the same number of numbers
    -that number is mx number / gcd - n
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

int main() {
	ios::sync_with_stdio(false);
	int n,mx=0,f=0,t,s;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> t;
		f = __gcd(f,t);
		mx = max(mx,t);
	}

	if((mx/f - n)&1)
		cout << "Alice";
	else
		cout << "Bob";
	return 0;
}
