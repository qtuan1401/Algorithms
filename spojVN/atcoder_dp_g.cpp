#include <bits/stdc++.h>

using namespace std;

vector < int > f;
vector < vector < int > > adj;

int res;

void dfs(int u) {
    if (adj[u].size() == 0) {
        f[u] = 1;
        return ;
    }
    for (int & v : adj[u]) {
        if (f[v] == 0)
            dfs(v);
        f[u] = max(f[u], f[v]);
    }
    
    res = max(res, f[u]++);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }

    f.resize(n);
    for (int i = 0; i < n; i++)
        if (f[i] == 0)
            dfs(i);

    cout << res;
    return 0;
}