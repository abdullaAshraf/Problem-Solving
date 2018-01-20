/*
	Author: Abdulla Ashraf
	Idea:
       - move through points in order give every one of tubes 2 points but the last one give it the rest.
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

int n,m,k,x=1,y=1;

void nxt(int &x, int&y)
{
    if(x%2)
    {
        if(y!= m)
            y++;
        else
            x++;
    }
    else
    {
        if(y!= 1)
            y--;
        else
            x++;
    }
}

int main()
{

    cin >> n >> m >> k;
    for(int h=1; h<k; h++)
    {
        cout << "2 " << x << " " << y << " ";
        nxt(x,y);
        cout << x << " " << y << "\n";
        nxt(x,y);
    }
    cout << n*m -2*(k-1);
    for(int i=n*m -2*(k-1); i>0; i--){
        cout << " " << x << " " << y;
        nxt(x,y);
    }
    cout << "\n";
    return 0;
}
