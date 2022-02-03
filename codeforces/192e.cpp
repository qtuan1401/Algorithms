#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

const int LIM = 1e5 + 10;

vector < II > adj[LIM];
int n, m[LIM][30], d[LIM], f[LIM], ans[LIM];

void dfs(int u, int p) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (p == v)
            continue;
        d[v] = d[u] + 1;
        m[v][0] = u;
        dfs(v, u);
    }
}

void prepare() {
    for (int k = 1; k <= 20; k++)
        for (int i = 1; i <= n; i++)
            m[i][k] = m[m[i][k - 1]][k - 1];
}

int lca(int u, int v) {
    if (d[u] > d[v])
        return lca(v, u);
    
    for (int i = 20; i >= 0; i--)
        if (d[v] - (1 << i) >= d[u])
            v = m[v][i];
    
    if (v == u)
        return v;

    for (int i = 20; i >= 0; i--)
        if (m[u][i] != m[v][i]) {
            u = m[u][i];
            v = m[v][i];
        }
    return m[v][0];
}

void cnt(int u, int p) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (p == v)
            continue;
        cnt(v, u);
        ans[adj[u][i].second] = f[v];
        f[u] += f[v];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(II(v, i));
        adj[v].push_back(II(u, i));
        
    }

    dfs(1, 0);
    prepare();

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (u == v)
            continue;
        int z = lca(u, v);
        f[u]++; f[v]++; f[z] -= 2;
    }

    cnt(1, 0);

    for (int i = 1; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}