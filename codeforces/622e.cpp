#include <bits/stdc++.h>

using namespace std;

const int md = 1e6 + 10;

vector < int > adj[md], leaves;
int n, res = 0;

void dfs(int u, int par, int level) {
    if (adj[u].size() == 1) leaves.push_back(level);
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == par) continue;
        dfs(v, u, level + 1);
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < adj[1].size(); i++) {
        leaves.clear(); 
        dfs(adj[1][i], 1, 1);
        sort(leaves.begin(), leaves.end());
        res = max(res, leaves[0]);
        for(int j = 1; j < leaves.size(); j++) 
            leaves[j] = max(leaves[j - 1] + 1, leaves[j]);
        res = max(res, leaves.back());
    }
    cout << res;
    return 0;
}