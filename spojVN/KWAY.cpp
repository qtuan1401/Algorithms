#include <bits/stdc++.h>

using namespace std;

const int md = 105;

const int oo = INT_MAX;

bool vis[md];
int f[md][md], cap[md][md], cost[md][md], par[md], d[md], check[md][md], vs[md];
int n, m, k, s, t, temp, cnt, r;
vector< int > adj[md];
vector< int > vv;

bool fordbellman() {
	for(int i=1;i<=n;i++) {
		d[i] = oo;
		par[i] = -1;
		vis[i] = false;
	}
	queue< int > q;
	q.push(s);
	d[s] = 0;
	vis[s] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i=0;i<adj[u].size();i++) {
			int v = adj[u][i];
			if (cap[u][v] > f[u][v]) {
				if (f[u][v] == 0)
					temp = cost[u][v];
				else
					//temp = cost[u][v] * f[u][v] / abs(f[u][v]);
					temp = (f[u][v] >= 0) ? cost[u][v] : -cost[u][v];
				if (d[v] > d[u] + temp) {
					d[v] = d[u] + temp;
					par[v] = u;
					if (!vis[v]) {
						vis[v] = true;
						q.push(v);
					}
				}
			}
		}
	}
	return d[t] < oo;
}

void inc_flow() {
	int flow = oo;
	for(int v = t; v != s; v = par[v]) 
		flow = min(flow, (f[par[v]][v] >= 0 ? cap[par[v]][v] - f[par[v]][v] : f[v][par[v]]));
	flow = min(flow, k - cnt);
	cnt += flow;
	for(int v = t; v != s; v = par[v]) {
		f[par[v]][v] += flow;
		f[v][par[v]] -= flow;
	}
}

void solve() {
	do {
		if (fordbellman())
			inc_flow();
		else 
			break;
	} while (cnt != k);
}

void findpath(int u) {
	vs[u] = true;
	vv.push_back(u);
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i];
		if (f[u][v] > 0 && !vs[v] && !check[u][v]) {
			check[u][v] = check[v][u] = true;
			findpath(v);
			break;
		}
	}
}

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k >> s >> t;
	for(int i=1;i<=m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		cost[u][v] = cost[v][u] = w;
		cap[u][v] = cap[v][u] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve();
	//cout << cnt << endl;
	if (cnt < k) {
		puts("-1");
		return 0;
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if (f[i][j] > 0)
				ans += f[i][j] * cost[i][j];
	cout << ans << '\n';
	while (k--) {
		vv.clear();
		//vs[t] = false;
		memset(vs, false, sizeof vs);
		findpath(s);
		cout << vv.size() << " ";
		for(int i=0;i<vv.size();i++)
			cout << vv[i] << " ";
		cout << '\n';
	}
	return 0;
}