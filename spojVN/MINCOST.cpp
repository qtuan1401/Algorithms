#include <bits/stdc++.h>

#define REP(i, n) for(int i=1;i<=n;i++)

using namespace std;

const int md = 105;

bool vis[md], check[md][md];
int f[md][md], cap[md][md], cost[md][md], par[md], d[md];
int n, m, k, s, t, temp, cnt;
vector< int > adj[md];

bool fordbellman() {
	REP(i, n) {
		par[i] = -1;
		d[i] = INT_MAX;
		vis[i] = false;
	}
	queue< int > q;
	q.push(s);
	vis[s] = true;
	d[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		//cout << u << endl;
		REP(v, n) {
		//for(int i=0;i<adj[u].size();i++) {
		//	int v = adj[u][i];
			if (cap[u][v] > f[u][v]) {
		//		cout << v <<" ";
				if (f[u][v] == 0)
					temp = cost[u][v];
				else
					temp = cost[u][v] * f[u][v] / abs(f[u][v]);
				if (d[v] > d[u] + temp) {
					d[v] = d[u] + temp;
					par[v] = u;
					if (!vis[v]) {
						q.push(v);
						vis[v] = true;
					}
				}
			}
		}
	//	cout << endl;
	}
	return d[t] < INT_MAX;
}

void inc_flow() {
	int flow = INT_MAX;
	for(int v = t; v != s; v = par[v]) 
		flow  = min(flow, ((f[par[v]][v] >= 0) ? cap[par[v]][v] - f[par[v]][v] : f[v][par[v]]));
	flow = min(flow, k - cnt);
	cnt += flow;
	for(int v = t; v != s; v = par[v]) {
		f[par[v]][v] += flow;
		f[v][par[v]] -= flow;
	}
}

void solve() {
	do {
		if (fordbellman()) {
			inc_flow();
		} else
			break;
	} while (cnt != k);
}

int main() {
	//freopen("test.inp", "r", stdin);
	//freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(0);

	cin >> n >> m >> k >> s >> t;
	memset(f, 0, sizeof f);
	REP(i, m) {
		int u, v, c, w;
		cin >> u >> v >> c >> w;
		cost[u][v] = cost[v][u] = c;
		cap[u][v] = cap[v][u] = w;
		if (!check[u][v]) {
			adj[u].push_back(v);
			adj[v].push_back(u);
			check[u][v] = check[v][u] = true;
		}
	}

	solve();
	if (cnt < k) {
		puts("-1");
		exit(0);
	}
	int ans = 0;
	REP(i, n)
		REP(j, n)
			if (f[i][j] > 0)
				ans += f[i][j] * cost[i][j];
	cout << ans << '\n';
	REP(i, n)
		REP(j, n)
			if (f[i][j] > 0)
				cout << i <<" "  << j << " " << f[i][j] << '\n';
	cout << "0 0 0";
	return 0;
}