/*
	Author: Abdulla Ashraf
	Idea:
        -notice that number of different subtree posibilties depend only on the number of consegtive element in it and not the values themselves
        -use a recusion memoization function to count 3 things depending on f (it acts as 3 sepreate recusion functions merged in one
        -when f==2 calculate all possible binary search tree with n nodes
        -when f==1 calculate all possible binary search tree with n nodes and total highet less than h
        -when f==0 calculate all possible binary search tree with n nodes and total highet more than or equal h
        -in counting we need to avoid counting the tree where both subtrees height more than h twice
        -we can use only 2 values for f (0,2) using inclusion exclusion principle
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

int n,h;
ll mem[40][40][3];

ll go(int l,int n,int f)
{
    if(n == 0)
    {
        if(f == 2)
            return 1;
        if(f == 1)
            return l < h;
        return l >= h;
    }
    ll &ret = mem[l][n][f];
    if(ret != -1)
        return ret;
    ret = 0;
    if(f == 2)
        for(int i=0; i<n; i++)
            ret += go(l+1,i,2)*go(l+1,n-i-1,2);
    else if(f == 1)
        for(int i=0; i<n; i++)
            ret += go(l+1,i,1)*go(l+1,n-i-1,1);
    else
        for(int i=0; i<n; i++)
            ret += go(l+1,i,0)*(go(l+1,n-i-1,2)+go(l+1,n-i-1,1));
    return ret;
}

int main()
{
    memset(mem,-1,sizeof mem);
    cin >> n >> h;
    cout << go(0,n,0);
    return 0;
}
