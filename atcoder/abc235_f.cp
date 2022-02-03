#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;
typedef pair < II, II > PIIII;

int n, m, q;
vector < int > lab, ans;
vector < PIIII > graph;

int root(int x) {
    if (lab[x] < 0) return x;
    return lab[x] = root(lab[x]);
}

bool checkRoot(int x, int y) {
    return ((x = root(x)) != (y = root(y)));
}

void merge(int x, int y) {
    x = root(x); y = root(y);   
    if (lab[y] < lab[x]) swap(x, y);
    lab[x] += lab[y];
    lab[y] = x;
}

void kruskal() {
    for (int i = 0; i < m + q; i++) {
        int u = graph[i].second.first, v = graph[i].second.second, id = graph[i].first.second;
        if (checkRoot(u, v)) {
            if (id > 0) ans[id - 1] = 1;
            else merge(u, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    lab.resize(n + 1, -1); graph.resize(m + q); ans.resize(q, 0);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[i] = PIIII(II(w, 0), II(u, v));
    }
    for (int i = m; i < m + q; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[i] = PIIII(II(w, i - m + 1), II(u, v));
    }
    sort(graph.begin(), graph.end());
    kruskal();
    for (int i = 0; i < q; i++)
        if (ans[i] == 0) cout << "No\n";
        else cout << "Yes\n";
    return 0;
}