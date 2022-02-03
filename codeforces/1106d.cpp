#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

set < int > s;
vector < int > adj[MXN];
bool vis[MXN];
int n, m;

void bfs() {
    s.insert(1);
    vis[1] = 1;
    while (s.size()) {
        int u = *s.begin();
        s.erase(s.begin());
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (!vis[v]) {
                s.insert(v);
                vis[v] = 1;
            }
        }
        cout << u << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
	}
	bfs();
    return 0;
}