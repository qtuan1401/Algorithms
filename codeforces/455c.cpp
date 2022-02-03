#include <bits/stdc++.h>

using namespace std;

const int MXN = 3e5  + 10;

int n, m, q;
int f[MXN], dst[MXN], root[MXN];
vector < int > adj[MXN];

int findRoot(int x) {
    if (root[x] < 0)
        return x;
    return root[x] = findRoot(root[x]);
}

void merge(int & u, int & v) {
    if ((u = findRoot(u)) == (v = findRoot(v)))
        return ;
    if (root[u] > root[v])
        swap(u, v);
    root[u] += root[v];
    root[v] = u;
    
}

void dfs(int u, int p) {
    merge(p, u);
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (root[v] == -1) {
            dfs(v, p);
            f[p] = max(f[p], dst[u] + dst[v] + 1);
            dst[u] = max(dst[u], dst[v] + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        root[i] = -1;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if (root[i] == -1) 
            dfs(i, i);

    while (q--) {
        int type, x;
        cin >> type >> x;
        if(type == 1)
            cout<< f[findRoot(x)]<<'\n';
        else {
            int y;
            cin >> y;
            x = findRoot(x); y = findRoot(y);
            if (x != y) {
                merge(x, y);
                f[x] = max(max(f[x], f[y]), (f[x] + 1) / 2 + (f[y] + 1) / 2 + 1);
            }
        }
    }
    return 0;
}