#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > adj, val, group(2);
int a, b;

void dfs(int u, int p, int depth) {
    // cout << u + 1 << endl;
    group[depth].push_back(u);
    for (int & v : adj[u]) {
        if (v == p) continue; 
        dfs(v, u, depth ^ 1);  
    }
}

int highestBit(int x) {
    for (int i = 20; i >= 0; i--)
        if ((x >> i) & 1) return i;
    return 0;
}

int main() {
    // freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        adj.clear();
        adj.resize(n);
        group.clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int lim = highestBit(n);
        val.clear();
        val.resize(lim + 1);
        for (int i = 1; i <= n; i++)
            val[highestBit(i)].push_back(i);
        dfs(0, 0, 0);
        vector < int > ans(n);
        for (int i = lim; i >= 0; i--) {
            int cur = 0;
            if (group[cur].size() < group[cur ^ 1].size()) cur ^= 1;
            for (int &v : val[i]) {
                ans[group[cur].back()] = v;
                group[cur].pop_back();
            }
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}