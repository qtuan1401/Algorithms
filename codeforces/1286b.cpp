#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

int c[MAXN], ans[MAXN], sz[MAXN];
vector < int > a, adj[MAXN];
int root, n;

void countSz(int u) {
    sz[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        countSz(v);
        sz[u] += sz[v];
    }
    //cout << sz[u] << " " << c[u] << endl;
    if (c[u] > sz[u] - 1) {
        cout << "NO";
        exit(0);
    }
}

void dfs(int u) {
    //cout << c[u] + 1 << " " << a.size() << endl;
    ans[u] = a[c[u] + 1];
    //cout << ans[u] << endl;
    //for(int i = 0; i < a.size(); i++)
    //    cout << a[i] << " ";
    //cout << endl;
    a.erase(a.begin() + c[u] + 1); 
    //for(int i = 0; i < a.size(); i++)
    //    cout << a[i] << " ";
    //cout << endl;
    for(int i = 0; i < adj[u].size(); i++) 
        dfs(adj[u][i]);
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int p;
        cin >> p >> c[i];
        adj[p].push_back(i);
        if (p == 0)
            root = i;
    }
    for(int i = 0; i <= n; i++)
        a.push_back(i);
    //cout << root << endl;
    countSz(root);
    dfs(root);
    cout << "YES\n";
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}