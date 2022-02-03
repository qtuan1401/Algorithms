#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const long long INF = 1e18;

typedef pair < int, int > II;

struct node {
    int v, id;
    long long w;
    node(const long long _w = 0, const int _v = 0, const int _id = 0) {
        v = _v;
        w = _w;
        id = _id;
    } 
    bool operator < (const node & temp) const {
        return (w > temp.w);
    }
};

vector < node > adj[MAXN];
long long dist[MAXN][2];
priority_queue < node > heap;
int train[MAXN];
int n, m, k, res;

void dijkstra() {
    while (heap.size()) {
        node cur = heap.top(); heap.pop();
        int u = cur.v;
        long long w = cur.w;
        //cout << u << " " << w << " " << cur.id << endl;
        if (w > dist[u][cur.id])
            continue;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].v, id = adj[u][i].id;
            long long nw = adj[u][i].w;
            if (dist[v][id] > w + nw) {
                dist[v][id] = w + nw;
                heap.push(node(dist[v][id], v, id));
            }
        }
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(node(w, v, 0));
        adj[v].push_back(node(w, u, 0));
    }
    for(int i = 0; i < k; i++) {
        int v, w;
        cin >> v >> w;
        //cout << v << " * " << w << endl;
        if (train[v] > 0) {
            train[v] = min(train[v], w);
            res++;
        } else 
            train[v] = w;
    }

    for(int i = 2; i <= n; i++) {
        if (train[i] > 0) {
            adj[1].push_back(node(train[i], i, 1));
        }
    }
    //cout << res << endl;

    for(int i = 1; i <= n; i++)
        dist[i][0] = dist[i][1] = INF;
    dist[1][0] = 0;
    heap.push(node(0, 1, 0));
    dijkstra();
    //return 0;
    //cout << dist[2][0] << " " << dist[2][1] << endl;
    for(int i = 2; i <= n; i++) {
        if (dist[i][1] < INF)
            res += (dist[i][1] >= dist[i][0]);
    }
    cout << res;
    return 0;
}