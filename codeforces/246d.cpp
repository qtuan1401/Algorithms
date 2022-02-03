#include<bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

set < int > adj[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector < int > cnt(MXN), c(MXN);
    for(int i = 1; i <= n; i++) {
        cin >> c[i]; 
        cnt[c[i]]++;
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (c[u] != c[v]) {
            adj[c[u]].insert(c[v]);
            adj[c[v]].insert(c[u]);
        }
    }

    int mx = 0, res = 0;
    for(int i = 1e5; i >= 1; i--)
        if (mx <= adj[i].size() && cnt[i]) {
            mx = adj[i].size();
            res = i;
        }
    cout << res;
    return 0;
}
