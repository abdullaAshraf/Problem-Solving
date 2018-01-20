/*
 * new
 *
 *  Created on: Dec 9, 2015
 *      Author: AbdullaAshraf
 */
#include<bits/stdc++.h>
using namespace std;

set<long long> lucky;

void gen(int i, long long n) {
	if (i == 11)
		return;
	lucky.insert(n * 10 + 4);
	lucky.insert(n * 10 + 7);
	gen(i + 1, n * 10 + 4);
	gen(i + 1, n * 10 + 7);
}

int main() {
	int l, r, i;
	long long total = 0;
	cin >> l >> r;
	gen(0,0);
	for(i = l; i <= r; i++){
	        auto it = lucky.lower_bound(i);
	        if(*it > r){
	            total += *it*(r-i+1);
	            break;
	        }
	        total += (*it-i+1)*(*it);
	        i = *it;
	    }
	cout << total << endl;
	return 0;
}
