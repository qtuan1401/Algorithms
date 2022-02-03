#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int goal[MXN], flip[MXN], par[MXN], in[MXN];
vector < int > adj[MXN], ans;
int res, n;

void buildTree(int u) {
    flip[u] = flip[par[par[u]]];
    if ((in[u] ^ flip[u]) != goal[u]) {
        flip[u] ^= 1;
        ans.push_back(u);
    }
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == par[u])
            continue;
        par[v] = u;
        flip[v] = flip[par[u]];
        buildTree(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        cin >> in[i];
    for(int i = 1; i <= n; i++)
        cin >> goal[i];
    buildTree(1);
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    return 0;
}