#include <bits/stdc++.h>

using namespace std;

const int md = 2e2 + 10;

vector < int > adj[md];
int f[md][md], c[md], par[md], trace[md][md];
int n, q, k, res;

void dfs(int u) {
    f[u][1] = c[u];
	for(int s=0;s<adj[u].size();s++) {
		int v = adj[u][s];
		//cout << v << endl;
		if (par[u] != v) {
		//	cout << v << " ";
			par[v] = u;
			dfs(v);
			for(int i=k;i>=1;i--)
                for(int j=1;j<i;j++) {
                    if (f[u][i] < f[u][j] + f[v][i - j]) {
                        f[u][i] = f[u][j] + f[v][i - j];
                        trace[v][i] = i - j;
                    }
                }
		}
	}
}

void trc(int u, int k) {
    for(int i=adj[u].size()-1;i>=0;i--) {
        int v = adj[u][i];
        if (par[u] != v && trace[v][k] > 0) {
            trc(v, trace[v][k]);
            k -= trace[v][k];
        }
    }
    cout << u << " ";
}

int main() {
	//freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
            f[i][j] = -1e9;
	for(int i=1;i<=n;i++)
		cin >> c[i];
	for(int i=1;i<n;i++) {
		int u, v;
		cin >> u >> v;
		//cout << u << " " << v << endl;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	par[1] = 1;
	dfs(1);
	int pos = 0;

	for(int i=1;i<=n;i++)
		if (res < f[i][k]) {
			res = f[i][k];
			pos = i;
		}
//	cout << res << endl;
    trc(pos, k);
	return 0;
}
