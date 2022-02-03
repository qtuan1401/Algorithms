#include<bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int n, m, dst;
int a[MXN], depth[MXN], vis[100005];
vector< int > adj[MXN];

void dfs(int u,int p) {
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> dst;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int i = 1;i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int u = 1, v = 1, ans = 0;
    dfs(a[1], 0);
    for(int i = 2; i <= m; i++)
        if (depth[a[i]] > depth[a[u]])
            u = i;
    depth[a[u]] = 0;
    dfs(a[u], 0);
    for(int i = 2; i <= m; i++)
        if(depth[a[i]] > depth[a[v]])
            v = i;
    for(int i = 1; i <= n; i++)
        if(depth[i] > dst)
            vis[i] = 1;
    depth[a[v]] = 0;
    dfs(a[v], 0);
    for(int i = 1; i <= n; i++)
        if (!vis[i] && depth[i] <= dst)
            ans++;

    cout << ans;
    return 0;
}