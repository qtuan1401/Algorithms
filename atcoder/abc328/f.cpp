#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, long long > pii;

vector < int > dep, lab, u, v, w, par;
vector < long long > sum;
vector < vector < int > > jump;
vector < vector < int > > adj;

int n;

map < pii, long long > mp;

void dfs(int u, int p) {
    for (auto & v : adj[u]) {
        long long w = mp[pii(v, u)];
        if (v == p) continue;
        par[v] = u;
        dep[v] = dep[u] + 1;
        sum[v] = sum[u] + w;
        dfs(v, u);
    }
}

void getPar() {
    for (int i = 0; i < n; i++) {
        jump[i][0] = par[i];
    }

    for (int k = 1; k <= 17; k++)
        for (int i = 0; i < n; i++) 
            jump[i][k] = jump[jump[i][k - 1]][k - 1];
}

int getRoot(int x) {
    if (lab[x] < 0) return x;
    return lab[x] = getRoot(lab[x]);
}

bool merge(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);

    if (u == v) return false;

    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
    return true;
}

int lca(int u, int v) {
    if (dep[u] != dep[v]) {
        if (dep[u] < dep[v]) swap(u, v);
    
        int k = dep[u] - dep[v];
        for (int j = 0; (1 << j) <= 17; ++j)
            if (k >> j & 1)
                u = jump[u][j];
    }
    if (u == v) return u;

    for (int j = 17; j >= 0; --j)
        if (jump[u][j] != jump[v][j])
            u = jump[u][j], v = jump[v][j];
    return jump[u][0];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int m;
        cin >> n >> m;
        lab.resize(n, -1);
        adj.resize(n);
        u.resize(m); v.resize(m); w.resize(m);

        for (int i = 0; i < m; i++) {
            cin >> u[i] >> v[i] >> w[i];
            u[i]--; v[i]--;
            if (u[i] == v[i]) continue;
            if (merge(u[i], v[i])) {
                adj[u[i]].push_back(v[i]);
                adj[v[i]].push_back(u[i]);
                if (mp[pii(u[i], v[i])] == 0) {
                    mp[pii(u[i], v[i])] = w[i];
                    mp[pii(v[i], u[i])] = -w[i];
                }
            }
        }
        dep.resize(n, 0);
        par.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
        sum.resize(n, 0);
        jump.resize(n, vector < int > (18, 0));
        for (int i = 0; i < n; i++)
            if (par[i] == i) dfs(i, i);
        
        getPar();
        for (int i = 0; i < m; i++) {
            if (u[i] == v[i]) {
                if (w[i] == 0) cout << i + 1 << " "; 
                continue;
            }
            int z = lca(u[i], v[i]);
            long long su = sum[u[i]] - sum[z];
            long long sv = sum[v[i]] - sum[z];
            if (su - sv == w[i]) cout << i + 1 << " ";
        }
    }
    return 0;
}