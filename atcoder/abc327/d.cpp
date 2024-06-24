#include <bits/stdc++.h>

#define vall(a) (a.begin(), a.end())

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

bool ok;
vector < vector < int > > adj;
vector < int > marked;

void dfs(int u, int val) {
    marked[u] = val;
    for (auto & v : adj[u]) {
        if (marked[v] != -1) {
            if (marked[v] == val) {
                ok = false;
            }
        } else {
            dfs(v, 1 - val);
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
        vector < int > a(m), b(m);
        for (int i = 0; i < m; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        adj.resize(n);
        ok = true;
        for (int i = 0; i < m; i++) {
            int u = a[i], v = b[i];
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        marked.resize(n, -1);
        for (int i = 0; i < n; i++) {
            if (marked[i] != -1) continue;
            dfs(i, 0);
        }

        if (!ok) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}