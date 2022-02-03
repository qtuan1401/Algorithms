#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=1;i<=n;i++)
#define md int(3e5 + 5)
#define INF int(1 << 30)
struct node {
	int own, debt;
}a[md];
vector< int > adj[md], cycle[md];
int par[md], vis[md], money[md], res;
int n, r;
void pre_cycle() {
	REP(i, n) {
		int u = i;
		if (!par[u]) {
			while (!par[u]) {
				par[u] = i;
				u = a[u].own;
			}
			if (par[u] != i)
				continue;
			while (!vis[u]) {
				vis[u] = true;
				cycle[r].push_back(u);
				u = a[u].own;
			}
			r++;
		}
	}
}
void dfs(int u) {
	vis[u] = true;
	for(int i = 0; i < adj[u].size(); i++) 
		if (!vis[adj[u][i]])
			dfs(adj[u][i]);
	money[a[u].own] += a[u].debt;
	res -= min(money[u] - a[u].debt, 0);
}
void out_cycle() {
	REP(i, n) 
		if (!vis[i])
			dfs(i);
}
void in_cycle() {
	for(int t = 0; t < r; t++) {
		int Min = INF;
		int start = -1;
		for(int i = 0; i < cycle[t].size(); i++) {
			int u = cycle[t][i];
			int cost = -min(money[u] - a[u].debt, 0);
			if (cost < Min) {
				Min = cost;
				start = u;
			}
		}
		res += Min;
		money[a[start].own] += a[start].debt;
		int u = a[start].own;
		while (u != start) {
			money[a[u].own] += a[u].debt;
			res -= min(money[u] - a[u].debt, 0);
			u = a[u].own;
		}
	}
}
int main() {
	//freopen("test.inp", "r", stdin);
	scanf("%d", &n);
	REP(i, n) {
		int u, w;
		scanf("%d %d", &a[i].own, &a[i].debt);
		adj[a[i].own].push_back(i);
	}
	pre_cycle();
	out_cycle();
	in_cycle();
	printf("%d", res);
	return 0;
}