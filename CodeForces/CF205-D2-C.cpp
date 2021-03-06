/*
	Author: Abdulla Ashraf

	Idea:
        - we can use a func to calculate how many are less than num X
        - the answer consist of 2 parts:
        - number with number digits smaller than R
        (if we have a number of 4 digits we have 9*10*10 number)
        - number with number digits equal to R
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

ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
}

int Dig(ll x){
    int a =0;
    while(x){
        x/=10;
        a++;
    }
    return a;
}

ll lessThan(ll y)
{
    if(y == 0)
        return 0;

    int r = Dig(y);
    ll s = 0;
    s+= (y/(ll)power(10,r-1)-1) * power(10,(max(r-2,0)));
    if(y/(ll)power(10,r-1) > y%10 )
        s--;
    if(r <= 2)
        s++;
    else
        s+= (y%(ll)power(10,r-1))/10 + 1;
    for(int i = 1; i<r; i++)
        s += power(10,(max(0,i-2)))*9;
    return s;
}


int main()
{
    ll x,y,s=0;
    cin >> x >> y;
    cout << lessThan(y) - lessThan(x-1);
    return 0;
}
