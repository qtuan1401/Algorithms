#include <bits/stdc++.h>

using namespace std;

const int md = 1e6 + 10;
const int N = 1e4 + 1;

int a[md];
int n, m;
vector<int> adj[md];
bool dd[N][N], vis[N];
int par[md];

void dfs(int u, int len, int s) {
//    cout << u << " " << len << "\n";
	if  (len == 4 && dd[u][s]) {
    //    cout << u << " " << s << " " << dd[u][s] << endl;
		for(int i=1;i<=len;i++)
			cout << a[i] << " ";
		exit(0);
	} else if (len >= 4) return;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u;
			a[len + 1] = v;
			dfs(v, len + 1, s);
		}
	}
}

int main() {
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++) {
		int u, v;
		cin >> u >> v;
		if (!dd[u][v]) {
			dd[u][v] = dd[v][u] = true;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	for(int i=1;i<=n;i++) {
        a[1] = i;
        par[i] = i;
        dfs(i, 1, i);
        for(int i=1;i<=n;i++)
            par[i] = 0;
		//cout << endl;
	}

	cout << "-1";
	return 0;
}
