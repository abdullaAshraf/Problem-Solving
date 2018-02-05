/*
	Author: Abdulla Ashraf
	Idea:
        -run a preprocess to find each '(' clsoing ')' and check if there is any words or the parentheses is not matching right
        -use a recusive way where you pass the start and end postions of the original string
        -next step is to get rid of the parentheses so if we found any one get a value for it
        -add all numbers and opreators in a stringstream now the sub problem is to solve an equation consisits of integers and * and + which can be solved in many easy ways.
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

string x;
int p[100005];
bool e;

ll go(int l, int r)
{
    //cout << l << " " << r << endl;
    if(l > r)
    {
        e = 1;
        return 0;
    }
    stringstream s;
    int ls = 0;
    for(int i=l; i<=r; i++)
    {
        if(x[i] <= '9' && x[i] >= '0')
        {
            if(ls) e=1;
            ll n = 0;
            while(x[i] <= '9' && x[i] >= '0')
                n = n*10 + (x[i++] - '0');
            i--;
            s << n;
            ls = 1;
        }
        else if(x[i] == '(')
        {
            if(ls) e=1;
            s << go(i+1,p[i]-1);
            i = p[i];
            ls = 1;
        }
        else if(x[i] == '+' || x[i] == '*')
        {
            if(!ls) e=1;
            s << ' ' << x[i] << ' ';
            ls = 0;
        }
    }
    if(!ls) e=1;
    if(e)
        return 0;
    char op;
    ll a,b,n=0;
    s >> a;
    while(s >> op >> b)
    {
        if(op == '*')
        {
            b*=a;
        }
        else
        {
            n+=a;
        }
        a = b;
    }
    n+=a;
    return n;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    cin.ignore();
    while(T--)
    {
        getline(cin,x);
        e = false;
        stack<int> r;
        for(int i=0; i<x.size(); i++)
        {
            if(x[i] == '(')
                r.push(i);
            else if(x[i] == ')')
            {
                if(r.empty())
                    e = 1;
                else
                {
                    p[r.top()] = i;
                    r.pop();
                }
            }
            else if (x[i] == '+') {}
            else if (x[i] == '*') {}
            else if(x[i] > '9' || x[i] < '0')
                e = 1;
        }
        if(!r.empty()) e = 1;
        ll t=0;
        if(!e)
            t = go(0,x.size()-1);
        if(e)
            printf("ERROR\n");
        else
        {
            cout << t << "\n";
        }
    }
    return 0;
}
