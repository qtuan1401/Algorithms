#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

struct edge {
    int u, v, c, i;
    edge(int _u = 0, int _v = 0, int _c = 0, int _i = 0) {
        u = _u;
        v = _v;
        c = _c;
        i = _i;
    }
};

bool cycle;
vector < edge > adj[MXN], edges;
int vis[MXN], pos[MXN];
vector < int > order, ans;
int n, m;

void dfs(int u, int x, int trc) {
    if (cycle)
        return ;
    //cout << u << endl;
    vis[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].v;
        //cout << v << " " << adj[u][i].c << " " << x << " " << trc << endl;
        if (adj[u][i].c <= x) {
            if (trc)
                edges.push_back(adj[u][i]);
            continue ;
        }
        if (vis[v] == 1) {
            cycle = true;
            return ;
        } else if (vis[v] == 0) {
            dfs(v, x, trc);
        }
    }
    vis[u] = 2;
    if (trc)
        order.push_back(u);
}

bool check(int x, int trc) {
    cycle = false;
    for(int i = 1; i <= n; i++)
        vis[i] = 0;
    for(int i = 1; i <= n; i++)
        if (vis[i] == 0) {
            dfs(i, x, trc);
            if (cycle)
                return false;
        }
    return true;
}

int bs(int l, int r) {
    int pos = 1e9;
    while (l <= r) {
        int mid = (l + r) >> 1;
        //cout << mid << " " << check(mid, 0) << endl;
        if (check(mid, 0)) {
            pos = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    check(pos, 1);
    return pos;
}

int main() {
    ios_base::sync_with_stdio(0);
    //cout << edges.size() << endl;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(edge(u, v, c, i + 1));
    }
    int res = bs(1, 1e9);
    reverse(order.begin(), order.end());
    for(int i = 0; i < order.size(); i++)
        pos[order[i]] = i;
    for(int i = 0; i < edges.size(); i++) {
        if (pos[edges[i].u] > pos[edges[i].v])
            ans.push_back(edges[i].i);
    }
    sort(ans.begin(), ans.end());
    cout << res << " " << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}