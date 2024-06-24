// atcoder abc305e

#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 1, -1, 0, -1, 0, 0, 1};
const int dy[] = {1, 0, 0, 1, 0, -1, -1, 0};

typedef pair < int, int > II;

priority_queue < II > heap;
vector < int > vst;
vector < vector < int > > adj;

void dijkstra() {
    while (heap.size()) {
        II pairs = heap.top(); heap.pop();
        int u = pairs.second;
        int val = pairs.first;
        if (vst[u] || val < 0) continue;
        vst[u] = true;
    
        for (int & v : adj[u]) {
            if (vst[v]) continue;
            heap.push({val - 1, v});
        }
    }
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m, k;
        cin >> n >> m >> k;
        adj.resize(n);
        vst.resize(n);
        for (int i = 0; i < n; i++) vst[i] = false;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        for (int i = 0; i < k; i++) {
            int p, h;
            cin >> p >> h;
            p--;
            heap.push({h, p});
        }

        dijkstra();
        vector < int > ans;
        for (int i = 0; i < n; i++)
            if (vst[i]) ans.push_back(i + 1);
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    }
    return 0;
}