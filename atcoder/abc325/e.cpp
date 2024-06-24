#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair < int, int > pii;
typedef pair < ll, pii > pli;

const ll INF = 1e18;

int n;
ll a, b, c;
vector < vector < ll > > f;
vector < vector < pii > > adj;

void dijkstra() {
    priority_queue < pli, vector < pli >, greater < pli > > heap;
    f.resize(n, vector < ll > (2));
    heap.push({0, {0, 0}});
    heap.push({0, {0, 1}});
    for (int i = 0; i < n; i++) {
        f[i][0] = f[i][1] = INF;
    }

    f[0][0] = 0;
    f[0][1] = 0;

    while (heap.size()) {
        pli cur = heap.top(); heap.pop();
        long long w = cur.first;
        int u = cur.second.first;
        int k = cur.second.second;

        if (f[u][k] != w) continue;

        for (auto & edge : adj[u]) {
            int nw = edge.second;
            int v = edge.first;
            
            if (f[v][1] > w + b * nw + c) {
                f[v][1] = w + b * nw + c;
                heap.push({f[v][1], {v, 1}});
            }

            if (k == 0) {
                if (f[v][0] > w + a * nw) {
                    f[v][0] = w + a * nw;
                    heap.push({f[v][0], {v, 0}});
                }
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        cin >> n >> a >> b >> c;
        adj.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ll x;
                cin >> x;
                adj[i].push_back({j, x});
                adj[j].push_back({i, x});
            }
        }

        dijkstra();

        cout << min(f[n - 1][0], f[n - 1][1]) << '\n';
    }
    return 0;
}