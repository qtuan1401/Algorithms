#include <bits/stdc++.h>

using namespace std;

const int MXN = 5e5 + 10;

int seg[MXN * 4][2], lazy[MXN * 4][2], st[MXN], fn[MXN], up[MXN];
vector < int > adj[MXN];
int n, cnt;

void update(int id, int l, int r, int u, int v, int val, int type) {
    if (lazy[id][type]) {
        seg[id][type] = lazy[id][type];
        if (l != r) {
            lazy[id * 2][type] = lazy[id * 2 + 1][type] = lazy[id][type];
        }
        lazy[id][type] = 0;
    }

    if (v < l || r < u)
        return ;

    if (u <= l && r <= v) {
        seg[id][type] = val;
        if (l != r) {
            lazy[id * 2][type] = lazy[id * 2 + 1][type] = val;
        }
        return ;
    }
    
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, val, type);
    update(id * 2 + 1, mid + 1, r, u, v, val, type);
    seg[id][type] = max(seg[id * 2][type], seg[id * 2 + 1][type]);
}

int get(int id, int l, int r, int u, int v, int type) {
    if (lazy[id][type]) {
        seg[id][type] = lazy[id][type];
        if (l != r) {
            lazy[id * 2][type] = lazy[id * 2 + 1][type] = lazy[id][type];
        }
        lazy[id][type] = 0;
    }

    if (v < l || r < u)
        return 0;
    
    if (u <= l && r <= v)
        return seg[id][type];

    int mid = (l + r) >> 1;
    return max(get(id * 2, l, mid, u, v, type), get(id * 2 + 1, mid + 1, r, u, v, type));
}

void buildTree(int u, int p) {
    st[u] = ++cnt;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        buildTree(v, u);
    }
    fn[u] = cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    buildTree(1, 1);

    int m;
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int type, v;
        cin >> type >> v;
        type--;
        if (type == 0) {
            update(1, 1, n, st[v], fn[v], i, type);
        } else if (type == 1) {
            update(1, 1, n, st[v], st[v], i, type);
        } else {
            int col = get(1, 1, n, st[v], st[v], 0);
            if (col == 0)
                cout << "0\n";
            else {
                if (col > get(1, 1, n, st[v], fn[v], 1))
                    cout << "1\n";
                else 
                    cout << "0\n";
            }
        }
    }
    return 0;
}
