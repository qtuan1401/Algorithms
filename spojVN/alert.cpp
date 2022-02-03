#include <bits/stdc++.h>

using namespace std;

const int MXN = 210;

vector < int > adj[MXN];
int f[MXN][MXN], c[MXN][MXN], par[MXN], id[MXN], val[MXN];
int res, sz, sum, n;

bool bfs(int s, int t, int n) {
	queue < int > q;
	for(int i = 1; i <= n; i++)
		par[i] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (par[v] == 0 && c[u][v] - f[u][v] > 0) {
				q.push(v);
				par[v] = u;
			}
		}
	}
	return !(par[t] == 0);
}

void maxflow(int s, int t) {
	int flow = 1e9;
	for(int v = t; v != s; v = par[v]) 
		flow = min(flow, c[par[v]][v] - f[par[v]][v]);
    cout << flow << endl;
	for(int v = t; v != s; v = par[v]) {
        cout << v << " " << par[v] << endl;
		f[par[v]][v] += flow;
		f[v][par[v]] = -f[par[v]][v];
	}
	res += flow;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    int n1, n2;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        id[x] = n + 1;
    }
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        id[x] = n + 2;
    }
    for (int i = 1; i <= n; i++)
        if (id[i] == 0) {
            id[i] = i;
        }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        sum += w;
        if (u == v)
            continue;
        c[id[u]][id[v]] += w;
        c[id[v]][id[u]] += w;
        adj[id[u]].push_back(id[v]);
        adj[id[v]].push_back(id[u]);
    }

    while (bfs(n + 2, n + 1, sz))
        maxflow(n + 2, n + 1);
    vector < int > ans;
    for (int i = 1; i <= n; i++)
        if (par[i] == 0 && id[i] >= 1 && id[i] <= n)
            ans.push_back(i);
    for (int i = 1; i <= n; i++)
        if (id[i] == n + 1)
            ans.push_back(i);
    cout << sum - res << " " << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}