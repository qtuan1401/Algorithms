#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

typedef pair < int, int > II;
typedef pair < int, II > III;

pair < int, II > a[MAXN];
int lab[MAXN], mx[MAXN];
bool vis[MAXN];
vector < II > adj[MAXN];
int n, m;

int findRoot(int x) {
    if (lab[x] < 0)
        return x;
    return lab[x] = findRoot(lab[x]);
}

bool merge(int u, int v) {
    if ((u = findRoot(u)) == (v = findRoot(v)))
        return false;
    if (lab[u] > lab[v])
        swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
    return true;    
}

void kruskal() {
    for(int i = 1; i <= n; i++)
        lab[i] = -1;
    for(int i = 1; i < m; i++) {
        int u = a[i].second.first;
        int v = a[i].second.second;
        if (merge(u, v)) {
            adj[u].push_back(II(v, a[i].first));
            adj[v].push_back(II(u, a[i].first));
        }
    }
}

void dfs(int u) {
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        if (vis[v])
            continue;
        mx[v] = max(mx[u], adj[u][i].second);
        dfs(v);
    }
}

int calc(int u, int v) {
    for(int i = 1; i <= n; i++)
        mx[i] = -1;
    dfs(u);
    //for(int i = 1; i <= n; i++)
    //    cout << mx[i] << " ";
    if (mx[v] == -1)
        mx[v] = 1e9;
    return mx[v];
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = III(w, II(u, v));
    }
    sort(a + 1, a + m);
    kruskal();
    cout << calc(a[0].second.first, a[0].second.second);
    return 0;
}