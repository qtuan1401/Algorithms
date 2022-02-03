#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int par[MXN], a[MXN];
vector < int > adj[MXN];
int n, q;

void dfs(int u, int p) {
    par[u] = p;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (par[u] == v)
            continue;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int v;
            cin >> v;
            int pos = 0;
            for(pos = par[v]; pos > 0; pos = par[pos])
                if (__gcd(a[pos], a[v]) > 1)
                    break;
            if (pos == 0)
                cout << "-1\n";
            else
                cout << pos << '\n';
        } else {
            int v, w;
            cin >> v >> w;
            a[v] = w;
        }
    }
    return 0;
}