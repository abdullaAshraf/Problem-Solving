/*
	Author: Abdulla Ashraf
	Idea:
        -the losing state is a number with 2 non-trival divisors which is a number which is a multiply of 2 primes
        -if the 1st player is not already in a losing state he always can get the 2nd one into it with 1 play.
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
    ll x,c=0,v=0,t;
    cin >> x;
    for(ll i=2; i*i<=x; i++)
    {
        while(x%i == 0)
        {
            x/=i;
            c++;
            if(!v)
                v = i;
            else
                t = i;
        }
    }
    if(x > 1){
        c++;
        t = x;
    }
    if(c == 0)
        cout << "1\n0";
    else if(c == 2)
        cout << 2;
    else
        cout << "1\n" << v*t;
    return 0;
}
