#include <bits/stdc++.h>
using namespace std;
#define md int(1e6 + 5)
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define REV(i, n) for(int i = (n); i >= 0; i--)
#define FORR(i, a, b) for(int i = (a); i < (b); i++)
int d[md], par[md], q, n;
int m[md][25];
vector< int > adj[md];
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
			m[i][k] = m[m[i][k - 1]][k - 1];
}
inline int lca(int x, int y) {
	REV(i, 20) 
		if (d[m[x][i]] >= d[y])
			x = m[x][i];
	REV(i, 20)
		if (d[m[y][i]] >= d[x])
			y = m[y][i];
	if (x == y)
		return x;
	REV(i, 20) {
		if (m[x][i] != m[y][i]) {
			x = m[x][i];
			y = m[y][i];
		}
	}
	return par[x];
}
int main() {
//	freopen("test.inp", "r", stdin);
	while (true) {
		scanf("%d", &n);
		if (n == 0)
			return 0;
		REP(i, n) {
			par[i] = 0;
			adj[i].clear();
			//d[i] = 0;
		}
		REP(i, n - 1) {
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		REP(i, n) 
			if (!par[i]) {	
				d[i] = 1;
				par[i] = i;
				dfs(i);
			}
		prepare();
		int root = 1;
		scanf("%d", &q);
		char c;
		while (q--) {
			cin >> c;
			//cout << c << endl;
			if (c == '?') {
				int u, v;
				scanf("%d%d", &u, &v);
				int x = lca(u, v);
				int y = lca(root, u);
				int z = lca(root, v);
				if (d[x] >= d[y] && d[x] >= d[z]) {
					printf("%d\n", x);
				}
				else if (d[y] >= d[x] && d[y] >= d[z]) {
					printf("%d\n", y);
				}
				else 
					printf("%d\n", z);
			}
			else {
				int u;
				scanf("%d", &u);
				root = u;
			}
		}
	}
	return 0;
}