#include<bits/stdc++.h>

using namespace std;
    
const int MXN = 1e5 + 10;

vector< int > adj[MXN];
int color[MXN];
int n, m;
    
void dfs(int u, int col) {
    color[u] = col;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (color[v] == col) {
            cout << "-1";
            exit(0);
        }
        if (color[v] == 0)
            dfs(v, 3 - col);
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
        if (color[i] == 0)
            dfs(i, 1);
    vector < int > col[3];
    for(int i = 1; i <= n; i++)
        col[color[i]].push_back(i);
    cout << col[1].size() << '\n';
    for(int i = 0; i < col[1].size(); i++)
        cout << col[1][i] << " ";
    cout << '\n' << col[2].size() << '\n';
    for(int i = 0; i < col[2].size(); i++)
        cout << col[2][i] << " ";
}