/*
	Author: Abdulla Ashraf

	Idea:
        - since brute force sol will TLE we do something like partial sum, first we stack operations and make them cancel each other.
        - we push in the output the elements which will never be changed again cause all coming operations have a range shorter than their indices
*/


#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
#define INF ((int)1e9)

typedef long long ll;

const int N = 10005;

int a[200005];

int main()
{
    int n,m,t,r;
    deque<pair<int,int>> x;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    while(m--)
    {
        cin >> t >> r;
        while(!x.empty() && x.back().second <= r)
            x.pop_back();
        if(x.empty() || x.back().first != t)
            x.push_back(mp(t,r));
    }
    int s=1,l=x.front().second,c=x.front().first,y =x.front().second ;
    sort(a+1,a+l+1);
    x.pop_front();
    vector<int> ans;
    for(int i=n; i>l; i--)
        ans.push_back(a[i]);
    while(!x.empty())
    {
        auto it = x.front();
        x.pop_front();
        int mv = y-it.second;
        if(c == 1)
            while(mv--)
                ans.push_back(a[l--]);
        else
            while(mv--)
                ans.push_back(a[s++]);
        c = it.first;
        y = it.second;
    }
    if(c == 1)
        for(int i=l; i>=s; i--)
            ans.push_back(a[i]);
    else
        for(int i = s; i<=l; i++)
            ans.push_back(a[i]);

    for(int i=n-1; i>=0; i--)
        cout << ans[i] << " ";
    return 0;
}

