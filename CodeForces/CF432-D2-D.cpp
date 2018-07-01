/*
 Author: Abdulla Ashraf
 Idea:
 -
 */

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define sqr(x) ((x) * (x))
const double PI = acos(-1.0);
const double EPS = 1e-9;

typedef long long ll;
#define INF 1000000007

const int mod = 7 + 1e9;
const int N = (1 << 19);
const ll OO = (ll) 1 * 1e9;

const int MAX = 26 + 1;		//+1 to assign starting from 1

char arr[100005], arr2[100005];

int nextNodeId = 0;

int cIdx(char c) {
	return 1 + c - 'A';
}

struct node {
	node* fail;
	node* child;
	vector<int> patIdx;
	char chars;
	int id;

	node() {
		child = 0;
		chars = 0;
		id = nextNodeId++;
	}

	void insert(char* str, int idx, bool firstCall = true) {
		if (firstCall) {
			char *t = str;
			while (*t)
				*t = cIdx(*t), t++;
		}
		if (!*str) {
			patIdx.pb(idx);
		} else {
			child = new node();
			chars = *str;
			patIdx.pb(idx);
			child->insert(str + 1, idx + 1, false);
		}
	}
};

void move(node* &k, char c) {
	while (k->id && k->chars != c)
		k = k->fail;
	if (k->id == 0 && k->chars != c)
		return;
	k = k->child;
}

node* buildAhoTree() {
	node * root = new node();

	strcpy(arr2, arr);
	root->insert(arr2, 0);
	queue<node*> q;

	q.push(root->child);
	root->child->fail = root;
	node* cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		int ch = cur->chars;
		if (ch) {
			q.push(cur->child);
			node* k = cur->fail;

			move(k, ch);

			cur->child->fail = k;

			cur->child->patIdx.insert(cur->child->patIdx.end(),
					k->patIdx.begin(), k->patIdx.end());
		}
	}
	return root;
}

void match(const char* str, node* root, vector<vector<int> > & res) {
	node* k = root;

	for (int i = 0; str[i]; i++) {
		move(k, cIdx(str[i]));
		for (int j = 0; j < k->patIdx.size(); j++)
			res[k->patIdx[j]].push_back(i);
	}
}

int main() {

	scanf("%s", arr);

	node* root = buildAhoTree();
	int k = strlen(arr);
	vector<vector<int> > res(k + 1);
	match(arr, root, res);

	vector<pair<int, int>> x;
	for (int i = 1; i <= k; i++)
		if (res[i].size() && res[i][res[i].size() - 1] == k - 1)
			x.pb(mp(i, res[i].size()));
	cout << x.size() << endl;
	for (auto it : x)
		cout << it.first << " " << it.second << "\n";
	return 0;
}
