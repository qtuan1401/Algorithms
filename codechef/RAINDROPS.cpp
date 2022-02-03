#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > adj; 
vector < int > f, leaf;

void dfs(int u, int p) {
    if (adj[u].size() == 1 && u != 0) {
        leaf.push_back(f[u]);
        return ;
    }
    for (int & v : adj[u]) {
        if (v == p) continue;
        f[v] = f[u] + 1;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        adj.resize(n);
        f.resize(n);
        leaf.clear();
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            f[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, 0);
        sort(leaf.begin(), leaf.end());
        vector < long long > sum(leaf.size(), 0);
        sum[0] = leaf[0];
        for (int i = 1; i < sum.size(); i++)
            sum[i] = sum[i - 1] + leaf[i];
        vector < int > wind(m);
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            cin >> wind[i];
            int diff;
            if (i == 0) {
                diff = wind[i];
            } else {
                diff = wind[i] - wind[i - 1];
            }
            int pos = upper_bound(leaf.begin(), leaf.end(), diff) - leaf.begin();
            if (pos != 0) {
                ans += 1ll * diff * pos - sum[pos - 1];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}