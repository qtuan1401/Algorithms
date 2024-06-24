#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

vector < int > col, vst;
vector < vector < int > > adj;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

long long ans;

void dfs(int u, int c, int & sz) {
    col[u] = c;
    sz++;
    vst[u] = true;
    for (auto & v : adj[u]) {
        if (vst[v]) continue;
        dfs(v, c, sz);
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

        vst.resize(n);
        col.resize(n);
        adj.resize(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c = 0;
        vector < int > tot;
        for (int i = 0; i < n; i++) {
            if (vst[i]) continue;
            int sz = 0;
            dfs(i, c, sz);
            tot.push_back(sz);
            c++;
        }

        for (int i = 0; i < n; i++) {
            // cout << col[i] << " " << tot[col[i]] << " " << adj[i].size() << endl;
            ans += tot[col[i]] - adj[i].size() - 1;
        }

        cout << ans / 2 << '\n';
    }
    return 0;
}