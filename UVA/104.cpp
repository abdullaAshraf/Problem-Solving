/*
	Author: Abdulla Ashraf
	Idea:
        -try to find best answer using every number of steps less than n
        -to find best answer in a step s use floyd algorthim with values in the pervious step to get best change rate for each value.
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

int n,p[25][25][25];
double a[25][25][25];

void floyd(int s)
{
    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if (a[i][k][s-1] * a[k][j][0] > a[i][j][s])
                {
                    a[i][j][s] = a[i][k][s-1] * a[k][j][0];
                    p[i][j][s] = k;
                }
}

int main()
{

    while(cin >> n)
    {
        memset(a,0,sizeof a);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)if(i!=j)
                {
                    cin >> a[i][j][0];
                    p[i][j][0] = i;
                }
        for(int i=0; i<n; i++)
        {
            a[i][i][0] = 1;
            p[i][i][0] = i;
        }

        vector<int> x;
        int f = 1;
        for(int s=1; f && s<n; s++)
        {
            floyd(s);
            for(int i=0; f && i<n; i++)if(a[i][i][s] > 1.01 - EPS)
                {
                    x.pb(i+1);
                    int k = p[i][i][s];
                    for(int j=s-1; j>=0; j--)
                    {
                        x.pb(k+1);
                        k = p[i][k][j];
                    }
                    x.pb(i+1);
                    for(int j=x.size()-1; j>0; j--)
                        cout << x[j] << " ";
                    cout << x[0] << "\n";
                    f=0;
                }
        }
        if(f)
            cout << "no arbitrage sequence exists\n";
    }
    return 0;
}
