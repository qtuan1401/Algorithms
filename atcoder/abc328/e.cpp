#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, long long > pii;

int n, m;

bool valid;
long long ans, k;

vector < int > vst, marked;
vector < pair < int, pii > > edges;
vector < vector < pii > > adj;

void dfs(int u, int p, long long & sum) {
    vst[u] = true;
    for (auto & edge : adj[u]) {
        int v = edge.first;
        long long w = edge.second;
        if (vst[v]) continue;
        sum += w;
        sum %= k;
        dfs(v, u, sum);
    }
}

int calc() {
    int sum = 0;
    for (int i = 0; i < m; i++) sum += marked[i];
    return sum;
}

void gen(int i) {
    if (calc() == n - 1) { 
        adj.clear();
        adj.resize(n);
        for (int j = 0; j < m; j++) {
            if (marked[j]) {
                int u = edges[j].first, v = edges[j].second.first;
                long long w = edges[j].second.second;
                adj[u].push_back(pii(v, w));
                adj[v].push_back(pii(u, w));
            }
        }

        long long sum = 0;
        valid = true;
        for (int j = 0; j < n; j++) vst[j] = false;
        dfs(0, -1, sum);
        for (int j = 0; j < n; j++) {
            if (vst[j] == false) valid = false;
        }
        if (valid) ans = min(ans, sum);
        return;
    }
    if (i == m) return;
    for (int j = 0; j <= 1; j++) {
        marked[i] = j;
        gen(i + 1);
        marked[i] = 0;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        cin >> n >> m >> k;
        ans = k;
        marked.resize(m, 0);
        vst.resize(n, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            u--; v--;
            edges.push_back(make_pair(u, pii(v, w)));
        }
        gen(0);

        cout << ans << '\n';
    }
    return 0;
}