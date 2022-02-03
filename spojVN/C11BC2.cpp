#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=1;i<=n;i++)
#define md int(1e5 + 5)
int dd[md];
int n, m, cnt;
vector< int > adj[md];
void dfs(int u) {
	dd[u] = cnt;
	for(int i=0;i<adj[u].size();i++)
		if (!dd[adj[u][i]])
			dfs(adj[u][i]);
}
int main() {
//	freopen("test.inp", "r", stdin);
	scanf("%d %d", &n, &m);
	REP(i, n - 1) {
		int u, type;
		scanf("%d %d", &u, &type);
		if (type == 1) {
			adj[i + 1].push_back(u);
			adj[u].push_back(i + 1);
		}
	}
	REP(i, n)
		if (!dd[i]) {
			cnt++;
			dfs(i);
		}
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (dd[u] != dd[v])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}