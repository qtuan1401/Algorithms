#include <bits/stdc++.h>

using namespace std;

const int md = 1e3 + 10;

int n;
long long child[md][md], par[md][md], dq[md][md];
vector < int > adj[md];

void dfs(int u, int root) {
    child[root][u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == par[root][u])
            continue;
        par[root][v] = u;
        dfs(v, root);
        child[root][u] += child[root][v];
    }
}

long long f(int u, int v) {
    if (u == v)
        return 0;
    if (dq[u][v] != -1)
        return dq[u][v];
    
    long long res = child[u][v] * child[v][u] + max(f(u, par[u][v]), f(par[v][u], v));
    return dq[u][v] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dq, -1, sizeof dq);
    for(int i = 1; i <= n; i++)
        dfs(i, i);

    long long res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            res = max(res, f(i, j));

    cout << res;
    return 0;
}