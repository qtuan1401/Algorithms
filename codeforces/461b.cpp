#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;
const int MOD = 1e9 + 7;

long long dp[MXN][2];
int n;
int col[MXN];
vector < int > adj[MXN];

void dfs(int u, int p) {
    dp[u][0] = 1;
    dp[u][1] = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        dfs(v, u);
        dp[u][1] *= dp[v][0]; dp[u][1] %= MOD;
        dp[u][1] += (dp[u][0] * dp[v][1]) % MOD; dp[u][1] %= MOD;
        dp[u][0] *= dp[v][0]; dp[u][0] %= MOD;
    }
    if (col[u] == 1) {
        dp[u][1] = dp[u][0];
        dp[u][1] %= MOD;
    } else {
        dp[u][0] += dp[u][1];
        dp[u][0] %= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int v;
        cin >> v;
        adj[v].push_back(i + 1);
        adj[i + 1].push_back(v);
    }
    for(int i = 0; i < n; i++)
        cin >> col[i];

    dfs(0, -1);
    
    cout << dp[0][1];
    return 0;
}