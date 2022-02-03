#include <bits/stdc++.h>

using namespace std;

const int MXN = 3e3 + 10;

typedef pair< int, int> II;
typedef pair< int, II> III;
vector < III > adj[MXN];
int l[MXN], r[MXN];
int pos, n, m, mn, mx;
bool vis[MXN];

void dfs(int u) {
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        int l = adj[u][i].second.first;
        int r = adj[u][i].second.second;
        if (!vis[v] && l <= mn && mx <= r)
            dfs(v);
    }
}

bool check(int val) {
    bool ok = false;
    for(int i = 1; i <= m; i++) {
        mn = l[i];
        mx = l[i] + val;
        for(int i = 1; i <= n; i++)
            vis[i] = false;
        dfs(1);
        if (vis[n])
            ok = true;
    }
    return ok;
}
void bs(int l, int r) {
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else r = mid;
    }
    if (l == -1)
        cout << "Nice work, Dima!";
    else cout << l + 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v >> l[i] >> r[i];
        adj[u].push_back(III(v, II(l[i], r[i])));
        adj[v].push_back(III(u, II(l[i], r[i])));
    }
    bs(-1, 1e6 + 10);
}
