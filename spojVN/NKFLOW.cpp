#include <bits/stdc++.h>

using namespace std;

const int md = 1e3 + 10;
const int INF = 1e9;

int par[md], f[md][md], c[md][md];
vector< int > adj[md];
int n, m, s, t, res;

bool bfs(int s, int t) {
	queue < int > q;
	for(int i=1;i<=n;i++)
		par[i] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++) {
			int v = adj[u][i];
			if (par[v] == 0 && c[u][v] - f[u][v] > 0) {
				q.push(v);
				par[v] = u;
			}
		}
	}
	if (par[t] == 0)
		return false;
	return true;
}

void maxflow() {
	int flow = INF;
	for(int v=t;v!=s;v=par[v]) 
		flow = min(flow, c[par[v]][v] - f[par[v]][v]);
	for(int v=t;v!=s;v=par[v]) {
		f[par[v]][v] += flow;
		f[v][par[v]] = -f[par[v]][v];
	}
	res += flow;
}

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >>m >> s >> t;
	for(int i=1;i<=m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] = w;
	}
	while (bfs(s, t))
		maxflow();
	cout << res;
	return 0;
}