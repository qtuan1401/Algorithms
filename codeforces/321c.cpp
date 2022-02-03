#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int sz[MXN], par[MXN], ans[MXN];
int n, centroid, mn;
vector < int > adj[MXN];

void countVertices(int u) {
    sz[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == par[u] || ans[v] >= 0)
            continue;
        par[v] = u;
        countVertices(v);
        sz[u] += sz[v];
    }
} 

void findCentroid(int u, int root) {
    int mxComp = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == par[u] || ans[v] >= 0)
            continue;
        findCentroid(v, root);
        mxComp = max(mxComp, sz[v]);    
    }

    mxComp = max(mxComp, sz[root] - sz[u]);
    //cout << u << " " << mxComp << endl;
    if (mn > mxComp) {
        centroid = u;
        mn = mxComp;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
        ans[i] = -1;

    for(int col = 0; col < 26; col++) {
        for(int i = 1; i <= n; i++)
            par[i] = -1, sz[i] = 0;
        for(int i = 1; i <= n; i++)
            if (ans[i] == -1 && par[i] == -1) {
                mn = n + 1;
                //cout << "root :" << i << endl;
                countVertices(i);
                findCentroid(i, i);
                //cout << i << " * " << centroid << endl;
                ans[centroid] = col;
            }
    }

    for(int i = 1; i <= n; i++)
        if (ans[i] == -1) {
            cout << "Impossible";
            return 0;
        }

    for(int i = 1; i <= n; i++)
        cout << char(ans[i] + 'A') << " ";
    return 0;
}