// atcoder abc304e
#include <bits/stdc++.h>

using namespace std;

vector < int > lab;

int getRoot(int x) {
    if (lab[x] < 0) return x;
    return lab[x] = getRoot(lab[x]);
}

void merge(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);

    if (u == v) return;
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        lab.resize(n);
        for (int i = 0; i < n; i++) lab[i] = -1;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            merge(u, v);
        }
        int k;
        cin >> k;
        map < pair < int, int >, int > mp;
        for (int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            u = getRoot(u);
            v = getRoot(v);
            mp[{u, v}] = 1;
            mp[{v, u}] = 1;
        }

        int q;
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            u = getRoot(u);
            v = getRoot(v);
            if (mp[{u, v}]) cout << "No\n";
            else cout << "Yes\n";
        }
    }
    return 0;
}