#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

typedef pair < long long, int > II;

long long dist[MXN], a[MXN];
priority_queue < II, vector < II >, greater < II > > heap;
vector < II > adj[MXN];
int n, m;

void dijkstra() {
    for(int i = 1; i <= n; i++) {
        heap.push(II(a[i], i));
        dist[i] = a[i];
    }
    while (heap.size()) {
        II cur = heap.top(); heap.pop();
        int u = cur.second; long long w = cur.first;
        if (w != dist[u])
            continue;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].second;
            long long nw = adj[u][i].first;
            if (w + nw < dist[v]) {
                dist[v] = w + nw;
                heap.push(II(dist[v], v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        w *= 2;
        adj[u].push_back(II(w, v));
        adj[v].push_back(II(w, u));
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dijkstra();
    for(int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    return 0;
}