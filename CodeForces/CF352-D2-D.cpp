/*
	Author: Abdulla Ashraf
	Idea:
        -first count the number of swaps required at the start
        -note in Furic turn he will always find a move in both directions since if it is sorted in the increasing order the game is over and if  it is sorted in the decreasing order it will be jeff turn
        -assume the number of required swaps is X and it is jeff turn if X < 2 the answer is X
        -else F(X) = 2+(F(X-2)+F(x))/2 which is the 2 cases jeff always reduce x by 1 while furic may reduce it or increase it back
        -now do the math F(x) = 4+F(X-2) which means we add 4 for each 2 of X (2 for each X) except for the last if x is odd
        -so answer is 2*x-x%2
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
    int n,a[3005],r=0;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        for(int j=0; j<i; j++)
            if(a[i] < a[j])
                r++;
    }
    cout <<fixed << setprecision(6) << (double)(r*2-r%2);
    return 0;
}
