/*
 Author: Abdulla Ashraf
 Idea:
 -use tarjan to transfrom graph to DAG and get all sources
 -check all unused nodes if adding them will reduce the average
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
#define MAXN (101)
#define MAXC (500 * 499 / 2 + 1)

typedef long long ll;
typedef complex<double> point;
#define X real()
#define Y imag()

const int N = (1 << 19);
const int OO = 1 * 1e9;

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
			}
		}
}

struct AntarcticaPolice {
	double minAverageCost(vector<int> costs, vector<string> roads) {
		int n = costs.size();
		adjList.resize(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (roads[i][j] == 'Y')
					adjList[i].pb(j);
		scc();
		computeCompGraph();
		double avg = 0;
        int v=0;
		for (int i = 0; i < comps.size(); i++)
			if (inDeg[i] == 0) {
            	v++;
				int mn = 2000, mni = 0;
				for (int it : comps[i])
					if (mn > costs[it]) {
						mn = costs[it];
						mni = it;
					}
				avg += mn;
				costs[mni] = 2000;
			}
		avg /= v;
		sort(costs.begin(), costs.end());
		int i = 0;
		while (i < n && costs[i] < avg) {
			avg = ((avg * v) + costs[i]) / (v + 1);
			v++;
            i++;
		}
		return avg;
	}
};
