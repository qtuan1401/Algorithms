#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

vector < int > adj[MXN];
int s[MXN], a[MXN];
long long res;
int n, k;

void dfs(int u, int p) {
    s[u] = a[u];
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        dfs(v, u);
        res += min(s[v], k * 2 - s[v]);
        s[u] += s[v];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < 2 * k; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1);
    cout << res;
    return 0;
}