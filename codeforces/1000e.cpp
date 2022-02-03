#include <bits/stdc++.h>

using namespace std;
    
const int MXN = 3e5 + 10;
    
vector < int > adj[MXN];
int dp[MXN], num[MXN], low[MXN];
int res, cnt;

void tarjan(int u, int p) {
    low[u] = num[u] = ++cnt;
    int mx = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue ;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else {
            tarjan(v, u);
            int temp = dp[v] + (low[v] >= num[v]);
            dp[u] = max(dp[u], temp);
            res = max(res, mx + temp);
            mx = max(mx, temp);
            low[u] = min(low[u], low[v]);
        }
    }
    res = max(res, dp[u]);
}
    
int main() {
    ios_base::sync_with_stdio(0);
    int n, m; 
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tarjan(1, 0);

    cout << res;
    return 0;
}