#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;
const int INF = 1e9;

int fw[2][MXN], a[MXN], v[MXN], st[MXN], fn[MXN], id[MXN];
vector < int > adj[MXN];
int n, m, cnt;

int get(int type, int x) {
    int res = 0;
    while (x > 0) {
        res += fw[type][x];
        x -= (x & (-x));
    }
    return res;
}

void update(int type, int x, int val) {
    while (x < MXN) {
        fw[type][x] += val;
        x += (x & (-x));
    }
}

void buildTree(int u, int p) {
    st[u] = ++cnt;
    v[cnt] = u;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p) 
            continue;
        id[v] = (id[u] + 1) % 2;
        buildTree(v, u);
    }
    fn[u] = cnt;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    buildTree(1, 0);
    for(int i = 1; i <= n; i++) {
        update(id[v[i]], i, a[v[i]]);
        update(id[v[i]], i + 1, -a[v[i]]);
    }
    while (m--) {
        int type, x;
        cin >> type >> x;
        if (type == 2) {
            cout << get(id[x], st[x]) << '\n';
        } else {
            int val;
            cin >> val;
            update(id[x], st[x], val);
            update(id[x], fn[x] + 1, -val);
            if (st[x] + 1 <= fn[x]) {
                update(id[v[st[x] + 1]], st[x] + 1, -val);
                update(id[v[st[x] + 1]], fn[x] + 1, val);
            }   
        }
    }
    return 0;
}