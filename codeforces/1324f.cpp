#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 10;

int n;
int col[MAXN], sum[MAXN];
vector < int > adj[MAXN];

void dfs(int u, int p) {
    sum[u] = col[u];
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        dfs(v, u);
    }

    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        if (sum[v] > 0)
            sum[u] += sum[v];
    }
}

void findMax(int u, int p) {
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        if (sum[v] >= 0)
            sum[v] = max(sum[u], sum[v]);
        else 
            sum[v] += sum[u];
        findMax(v, u);
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> col[i];
        if (col[i] == 0)
            col[i] = -1;
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);        
    }
    dfs(1, 1);
    //for(int i = 1; i <= n; i++)
    //    cout << sum[i] << " ";
    findMax(1, 1);
    for(int i = 1; i <= n; i++)
        cout << max(sum[i], -1) << " ";
    return 0;
}
