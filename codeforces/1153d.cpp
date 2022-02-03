#include <bits/stdc++.h>

using namespace std;

const int md = 3e5 + 10;

vector < int > adj[md];
int f[md], o[md];
int n, k;
vector < int > leaves;

void dfs(int u) {
    if (adj[u].size() == 0) {
        f[u] = 1;
        k++;
        return ;
    }
    if (o[u] == 1)
        f[u] = 1e9 + 7;
    else f[u] = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v);
        if (o[u])
            f[u] = min(f[u], f[v]);
        else f[u] += f[v];
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> o[i];
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1); 
    cout << k + 1 - f[1];
    return 0;
}