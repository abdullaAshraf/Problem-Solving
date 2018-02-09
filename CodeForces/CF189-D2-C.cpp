/*
	Author: Abdulla Ashraf
	Idea:
        -any number that's is not in place will shift all upcoming by 1
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

const int N = (1 << 15);
const int OO = 200000;

int a[200005],n,t,m=0;

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
    {
        cin >> t;
        if(t != a[i-m])
            m++;
    }
    cout << m;
    return 0;
}
