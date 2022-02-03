#include <bits/stdc++.h>

using namespace std;

const int md = 2e6 + 10;

typedef pair<int, int> ii;

int low[md], num[md], par[md], u[md], v[md], z[md], child[md], lab[md], ver[5];
int cnt1, n, m, t, r, bridge = 0, root, cnt;
long long res = 0;
ii inTree[md];
vector<int> adj1[md], adj[md];
int vis[md];

void dfs(int u, int p) {
	//int child = 0;
	if (cnt == 1)
		cnt1++;
	low[u] = num[u] = ++t;
    child[u] = 1;
    vis[u] = 1;
	for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++) {
		if (*it != p) {
			if (!vis[*it]) {
				dfs(*it, u);
				child[u] += child[*it];
				low[u] = min(low[u], low[*it]);
			} else 
				low[u] = min(low[u], num[*it]);
		}
	}
	if (u != root && low[u] == num[u])
		bridge++;
}

int main() {
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++) 
		if (!vis[i]) {
			root = i;
			++cnt;
			dfs(i, 0);
		}
	//cout << cnt1 << endl;
	if (cnt >= 3) {
		cout << 0;
		return 0;
	} else if (cnt == 2) {
		cout << (long long)(m - bridge) * cnt1 * (n - cnt1);
	} else {
		res = (long long)(m - bridge) * ((long long)n * (n - 1) / 2 - m);
		for(int i=2;i<=n;i++)
			if (low[i] == num[i])
				res += (long long)(child[i]) * (n - child[i]) - 1;
		cout << res;
 	}
	return 0;
}