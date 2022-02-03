#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

typedef pair < int, int > II;

vector < II > adj[MAXN];
bool marked[MAXN];
int sz[MAXN];
long long sumMin, sumMax;
int n;

void dfsMin(int u, int p) {
    int cnt = 0;
    sz[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first, w = adj[u][i].second;
        if (v == p)
            continue;
        dfsMin(v, u);
        sz[u] += sz[v];
        sumMin += (sz[v] % 2 == 1 ? w : 0);
    }
}

long long findMin() {
    sumMin = 0;
    dfsMin(1, 0);
    return sumMin;
}

void dfsMax(int u, int p) {
    //sz[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first, w = adj[u][i].second;
        if (v == p)
            continue;
        dfsMax(v, u);
        //sz[u] += sz[v];
        sumMax += 1ll * w * min(sz[v], n - sz[v]); 
    }
}

long long findMax() {
    sumMax = 0;
    dfsMax(1, 0);
    return sumMax;
}

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        n *= 2;
        for(int i = 1; i <= n; i++) {
            marked[i] = false;
            adj[i].clear();
        }
        for(int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(II(v, w));
            adj[v].push_back(II(u, w));
        }
        cout << findMin() << " " << findMax() << '\n';
    }    
    return 0;
}