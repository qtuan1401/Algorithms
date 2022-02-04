#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > PII;

vector < vector < PII > > adj;
vector < int > ans;

void dfs(int u, int p, int edge) {
    for (PII &v : adj[u]) {
        if (v.first == p) continue;
        ans[v.second] = 1 - edge;
        edge = 1 - edge;
        dfs(v.first, u, edge);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        adj.resize(n);
        for (int i = 0; i < n; i++)
            adj[i].clear();
        ans.resize(n - 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(PII(v, i));
            adj[v].push_back(PII(u, i));
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() > 2) {
                ok = false;
                break;
            } 
        }
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        dfs(0, 0, 1);
        for (int i = 0; i < n - 1; i++)
            cout << (ans[i] == 0 ? 2 : 3) << " ";
        cout << '\n';
    }
    return 0;
}