#include <bits/stdc++.h>

using namespace std;

const int md = 1e5 + 10;

vector < int > adj[md];
bool vis[md];
int n, m, cnt;

void dfs(int u) {
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (vis[v]) continue;
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if (!vis[i]) {
            cnt++;
            dfs(i);
        }
    cout << cnt + m - n;
    return 0;
}