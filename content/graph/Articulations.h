/**
 * Author: Josh Taylor
 * Date: 2024-05-22
 * Description: Used to find articulation points in an undirected graph. Can be easily modified to find bridges.
 * Status: tested on CF 652E
 */
#pragma once

vi ti, lo;
vector<vi> g;
set<int> art; // vector<pii> for bridges
int timer;
void dfs(int u, int p = -1) {
	ti[u] = lo[u] = ++timer;
	int c = 0;
	for (auto v : g[u]) {
		if (v == p) continue;
		if (ti[v] != -1) lo[u] = min(lo[u], ti[v]);
		else {
			dfs(v, u);
			lo[u] = min(lo[u], lo[v]);
			if (lo[v] >= ti[u] && !(p == -1)) // (lo[v] > ti[u]) for bridges
				art.insert(u);
			++c;
		}
	}
	if (p == -1 && c > 1) art.insert(u); // remove for bridges
}

void find_articulations() {
	timer = 0;
	ti.assign(n, -1);
	lo.assign(n, -1);
	rep(i, 0, n) if (ti[i] == -1) dfs(i);
}
