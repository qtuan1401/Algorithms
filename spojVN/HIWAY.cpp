#include <bits/stdc++.h>

using namespace std;

const int md = 105;

const int oo = INT_MAX;

bool vis[md];
int f[md][md], cap[md][md], cost[md][md], par[md], d[md], check[md];
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
//	check[s] = false;
//	check[t] = false;
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
					temp = cost[u][v] * f[u][v] / abs(f[u][v]);
				if (d[v] > temp + d[u]) {
					d[v] = temp + d[u];
					par[v] = u;
					if (!vis[v]) {
						vis[v] = true;
						q.push(v);
					}
				}

			}
		}
	}
	//cout << d[t] << endl;
	return d[t] < oo;
}

void inc_flow() {
	int flow = oo;
	for(int v = t; v != s; v = par[v])
		flow = min(flow, (f[par[v]][v] >= 0 ? cap[par[v]][v] - f[par[v]][v] : f[v][par[v]]));
	flow = min(flow, 2 - cnt);
	cnt += flow;
	//cout << cnt << endl;
	++r;
	for(int v = t; v != s; v = par[v]) {
		f[par[v]][v] += flow;
		f[v][par[v]] -= flow;
		//if (f[par[v]][v] > 0)
		//	vv[r].push_back(v);
		//check[v] = true;
	}
	//vv[r].push_back(s);
}

void solve() {
	do {
		if (fordbellman())
			inc_flow();
		else
			break;
	} while (cnt != 2);
}

void findpath(int u) {
	check[u] = true;
	vv.push_back(u);
	for(int v=1;v<=n;v++)
		if (f[u][v] > 0 && !check[v]) {
			findpath(v);
			break;
		}
}

int main() {
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	cin >> s >> t;
	for(int i=1;i<=m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		cap[u][v] = 1;
		cap[v][u] = 1;
		cost[u][v] = w;
		cost[v][u] = w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve();
	//cout << cnt << endl;
	if (cnt < 2)
		puts("-1");
	else {
		int ans = 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if (f[i][j] > 0)
					ans += f[i][j] * cost[i][j];
		cout << ans << '\n';
		findpath(s);
		cout << vv.size() <<" ";
		for(int i=0;i<vv.size();i++)
			cout << vv[i] << " ";
		cout << '\n';
		vv.clear();
		check[t] = false;
		findpath(s);
		cout << vv.size() <<" ";
		for(int i=0;i<vv.size();i++)
			cout << vv[i] << " ";
		cout << '\n';
		//vv.clear();
	}
	return 0;
}
