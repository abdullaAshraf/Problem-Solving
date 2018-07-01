/*
 Author: Abdulla Ashraf
 Idea:
 -use strongly connected compnents to convert graph to DAG
 -add parents to all roots or childs to all leafs to make the DAG one cycle
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

vector<vector<int> > adjList, comps, dagList;
vector<int> inStack, lowLink, dfn, comp, inDeg, outDeg;
stack<int> stk;
int ndfn, cntSrc, cntSnk;

void tarjan(int node) {
	lowLink[node] = dfn[node] = ndfn++, inStack[node] = 1;
	stk.push(node);

	for (int i = 0; i < adjList[node].size(); i++) {
		int ch = adjList[node][i];
		if (dfn[ch] == -1) {
			tarjan(ch);
			lowLink[node] = min(lowLink[node], lowLink[ch]);
		} else if (inStack[ch])
			lowLink[node] = min(lowLink[node], dfn[ch]);
	}

	if (lowLink[node] == dfn[node]) {
		comps.push_back(vector<int>());
		int x = -1;
		while (x != node) {
			x = stk.top(), stk.pop(), inStack[x] = 0;
			comps.back().push_back(x);
			comp[x] = sz(comps) - 1;
		}
	}
}

void scc() {
	int n = sz(adjList);

	inStack.clear();
	inStack.resize(n);
	lowLink.clear();
	lowLink.resize(n);
	dfn.clear();
	dfn.resize(n, -1);
	ndfn = 0;

	comp.clear(), comp.resize(n);
	comps.clear();

	for (int i = 0; i < n; i++)
		if (dfn[i] == -1)
			tarjan(i);
}

void computeCompGraph() {
	int csz = comps.size(), cntSrc = csz, cntSnk = csz;

	outDeg.clear();
	outDeg.resize(csz);
	inDeg.clear();
	inDeg.resize(comps.size());
	dagList.clear();
	dagList.resize(csz);	//will contain duplicates

	for (int i = 0; i < sz(adjList); i++)
		for (int j = 0; j < sz(adjList[i]); j++) {
			int k = adjList[i][j];
			if (comp[k] != comp[i]) {
				dagList[comp[i]].push_back(comp[k]);	//reverse
				if (!(inDeg[comp[k]]++))
					cntSrc--;
				if (!(outDeg[comp[i]]++))
					cntSnk--;
			} else
				;	// this edge is for a component comp[k]
		}

	if (comps.size() == 1)
		cout << "0\n";
	else {
		cout << max(cntSrc, cntSnk) << "\n";
	}

}

int main() {
	int T, n, a, b, m;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		adjList.clear();
		adjList.resize(n);
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adjList[a - 1].pb(b - 1);
		}
		scc();
		computeCompGraph();
	}
	return 0;
}
