#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

vector < int > adj[MXN];
bool vis[MXN];
int depth[MXN], cnt[2];
long long res = 0;
int n, m;

void dfs(int u) {
    vis[u] = 1;
    //cout << u << "*" << endl;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        //cout << v << " " << endl;
        if (vis[v] == 0) {
            depth[v] = depth[u] + 1;
            cnt[depth[v] % 2]++;
            dfs(v);
        } else {
            int diff = depth[v] - depth[u] + 1;
            if (diff & 1) {
                cout << "0 1";
                exit(0);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if (vis[i] == 0) {
            cnt[0] = 1; cnt[1] = 0;
            dfs(i);
            //cout << cnt[0] << " " << cnt[1] << endl;
            res += max(0ll, (1ll * cnt[0] * (cnt[0] - 1) + 1ll * (cnt[1]) * (cnt[1] - 1)) / 2);
        }
    if (res > 0) {
        cout << 1 << " " << res;
    } else if (m > 0) {
        long long res = 1ll * m * (n - 2);
        if (res <= 0)
            cout << "0 0";
        else
            cout << 2 << " " << res;
    } else {
        if (n >= 3)
            cout << 3 << " " << 1ll * n * (n - 1) * (n - 2) / 6;
        else
            cout << "0 0"; 
    }
    return 0;
}