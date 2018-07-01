/*
 Author: Abdulla Ashraf
 Idea:
 -use simple loop to transfer string to tree
 -use canonical form to compare two trees
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

vector<vector<int>> x;
int p[3001];

string getNodeCanoincalForm(int v, vector<vector<string> > &subCan) {
	string nodeRep = "(";
	sort(subCan[v].begin(), subCan[v].end());
	for (int i = 0; i < subCan[v].size(); i++)
		nodeRep += subCan[v][i];
	nodeRep += ")";

	return nodeRep;
}

string treeCanoincalForm() {
	int n = sz(x);

	// Prepare level one nodes: the leaves
	queue<int> LeafNodes;
	vector<int> deg(n, -1);
	int remNodes = n;

	for (int i = 0; i < x.size(); i++) {
		if (sz(x[i]) <= 1)
			LeafNodes.push(i);
		else
			deg[i] = sz(x[i]);
	}

	vector<vector<string> > subCan(n);

	while (remNodes > 2)  // bfs-like
	{
		int sz = sz(LeafNodes);
		while (sz--) // level by level
		{
			int v = LeafNodes.front();
			LeafNodes.pop();

			string nodeRep = getNodeCanoincalForm(v, subCan);

			for (int j = 0; j < x[v].size(); j++) {
				int to = x[v][j];
				subCan[to].push_back(nodeRep);
				if (--deg[to] == 1)
					LeafNodes.push(to);
			}
			--remNodes;
		}
	}

	// what remains are tree centers
	int v1 = LeafNodes.front();
	LeafNodes.pop();
	int v2 = LeafNodes.empty() ? -1 : LeafNodes.front();

	string str1 = getNodeCanoincalForm(v1, subCan);
	string str2 = v2 == -1 ? "" : getNodeCanoincalForm(v2, subCan);

	if (v2 == -1)    // only 1 node
		return str1;

	// 2 nodes. try 2nd as child of first and reverse
	subCan[v1].push_back(str2);
	subCan[v2].push_back(str1);

	return min(getNodeCanoincalForm(v1, subCan),
			getNodeCanoincalForm(v2, subCan));
}

string transform(string a) {
	x.clear();
	x.resize(1);
	int cur = 0, cnt = 1;
	for (auto it : a) {
		if (it == '0') {
			p[cnt] = cur;
			x.pb(vector<int>());
			x[cur].pb(cnt);
			x[cnt].pb(cur);
			cur = cnt++;
		} else
			cur = p[cur];
	}
	return treeCanoincalForm();
}

int main() {
	int T;
	cin >> T;
	string a, b;
	while (T--) {
		cin >> a >> b;
		if (transform(a) == transform(b))
			cout << "same\n";
		else
			cout << "different\n";
	}
	return 0;
}
