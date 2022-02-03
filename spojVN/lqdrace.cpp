#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 10;
const int oo = 1e9;

typedef pair < int, int > II;

int sz[MAXN], depth[MAXN];
long long sum[MAXN];
vector < II > adj[MAXN];
vector < int > vec[MAXN];
unordered_map < long long, int > path;
int h[MAXN][2], l[MAXN], big[MAXN];
int n, k;
int ans = oo, cnt = 0;
int in[MAXN], out[MAXN], id[MAXN];

void dfs(int u, int p) {
	sz[u] = 1;
	in[u] = ++cnt;
	id[cnt] = u;
	for(int i = 0; i < adj[u].size(); i++) {
		II cur = adj[u][i];
		int v = cur.first, w = cur.second;
		if (v == p)
			continue;
		depth[v] = depth[u] + 1;
		sum[v] = sum[u] + w;
		dfs(v, u);
		sz[u] += sz[v];
	}
	out[u] = cnt;
}

void modify(int u, int k) {
	long long sumNow = sum[u]; 
	if (k == -1) {
		path[sumNow] = 0;
	} else {
		int tmp = path[sumNow];
		if (tmp == 0)
			tmp = oo;
		path[sumNow] = min(tmp, depth[u]);
	}
}

void sack(int u, int p, int keep) {
	int szMax = -1, bigChild = -1;
	
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (v == p)
			continue;
		if (sz[v] > szMax) {
			sz[v] = szMax;
			bigChild = v;
		}
	}
	
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (v != bigChild && v != p)
			sack(v, u, 0);
	}
	
	if (bigChild != -1) {
		sack(bigChild, u, 1);
		big[bigChild] = 1;
	}
	
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (v == p || v == bigChild)
			continue;
		for(int j = in[v]; j <= out[v]; j++) {
			int x = id[j];
			long long need = k + sum[u] * 2 - sum[x];
			if (path[need]) 
				ans = min(ans, path[need] + depth[x] - 2 * depth[u]);
		}
		for(int j = in[v]; j <= out[v]; j++) {
			int x = id[j];
			modify(x, 1);
		}
	}
	
	modify(u, 1);
	if (path[k + sum[u]])
			ans = min(ans, path[k + sum[u]] - depth[u]);
	if (bigChild != -1)
		big[bigChild] = 0;
	if (!keep) {
		for(int i = in[u]; i <= out[u]; i++) {
			int v = id[i];
			modify(v, -1);
		}
	}
	
}

int solve() {
	dfs(0, -1);
	sack(0, -1, 1);
	return (ans == oo ? -1 : ans);
}

int best_path(int N, int K, int H[][2], int L[]) {
	n = N, k = K;
	for(int i = 0; i < n - 1; i++) {
		int u = H[i][0], v = H[i][1], w = L[i];
		adj[u].push_back(II(v, w));
		adj[v].push_back(II(u, w));
	}
	return solve();
}

int main() {
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++) 
		cin >> h[i][0] >> h[i][1] >> l[i];
	cout << best_path(n, k, h, l);
	return 0;
}