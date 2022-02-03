#include<bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int n;
int depth[MXN], st[MXN][20], child[MXN], par[MXN];
vector < int > adj[MXN];

void dfs(int u) {
	child[u] = 1;
	for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (par[u] == v)
            continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
        child[u] += child[v];
    }
}

void prepare() {
    for(int i = 1; i <= n; i++)
        st[i][0] = par[i];
    for(int k = 1; k <= 17; k++)
        for(int i = 1; i <= n; i++)
            st[i][k] = st[st[i][k - 1]][k - 1];
}

int lca(int x, int y) {
    if (depth[x] < depth[y])
        return lca(y, x);
    for(int i = 17; i >= 0; i--)
        if (depth[x] - (1 << i) >= depth[y])
            x = st[x][i];
    if (x == y)
        return x;
    for(int i = 17; i >= 0; i--)
        if (st[x][i] != st[y][i]) {
            x = st[x][i];
            y = st[y][i];
        }
    return par[x];
}

int findVtx(int x, int val) {
	for(int i= 17; i >= 0; i--)
		if ((val >> i) & 1)
			x = st[x][i];
	return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
	dfs(1);
    prepare();
    int q;
    cin >> q;
	while (q--) {
        int x, y;
        cin >> x >> y;
        if ((depth[x] + depth[y]) & 1) {
            cout << "0\n";
            continue;
        }
		int z = lca(x, y);
        if (depth[x] == depth[y]) {
            x = findVtx(x, depth[x] - depth[z] - 1);
            y = findVtx(y, depth[y] - depth[z] - 1);
            cout << n - child[x] - child[y] << '\n';
        } else {
            if (depth[x] < depth[y])
                swap(x, y);
            x = findVtx(x, (depth[x] + depth[y] - depth[z] * 2) / 2 - 1);
            cout << child[par[x]] - child[x] << '\n';
        }
	}
	return 0;
}