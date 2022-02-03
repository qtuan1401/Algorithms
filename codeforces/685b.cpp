#include <bits/stdc++.h>

using namespace std;

const int MXN = 3e5 + 10;

vector < int > adj[MXN];
int sz[MXN], par[MXN], biggest[MXN], centroid[MXN];
int n, q;

inline bool check(int v, int c) {
	return ((sz[v] - sz[c]) * 2 <= sz[v] && biggest[c] * 2 <= sz[v]);
}

void buildTree(int u) {
	sz[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        par[v] = u;
		buildTree(v);
		sz[u] += sz[v];
		biggest[u] = max(biggest[u], sz[v]);
	}
}

void findCentroid(int u) {
	if (sz[u] == 1) 
		centroid[u] = u;
	else {
		int vtx = -1;
		for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
			findCentroid(v);
            if (vtx == -1 || sz[vtx] < sz[v])
                vtx = v;
		}
		int c = centroid[vtx];
		while (!check(u, c))
			c = par[c];
		centroid[u] = c;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int v;
        cin >> v;
        adj[v].push_back(i + 1);
    }

	buildTree(1);
	findCentroid(1);

    while (q--) {
        int v;
        cin >> v;
        cout << centroid[v] << '\n';
    }
	return 0;
}