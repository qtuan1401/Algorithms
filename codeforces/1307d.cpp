#include <bits/stdc++.h>

using namespace std;

const int md = 2e5 + 10;

queue < int > q;
vector < int > adj[md];
bool vis[md][5], dd[md];
int f[md][5], a[md];
int n, m, k;

void bfs(int x, int type) {
    q.push(x);
    while (q.size()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (f[v][type] || v == x) continue;
            f[v][type] = f[u][type] + 1;
            q.push(v);
        }
    }
}
int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        dd[a[i]] = 1;
    }

    bool ok = false;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    

    bfs(1, 0);
    bfs(n, 1);

    vector < pair < int, int > > v;
    for(int i = 0; i < k; i++) 
        v.push_back({f[a[i]][0] - f[a[i]][1], a[i]});
    
    sort(v.begin(), v.end());
    //for(int i = 0; i < v.size(); i++)
    //    cout << v[i].second << " ";
    //cout << f[n][0] << endl;
    int res = 0, mx = f[v[0].second][0];
    for(int i = 1; i < v.size(); i++) {
        //cout << mx << " " << f[v[i].second][1] << endl;
        res = max(res, mx + f[v[i].second][1]);
        mx = max(mx, f[v[i].second][0]);
    }

    cout << min(f[n][0], res + 1);
    return 0;
}