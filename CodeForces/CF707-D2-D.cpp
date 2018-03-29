/*
 Author: Abdulla Ashraf
 Idea:
 	 -flat the table to 1D array
 	 -use persistent segment tree with lazy propagation
 	 -update for the 1st and 2nd were u just set the index to the value
 	 -update range for the 3rd
 	 -return to current state for the 4th
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

const int N = (1 << 20);
const ll OO = (ll) 1 * 1e18;

struct Node;
Node* empty;

struct Node {
	int sum, lazy;
	Node * lft, *rit;
	Node() {
		lft = rit = this;
		sum = 0;
		lazy = 0;
	}
	Node(int s, Node* l = empty, Node* r = empty, int lz = 0) {
		lft = l;
		rit = r;
		sum = s;
		lazy = lz;
	}
};

Node* build(int ns, int ne) {
	if (ns == ne)
		return new Node(0);
	int med = ns + ((ne - ns) >> 1);
	Node* lf = build(ns, med);
	Node* rt = build(med + 1, ne);
	return new Node(lf->sum + rt->sum, lf, rt);
}

void propagte(Node* cur, int l, int r) {
	if (cur->lazy) {
		cur->sum = (r - l + 1) - cur->sum;
		if (l != r) {
			cur->lft = new Node(cur->lft->sum, cur->lft->lft, cur->lft->rit,
					cur->lft->lazy ^ 1);
			cur->rit = new Node(cur->rit->sum, cur->rit->lft, cur->rit->rit,
					cur->rit->lazy ^ 1);
		}
		cur->lazy = 0;
	}
}

void print(Node* cur, int x, int y, int l = 1, int r = N) {
	if (l >= x && r <= y)
		cout << l << "-" << r << ": " << cur->sum << " " << cur->lazy << endl;
	if (l == r)
		return;
	int med = l + ((r - l) >> 1);
	print(cur->lft, x, y, l, med);
	print(cur->rit, x, y, med + 1, r);
}

Node* update(Node* cur, int ns, int ne, int in, int val) {
	propagte(cur, ns, ne);
	if (in < ns || in > ne)
		return cur;
	if (ns == ne)
		return new Node(val);
	int med = ns + ((ne - ns) >> 1);
	Node* lf = update(cur->lft, ns, med, in, val);
	Node* rt = update(cur->rit, med + 1, ne, in, val);
	return new Node(lf->sum + rt->sum, lf, rt);
}

Node* updateRange(Node* cur, int l, int r, int x, int y) {
	propagte(cur, l, r);
	if (l > y || x > r)
		return cur;
	if (l >= x && r <= y) {
		Node * n = new Node(cur->sum, cur->lft, cur->rit);
		n->lazy ^= 1;
		propagte(n, l, r);
		return n;
	}
	int mid = l + ((r - l) >> 1);
	Node* lf = updateRange(cur->lft, l, mid, x, y);
	Node* rt = updateRange(cur->rit, mid + 1, r, x, y);
	return new Node(lf->sum + rt->sum, lf, rt);
}

Node* roots[100005];

int main() {
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
	int n, m, q, t, a, b;
	cin >> n >> m >> q;
	empty = new Node;
	roots[0] = build(1, N);
	for (int i = 1; i <= q; i++) {
		//print(roots[0], 1, 16);
		cin >> t;
		if (t == 1) {
			cin >> a >> b;
			roots[i] = update(roots[i - 1], 1, N, (a - 1) * m + b, 1);
			cout << roots[i]->sum << "\n";
		} else if (t == 2) {
			cin >> a >> b;
			roots[i] = update(roots[i - 1], 1, N, (a - 1) * m + b, 0);
			cout << roots[i]->sum << "\n";
		} else if (t == 3) {
			cin >> a;
			roots[i] = updateRange(roots[i - 1], 1, N, (a - 1) * m + 1, a * m);
			cout << roots[i]->sum << "\n";
		} else {
			cin >> a;
			roots[i] = roots[a];
			cout << roots[i]->sum << "\n";
		}
	}
	return 0;
}
