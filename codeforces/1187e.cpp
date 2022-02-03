#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

long long dq[MAXN], sz[MAXN];
vector < int > adj[MAXN];
int n;
long long ans = 0;

void calcSize(int u, int p) {
    sz[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        calcSize(v, u);
        sz[u] += sz[v];
    }
}

void calcSum(int u, int p) {
    dq[u] = sz[u];
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        calcSum(v, u);
        dq[u] += dq[v];
    }
}

void solve(int u, int p) {
    ans = max(ans, dq[u]);
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        dq[u] -= dq[v];
        dq[u] -= sz[v];
        sz[u] -= sz[v];
        dq[v] += dq[u];
        dq[v] += sz[u];
        sz[v] += sz[u];
        solve(v, u);
        dq[v] -= dq[u];
        dq[v] -= sz[u];
        sz[v] -= sz[u];
        dq[u] += dq[v];
        dq[u] += sz[v];
        sz[u] += sz[v];
    }
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

    calcSize(1, 0);
    calcSum(1, 0);
    solve(1, 0);

    cout << ans;
    return 0;
}