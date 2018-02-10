/*
	Author: Abdulla Ashraf
	Idea:
        -getting the current max sum row or current max sum column will give best answer
        -order of opeartions doesn't change the answer only the selected rows and columns
        -getting a row reduce its value by p*m and all columns by p and vice verca
        -try every possible max X rows and k-X columns
        -to get max X rows we need to sort them in a priority queue get the top reduce it and push it again (k*logn = 10^7)
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

ll n,m,k,p,x[1000],y[1000],t;

int main()
{
    cin >> n >> m >> k >> p;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin >> t;
            x[i]+=t;
            y[j]+=t;
        }
    priority_queue<int> q,w;
    stack<int> v;
    for(int i=0; i<n; i++)
        q.push(x[i]);
    for(int i=0; i<m; i++)
        w.push(y[i]);
    ll sum = 0,s =0;
    for(int i=0; i<k; i++)
    {
        int h = w.top();
        w.pop();
        v.push(h);
        sum += h;
        w.push(h-p*n);
    }
    ll mx = sum;
    for(int i=1; i<=k; i++)
    {
        int h = q.top();
        q.pop();
        s+= h;
        sum -= v.top();
        v.pop();
        q.push(h-p*m);
        mx = max(mx,sum + s - (k-i)*p*i);
    }
    cout << mx;
    return 0;
}
