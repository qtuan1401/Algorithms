#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector < vector < int > > a, adj;

int bfs(int m) {
    queue < int > qu;

    int n = a.size();
    vector < int > d(m, INF);
    vector < int > vst(n, 0);

    for (int i = 0; i < n; i++) {
        if (a[i][0] == 0) {
            vst[i] = 1;
            for (int & e : a[i]) {
                if (d[e] == INF) qu.push(e);
                d[e] = 0;
            }
        }
    }

    while (qu.size()) {
        int u = qu.front(); qu.pop();
        for (int & row : adj[u]) {
            if (vst[row]) continue;
            vst[row] = 1;
            for (int & num : a[row]) {
                if (d[num] != INF) continue;
                d[num] = d[u] + 1;
                qu.push(num);
            }
        }
    }

    if (d[m - 1] == INF) return -1;
    return d[m - 1];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        a.resize(n);
        adj.resize(m);
        for (int i = 0; i < n; i++) {
            int len;
            cin >> len;
            a[i].resize(len);
            for (int j = 0; j < len; j++) {
                cin >> a[i][j];
                a[i][j]--;
                adj[a[i][j]].push_back(i);
            }
            sort(a[i].begin(), a[i].end());
        }

        
        cout << bfs(m) << '\n';
    }
    return 0;
}