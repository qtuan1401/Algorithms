#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

typedef pair < long long, long long > II;

long long b[MXN];
int depth[MXN], par[MXN], m[MXN][25], a[MXN];
int n;
vector < int > adj[MXN];

void buildTree(int u) {
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        depth[v] = depth[u] + 1;
        buildTree(v);
    }
}

void prepare() {
    for(int i = 1; i <= n; i++)
        m[i][0] = par[i];

    for(int k = 1; k <= 20; k++)
        for(int i = 1; i <= n; i++)
            m[i][k] = m[m[i][k - 1]][k - 1]; 
}

int lca(int u, int v) {
    if (depth[u] > depth[v])
        return lca(v, u);
    for(int i = 20; i >= 0; i--)
        if (depth[v] - (1 << i) >= depth[u])
            v = m[v][i];
    if (v == u)
        return u;
    for(int i = 20; i >= 0; i--)
        if (m[u][i] != m[v][i]) {
            u = m[u][i];
            v = m[v][i];
        }
    return par[v];
}

inline bool ccw(II a, II b, II c) {
    return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second) > 0;
}

int pos[MXN * 100];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        pos[a[i]] = i;
    }
    vector < II > hill;
    hill.push_back(II(a[n], b[n]));
    for(int i = n - 1; i >= 1; i--) {
        while (hill.size() >= 2 && ccw(II(a[i], b[i]), hill[hill.size() - 1], hill[hill.size() - 2]))
            hill.pop_back();
        par[i] = pos[hill.back().first];
        //cout << i << " " << hill.back().first << " " << pos[hill.back().first] << endl;
        adj[pos[hill.back().first]].push_back(i);
        hill.push_back(II(a[i], b[i]));
    }
    buildTree(n);
    //for(int i = 1; i <= n; i++)
    //    cout << depth[i] << " ";
    prepare();
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << " ";
    }
    return 0;
}