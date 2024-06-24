#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;


vector < vector < pii > > adj;
vector < int > lab, vst, trc, edge;

int getRoot(int x) {
    if (lab[x] < 0) return x;
    return lab[x] = getRoot(lab[x]);
}

int merge(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    cout << u << " | " << v << endl;
    if (u == v) return false;

    if (lab[u] > lab[v])
        swap(u, v);

    lab[u] += lab[v];
    lab[v] = u;
    return true;
}

void dfs(int u) {
    vst[u] = true;
    for (auto & p : adj[u]) {
        int v = p.first;
        int id = p.second;
        if (vst[v]) continue;
        trc[v] = u;
        dfs(v);
    }
}

void trace(int u, int v) {
    cout << u << " * " << v << endl;
    dfs(u);

    vector < int > ans;
    while (u != v) {
        cout << v << endl;
        ans.push_back(v);
        v = trc[v];
    }
    ans.push_back(u);

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    freopen("../test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;

        vector < pair < pair < int, int >, pair < int, int > > > edges(m); 
        adj.clear();
        adj.resize(n);
        lab.clear();
        lab.resize(n, -1);
        vst.clear();
        vst.resize(n, 0);
        edge.clear();
        edge.resize(n, 0);
        trc.clear();
        trc.resize(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            edges[i] = {{w, i}, {u, v}};
        }

        sort(edges.begin(), edges.end());
        reverse(edges.begin(), edges.end());

        for (int i = 0; i < m; i++) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int id = edges[i].first.second;
            if (merge(u, v)) {
                adj[u].push_back({v, id});
                adj[v].push_back({u, id});
            } else {
                
            }
        }

        for (int i = 0; i < m; i++) {

        }
    }
    return 0;
}