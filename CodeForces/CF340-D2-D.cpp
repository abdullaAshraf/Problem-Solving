/*
	Author: Abdulla Ashraf
	Idea:
        -longest increasing subsequence using binary search method nlogk
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

int main()
{
    int n,t;
    cin >> n;
    set<int>x;
    for(int i = 0 ; i<n ; i++)
    {
        int t;
        cin>>t;
        auto it = x.lower_bound(t);
        if(it!=x.end())
            x.erase(*it);
        x.insert(t);
    }
    cout<<x.size();
    return 0;
}
