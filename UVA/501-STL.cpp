/*
	Author: Abdulla Ashraf
	Idea:
        -too add numbers and get the min at anytime we can use a reversed priority queue.
        -now when we use get it increase i so it may sounds we don't need this number anymore so pop it and keep it in a 2nd queue
        -when a new number is added it maybe larger than the min in the 1st queue so it won't affect the current min just add it.
        -if it is smaller then the min will be this vaule or one of the values we poped eariler.
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

int a[30005];
priority_queue<int> x;
priority_queue<int, vector<int>, greater<int> > y;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n,m,t,r=0;
        cin >> n >> m;
        for(int i=0; i<n; i++)
            scanf("%d",a+i);
        for(int i=0; i<m; i++)
        {
            cin >> t;
            while(r < t){
                    if(!y.empty() && a[r] >= y.top())
                        y.push(a[r++]);
                    else{
                        x.push(a[r++]);
                        y.push(x.top());
                        x.pop();
                    }
            }
            printf("%d\n",y.top());
            x.push(y.top());
            y.pop();
        }
        while(!x.empty())
            x.pop();
        while(!y.empty())
            y.pop();
        if(T)
            printf("\n");
    }
    return 0;
}
