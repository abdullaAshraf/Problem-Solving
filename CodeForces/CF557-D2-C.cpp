/*
	Author: Abdulla Ashraf
	Idea:
        -we will try every avaliable length to make length x the max leg length and the table stable we must do the following:
        -remove all legs longer than x, remove all legs less than x except for max of number of x-1
        -we use cumlative sum to get the sum of power required to remove every leg till now and we use a priority queue to calculate the sum of max n-1 numbers less than x
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

int n,a[100005],l=0;

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin >> n;
    vector<pair<int,int>> x(n),t;
    priority_queue<int> h;
    queue<int> rem;
    for(int i=0; i<n; i++)
        cin >> x[i].first;
    for(int i=0; i<n; i++)
        cin >> x[i].second;
    sort(x.begin(),x.end());
    for(int i=1; i<=n; i++)
    {
        a[i] = x[i-1].second + a[i-1];
        if(x[i-1].first != l)
        {
            l = x[i-1].first;
            t.pb(mp(i,i));
        }
        else
            t[t.size()-1].second = i;
    }
    int mn = INT_MAX;
    for(auto it : t)
    {
        //cout << it.first << " " << it.second << endl;
        while(h.size() + 1 < it.first)
            h.push(x[h.size()].second);
        int r = 0,v = min(it.second - it.first ,(int) h.size());
        for(int i=0; i<v; i++)
        {
            r += h.top();
            rem.push(h.top());
            h.pop();
        }
        while(rem.size())
        {
            h.push(rem.front());
            rem.pop();
        }
        //cout << r << " " << a[it.first-1] << " " << a[n] << " " << a[it.second] << endl;
        mn = min(mn,a[it.first-1] - r + a[n] - a[it.second]);
        //cout << mn << endl;
    }
    cout << mn;
    return 0;
}
