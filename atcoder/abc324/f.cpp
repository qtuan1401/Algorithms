#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;
typedef pair < int, II > III;

vector < vector < III > > adj;

typedef pair < long double, long double > DD;
typedef pair < pair < long double, int >, DD > DIDD;

vector < long double > f;

void dijkstra() {
    priority_queue < DIDD > heap;
    heap.push({{0, 0}, {0, 0}});
    f[0] = 0;
    while (heap.size()) {
        DIDD cur = heap.top(); heap.pop();
        long double w = cur.first.first;
        int u = cur.first.second;
        long double sb = cur.second.first;
        long double sc = cur.second.second;

        for (auto & p : adj[u]) {
            int v = p.first, b = p.second.first, c = p.second.second;
            long double w = (sb + b) / (sc + c);
            // cout << u << " " << v << " " << w << endl;
            if (f[v] < w) {
                f[v] = w;
                heap.push({{f[v], v}, {sb + b, sc + c}});
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
        int n, m;
        cin >> n >> m;
        adj.resize(n);
        for (int i = 0; i < m; i++) {
            int u, v, b, c;
            cin >> u >> v >> b >> c;
            u--; v--;
            adj[u].push_back({v, {b, c}});
        }

        f.resize(n, -1);
        dijkstra();

        cout << fixed << setprecision(11);
        cout << f[n - 1] << '\n';
    }
    return 0;
}