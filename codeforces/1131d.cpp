#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;

int lab[MAXN], vis[MAXN], f[MAXN];
vector < int > adj[MAXN];
int n, m;
string s[MAXN];

int getRoot(int x) {
    if (lab[x] < 0)
        return x;
    return lab[x] = getRoot(lab[x]);
}

void merge(int x, int y) {
    if ((x = getRoot(x)) == (y = getRoot(y)))
        return ;
    if (lab[x] > lab[y])
        swap(x, y);
    lab[x] += lab[y];
    lab[y] = x;
}

void dfs(int u) {
    vis[u] = 1;
    f[u] = 1;
    int res = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (vis[v] == 1) {
            cout << "No";
            exit(0);
        } else if (!vis[v])
            dfs(v);
        res = max(res, f[v]);
    }
    f[u] += res;
    vis[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n + m; i++)
        lab[i] = -1;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < m; j++)
            if (s[i][j] == '=')
                merge(i, j + n);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (s[i][j] == '=')
                continue;
            int u = getRoot(i);
            int v = getRoot(j + n);
            if (u == v) {
                cout << "No";
                return 0;
            }
            if (s[i][j] == '>')
                adj[u].push_back(v);
            else adj[v].push_back(u);
        }
    }

    for(int i = 0; i < n + m; i++)
        if (vis[i] == 0 && getRoot(i) == i)
            dfs(i);
    cout << "Yes\n";
    for(int i = 0; i < n; i++)
        cout << f[getRoot(i)] << " ";
    cout << '\n';
    for(int i = n; i < n + m; i++)
        cout << f[getRoot(i)] << " ";
    return 0;
}