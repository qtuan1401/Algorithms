#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int a[MXN], s[MXN], par[MXN];
int n;
vector < int > adj[MXN];

void dfs(int u, int depth) {
    
    if (depth == 1) {
        a[u] = s[u] - s[par[u]];
    } else {
        int mn = 1e9 + 10;
        for(int i = 0; i < adj[u].size(); i++) {
            for(int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (par[u] == v)
                    continue;
                par[v] = u;
                mn = min(mn, s[v] - s[par[u]]);
                //cout << s[v] - s[par[u]] << " " << mn << endl;
            }
        }
        if (mn == 1e9 + 10)
            mn = 0;
        a[u] = mn;

        s[u] = s[par[u]] + mn;
    }
    if (a[u] < 0) {
        cout << "-1";
        exit(0);
    }
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (par[u] == v)
            continue;
        par[v] = u;
        dfs(v, (depth + 1) % 2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    dfs(1, 1);
    long long res = 0;
    for(int i = 1; i <= n; i++)
        res += a[i];
    cout << res;
    return 0;
}