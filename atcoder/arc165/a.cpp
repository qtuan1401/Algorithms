#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int color) {
    
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dfs(1, 0);
    }
    return 0;
}