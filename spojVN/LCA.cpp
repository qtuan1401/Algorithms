#include <bits/stdc++.h>
using namespace std;
#define md int(3e5 + 5)
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define REV(i, n) for(int i = (n); i >= 0; i--)
#define FORR(i, a, b) for(int i = (a); i < (b); i++)
vector< int > adj[md];
int par[md], d[md];
int m[md][25], n, q, r;
inline void dfs(int u) {
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
			m[i][k] = m[m[i][k-1]][k-1];
}
inline int lca(int p, int q) {
	REV(i, 20)
		if (d[m[p][i]] >= d[q])
			p = m[p][i];
	REV(i, 20)
		if (d[m[q][i]] >= d[p])
			q = m[q][i];
	if (q == p)
		return q;
	REV(i, 20)
		if (m[q][i] != m[p][i]) {
			p = m[p][i];
			q = m[q][i];
		}
	return par[p];
}
int main() {
	//freopen("test.inp", "r", stdin);
	scanf("%d", &q);
	REP(z, q) {
		printf("Case %d:\n", z);
		scanf("%d", &n);
		REP(i, n) {
			par[i]=0;
			adj[i].clear();
		}
		REP(i, n) {
			scanf("%d", &r);
			REP(j, r) {
				int u;
				scanf("%d", &u);
				adj[i].push_back(u);
			}
		}
		REP(i, n)
			if (!par[i]) {
				par[i] = i;
				d[i] = 1;
				dfs(i);
			}
		prepare();
		scanf("%d", &r);
		while (r--) {
			int u, v;
			scanf("%d %d", &u, &v);
			printf("%d\n", lca(u, v));
		}
	}
	return 0;
}
