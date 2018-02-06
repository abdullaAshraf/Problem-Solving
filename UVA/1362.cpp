/*
	Author: Abdulla Ashraf
	Idea:
        -for a string to be valid it must be with odd length
        -use a dp solution where you try to split the current tap into 2 subtaps where the first one represents going for a child tour and comeback
        -the second one represent the remaining tap and it can be 0 child (i == r) , 1 child or more.
        -we multiplay the number of ways to represent the 2 subtaps to get total number of ways this split may end
        -then we sum the different ways to split the current subtap.
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
ll mem[301][301];
string x;
ll go(int l, int r)
{
    if(l == r)
        return 1;
    ll &ret = mem[l][r];
    if(ret != -1)
        return ret;
    ret = 0;

    if(x[l] == x[r])
        for(int i = l+2; i<=r; i+=2)
            if(x[i] == x[l])
                ret = (ret + go(l+1,i-1) * go(i,r))%1000000000;
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    while(getline(cin,x))
    {
        memset(mem,-1,sizeof mem);
        if(x.length()%2 == 0)
            cout << "0\n";
        else
            cout << go(0,x.length()-1) << "\n";
    }
    return 0;
}
