#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;
typedef pair < long long, int > pli;

vector < vector < pii > > adj;
vector < int > a;

const long long INF = 1e18;

void dijsktra(int n) {
    vector < long long > f(n, INF);
    f[0] = a[0];
    priority_queue < pli, vector < pli >, greater < pli > > heap;
    heap.push(pli(f[0], 0));
    while (heap.size()) {
        pli cur = heap.top(); heap.pop();
        long long w = cur.first;
        int u = cur.second;

        if (f[u] != w) continue;

        for (auto & p : adj[u]) {
            int v = p.first;
            int val = p.second;

            if (f[v] > f[u] + val + a[v]) {
                f[v] = f[u] + val + a[v];
                heap.push(pli(f[v], v));
            }
        }
    }

    for (int i = 1; i < n; i++) cout << f[i] << " ";
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
        a.resize(n);
        adj.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;

            adj[u].push_back(pii(v, w));
            adj[v].push_back(pii(u, w));
        }

        dijsktra(n);
    }
    return 0;
}