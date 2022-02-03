#include <bits/stdc++.h>

using namespace std;

const int MXN = 3e3 + 10;

typedef pair < int, int > II;

vector < II > fact[MXN];
vector < int > adj[MXN];
int par[MXN], cap[MXN][MXN], a[MXN], f[MXN][MXN];
int n, m, cnt;

void factorize(int x, int p) {
    for(int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            fact[p].push_back(II(i, ++cnt));
            x /= i;
            //cout << i << " ";
        }
    }
    //cout << x << " ";
    if (x > 1)
        fact[p].push_back(II(x, ++cnt));
}

bool bfs(int s, int t) {
    queue < int > q;
    for(int i = 0; i <= cnt; i++)
        par[i] = -1;
    q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (par[v] == -1 && cap[u][v] - f[u][v] > 0) {
                q.push(v);
                par[v] = u;
            }
        }
    }
    if (par[t] == -1)
        return false;
    return true;
}

int maxFlow(int s, int t) {
    int flow = 1e9;
    for(int v = t; v != s; v = par[v])
        flow = min(flow, cap[par[v]][v] - f[par[v]][v]);
    for(int v = t; v != s; v = par[v]) {
        f[par[v]][v] += flow;
        f[v][par[v]] = -f[par[v]][v];
    }
    return flow;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        factorize(a[i], i);
    }
    
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (l % 2 != 0)
            swap(l, r);
        for(int j = 0; j < fact[l].size(); j++)
            for(int k = 0; k < fact[r].size(); k++)
                if (fact[l][j].first == fact[r][k].first) {
                    int u = fact[l][j].second;
                    int v = fact[r][k].second;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                    //cout << a[l] << " " << a[r] << " " << u << " " << v << endl;
                    cap[u][v] = 1;
                }
    }
    cnt++;
    for(int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            for(int j = 0; j < fact[i].size(); j++) {
                int v = fact[i][j].second;
                adj[v].push_back(cnt);
                adj[cnt].push_back(v);
                cap[v][cnt] = 1;
            }
        } else {
            for(int j = 0; j < fact[i].size(); j++) {
                int v = fact[i][j].second;
                adj[0].push_back(v);
                adj[v].push_back(0);
                cap[0][v] = 1;
            }
        }
    }

    int res = 0;
    while (bfs(0, cnt))
        res += maxFlow(0, cnt);

    cout << res;
    return 0;
}