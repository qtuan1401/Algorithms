#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > adj;
vector < int > fin, h;
vector < long long > f;

int calc(int u, int v) {
    if (h[u] < h[v]) return 2 * (h[u] - h[v]);
    return h[u] - h[v];
}

void dfs(int u) {
    fin[u] = 1;

    // int cnt = 0;
    // for (int &v : adj[u]) {
    //     if (fin[v] == 1) continue;

    // }
    for (int &v: adj[u]) {
        if (fin[v] == 1) continue;
        if (fin[v] == 2) {
            f[u] = max(f[u], max(0ll, max(0ll, f[v]) + calc(u, v)));
            continue;
        }
        dfs(v);
        f[u] = max(f[u], max(0ll, max(0ll, f[v]) + calc(u, v)));
    }
    fin[u] = 2;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    h.resize(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    adj.resize(n);
    fin.resize(n, 0);
    f.resize(n, -1e18);
    f[0] = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);

    cout << f[0] << '\n';
    return 0;
}