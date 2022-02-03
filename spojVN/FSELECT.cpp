#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 1;i <= (n); i++)
#define FORR(i, a, b) for(int i = (a); i < (b); i++)
#define REV(i, n) for(int i = (n);i >= 0; i--)
#define md int(1e6 + 5)
int par[md], c[md], d[md], n, k, z[md], t[md], res[md];
int m[md][25];
vector< int > adj[md];
inline void dfs(int u) {
	if (d[u] > c[z[u]]) {
		c[z[u]] = d[u];
		t[z[u]] = u;
	}
	FORR(i, 0, adj[u].size()) {
		int v = adj[u][i];
		if (v != par[u]) {
			par[v] = u;
			d[v] = d[u] + 1;
			dfs(v);
		}
	}
}
inline void prepare() {
	REP(i, n) 	
		m[i][0] = par[i];
	REP(k, 20)
		REP(i, n)
			m[i][k] = m[m[i][k- 1]][k - 1];
}
inline int lca(int x, int y) {
	int res = d[x] + d[y];
	REV(i, 20)
		if (d[m[x][i]] >= d[y]) 
			x = m[x][i];
	REV(i, 20)
		if (d[m[y][i]] >= d[x])
			y = m[y][i];
	if (x != y) {
		REV(i, 20) {
			if (m[x][i] != m[y][i]) {
				x = m[x][i];
				y = m[y][i];
			}
		}
		x = par[x];
	}
	return res - 2 * d[x];
}
int main() {
//	freopen("test.inp", "r", stdin);
	scanf("%d%d", &n, &k);
	REP(i, n) {
		int y;
		scanf("%d %d", &z[i], &y);
		if (y != 0) {
			adj[i].push_back(y);
			adj[y].push_back(i);
		}
	}
	REP(i, n) 
 		if (!par[i]) {
 			d[i] = 1;
 			par[i] = i;
 			dfs(i);
		}
	prepare();
	REP(i, n)
		res[z[i]] = max(res[z[i]], lca(t[z[i]], i));
	REP(i, k)
		printf("%d\n", res[i]);
}