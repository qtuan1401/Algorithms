#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > PII;

vector < int > ans, color, sum, marked;
vector < PII > f;
vector < vector < int > > adj;

void dfs(int u, int p) {
    f[u].first = color[u];
    sum[u] = color[u];
    for (int & v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sum[u] += sum[v];
        if (f[u].first < f[v].first + color[u]) {
            f[u].second = f[u].first;
            f[u].first = f[v].first + color[u];
        } else if (f[u].second < f[v].first + color[u]) {
            f[u].second = f[v].first + color[u];
        }
    }
}

void calc(int u, int p, int type) {
    ans[u] |= (f[u].first >= 2) | color[u];
    for (int & v : adj[u]) {
        if (v == p) continue;
        marked[v] = marked[u];
        if ((color[u] || color[p]) && sum[0] - sum[v] >= 2)
            marked[v] = true;
        int temp = f[u].first;
        if (f[v].first + color[u] == f[u].first)
            temp = f[u].second;
        if (temp >= 2) marked[v] = true;

        ans[v] |= marked[v];
        calc(v, u, type);
    }
}

void swapColor(int u, int p) {
    for (int & v : adj[u]) {
        if (v == p) continue;
        if (color[u] == 0 && color[v] == 1)
            swap(color[u], color[v]);
        swapColor(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    color.resize(n); ans.resize(n); adj.resize(n);
    f.resize(n); sum.resize(n); marked.resize(n);
    for (int i = 0; i < n; i++)
        cin >> color[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (color[u] == 1 || color[v] == 1)
            ans[u] = ans[v] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    calc(0, 0, 0);
    swapColor(0, 0);
    f.resize(n, PII(0, 0));
    sum.resize(n, 0);
    marked.resize(n, 0);
    dfs(0, 0);
    calc(0, 0, 1);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}