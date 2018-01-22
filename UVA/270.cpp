/*
	Author: Abdulla Ashraf
	Idea:
        - n^2 log n solution
        - we get every point consider that the line will pass through this point
        - try all the slope of the other points with this one and maximize the common slope
        - handle vertical slope OO and handle if 2 points are on the same position
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

map<double,int> m;
double x[705],y[705];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    cin.ignore();
    cin.ignore();
    string s;
    while(T--)
    {
        int mx=0,t=0;
        while(getline(cin,s) && s.length() > 0)
        {
            stringstream ss(s);
            ss >> x[t] >> y[t];
            t++;
        }
        for(int i=0; i<t; i++)
        {
            m.clear();
            int c = 0,d =0;
            for(int j=0; j<t; j++)
            {
                if(x[j] == x[i])
                {
                    if(y[j] == y[i])
                    {
                        d++;
                    }
                    else
                    {
                        c++;
                    }
                }
                else
                    m[(y[j]-y[i])/(x[j]-x[i])]++;
            }
            for(auto it : m)
                c = max(c,it.second);
            mx = max(mx,c+d);
        }
        cout << mx << "\n";
        if(T)
            cout << "\n";
    }
    return 0;
}
