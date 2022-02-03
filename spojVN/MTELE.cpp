#include <bits/stdc++.h>

using namespace std;

const int md = 5e3 + 10;
const int oo = 1e9 + 10;

struct node {
    int u, w;
    node(int _u = 0, int _w = 0) {
        u = _u;
        w = _w;
    }
};

vector < node > adj[md];
int z[md], f[md][md], a[md];
int n, m;

int dfs(int u) {
    f[u][0] = 0;
    if (u > n - m) {
        f[u][1] = a[u];
        return 1;
    }
    int child = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].u;
        int w = adj[u][i].w;
        child += dfs(v);
        //cout << u <<" " << child << endl;
        for(int j = 0; j <= child; j++)
            z[j] = -oo;
        for(int j = 0; j <= child; j++) {
            for(int k = 0; k <= j; k++)
                z[j] = max(z[j], f[u][j - k] + f[v][k] - w);
        }
        for(int j = 0; j <= child; j++)
            f[u][j] = max(f[u][j], z[j]);
    }
    return child;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
            f[i][j] = -oo;
    for(int i = 1; i <= n - m; i++) {
        int r;
        cin >> r;
        for(int j = 1; j <= r; j++) {
            int u, w;
            cin >> u >> w;
            adj[i].push_back(node(u, w));
        }
    }
    for(int i = n - m + 1; i <= n; i++)
        cin >> a[i];
    dfs(1);
    for(int i = m; i >= 1; i--) {
    //    cout << i << endl;
        if (f[1][i] >= 0) {
            cout << i;
            return 0;
        }
    }
}
