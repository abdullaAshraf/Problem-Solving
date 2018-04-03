/*
 Author: Abdulla Ashraf
 Idea:
 -http://codeforces.com/blog/entry/14256
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
const int NN = 10;
const ll MOD = 1e9 + 7;

int main(){
	int n,k;
	cin >> n >> k;
	cout << (6*(n-1)+5)*k << "\n";
	for(int i=0; i<n; i++)
		cout << k*(i*6+1) << " " << k*(i*6+2) << " " << k*(i*6+3) << " " << k*(i*6+5) << "\n";
}
