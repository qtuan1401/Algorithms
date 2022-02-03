#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int minPrime[MAXN], a[MAXN], f[MAXN][10];
vector < int > adj[MAXN], factor[MAXN];
int n, res;

void eratos(int n) {
    for(int i = 2; i * i <= n; i++) {
        if (factor[i].empty()) {
            for(int j = i; j <= n; j += i) { 
                factor[j].push_back(i);
            }
        }
    }
    for(int i = 2; i <= n; i++)
        if (factor[i].empty())
            factor[i].push_back(i);
}

void dfs(int u, int p) {
    int mx1[10], mx2[10];
    for(int i = 0; i < factor[a[u]].size(); i++)
        mx1[i] = mx2[i] = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        dfs(v, u);
        //if (u == 10 || u == 75 || u == 74)
        //    cout << v << " " << a[v] << "*\n";
        for(int j = 0; j < factor[a[u]].size(); j++) {
            int cur = factor[a[u]][j];
            //if (ug == 10 || u == 75 || u == 74) cout << cur << "\n(";
            for(int k = 0; k < factor[a[v]].size(); k++) {
                int nxt = factor[a[v]][k];
            //    if (u == 10 || u == 75 || u == 74) cout << nxt << " ";
                if (nxt == cur) {
                    if (mx1[j] <= f[v][k]) {
                        mx2[j] = mx1[j];
                        mx1[j] = f[v][k];
                    } else if (mx2[j] <= f[v][k])
                        mx2[j] = f[v][k];
                }
            }
            //if (u == 10 || u == 75 || u == 74) cout << ")\n";
        }   
    }
    for(int i = 0; i < factor[a[u]].size(); i++) { 
        res = max(res, f[u][i] = mx1[i] + 1);
        res = max(res, mx1[i] + mx2[i] + 1);
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);

    eratos(2e5);
    //cout << minPrime[4] << endl;
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << res;
    return 0;
}