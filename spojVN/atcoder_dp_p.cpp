#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

vector < vector < int > > dp;
vector < vector < int > > adj;

// 0 = white; 1 = black
void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 1;
    if (adj[u].size() == 1 && u != p)
        return ;

    for (int &v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }

    for (int &v : adj[u]) {
        if (v == p) continue;
        dp[u][1] = (1ll * dp[u][1] * dp[v][0]) % MOD;
        dp[u][0] = (1ll * dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 2;
        return 0;
    }
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp.resize(n, vector < int > (2));
    dfs(0, 0);
    cout << (dp[0][0] + dp[0][1]) % MOD << '\n';
    return 0;
}