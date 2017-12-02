#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool p[10000001];
ll a[10000001];

void seive(int n){
	memset(p,1,sizeof p);
	p[0] = p[1] = 0;
	for(int i=2; i*i <= n ; i++)if(p[i]){
		for(int j=i*i; j<=n;j+=i)
			p[j] = 0;
	}
}

vector<int> x;

int main() {
	int n,m,t,l,r;
	scanf("%d",&n);
	seive(10000000);
	for(int i=2; i<=100000; i++)
		if(p[i]) x.push_back(i);
	for(int i=0; i<n; i++){
		scanf("%d",&t);
		for(auto it : x){
			if(it*it > t)break;
			if(t%it == 0)
				a[it]++;
			while(t%it == 0)
				t/=it;
		}
		if(t != 1)a[t]++;
	}
	for(int i=2; i<10000001; i++)
		a[i] += a[i-1];
	scanf("%d",&m);
	for(int i=0; i<m; i++){
		scanf("%d",&l);
		scanf("%d",&r);
		r = min(r,10000000);
		l = min(l,10000000);
		ll ans = a[r] - a[l-1];
		printf("%I64d\n",ans);
	}

	return 0;
}
