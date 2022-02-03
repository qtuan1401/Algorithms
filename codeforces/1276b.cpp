#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int low[MAXN], num[MAXN];
bool vA[MAXN], vB[MAXN], check[MAXN];
vector < int > adj[MAXN];
int cnt = 0, a, b, n, m, child;

void tarjan(int u, int p) {
    low[u] = num[u] = ++cnt;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else {
            tarjan(v, u);
            child++;
            low[u] = min(low[u], low[v]);
            if (u == p) {
                if (child >= 2)
                    check[u] = true;
            } else {
                if (low[v] >= num[u])
                    check[u] = true;
            }
        }
    }
}

void dfs(int u, bool * vu, int band) {
    vu[u] = true;
    //for(int i = 1;)
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (vu[v] || v == band)
            continue;
        dfs(v, vu, band);
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> a >> b;
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
            check[i] = vA[i] = vB[i] = false;
            num[i] = low[i] = 0;   
        }
        cnt = 0; child = 0;
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= n; i++)
            if (num[i] == 0)
                tarjan(i, i);
        if (!check[a] || !check[b]) {
            cout << "0\n";
            continue;
        } else {
            dfs(a, vA, b);
            dfs(b, vB, a);
            long long res = 0;
            int cntA = 0, cntB = 0;
            for(int i = 1; i <= n; i++) {
            //    cout << vA[i] << " " << vB[i] << endl;
                cntA += (vA[i] && !vB[i] && i != a && i != b);
                cntB += (vB[i] && !vA[i] && i != a && i != b);
            }
            res = 1ll * cntA * cntB;
            cout << res << '\n';
        }
    }
    return 0;
}