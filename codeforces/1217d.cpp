#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10;

typedef pair < int, int > II;

int vis[MAXN], col[MAXN];
vector < II > adj[MAXN];
int n, m, ans = 1;

void dfs(int u) {
    vis[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first, edge = adj[u][i].second;
        if (vis[v] > 0) {
            if (vis[v] == 1)
                col[edge] = 1, ans = 2;
        } else {
            dfs(v);
        }
    }
    vis[u] = 2;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(II(v, i));
        //adj[v].push_back(II(u, i));
    }
    for(int i = 1; i <= n; i++)
        if (vis[i])
            dfs(i);
    cout << ans << '\n';
    for(int i = 0; i < m; i++)
        cout << col[i] + 1 << " ";
    return 0;
}