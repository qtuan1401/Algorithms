#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

vector < int > adj[MAXN], vec[MAXN];
int col[MAXN], cnt[MAXN], sz[MAXN];
long long res[MAXN], sum[MAXN];
int n;

void countSize(int u, int p) {
	sz[u] = 1;
	for(auto v : adj[u]) {
		if (v == p)
			continue;
		countSize(v, u);
		sz[u] += sz[v];
	}
}

void modify(int u, int val) {
	sum[cnt[col[u]]] -= col[u];
	cnt[col[u]] += val;
	sum[cnt[col[u]]] += col[u];
}

int dfs(int u, int p, int keep) {
	int bigChild = -1, mxSize = -1, mx = 0;
	//cout << u << "*" << keep << endl;
	for(auto v : adj[u]) {
		if (v == p) continue;
		if (mxSize < sz[v]) {
			mxSize = sz[v];
			bigChild = v;
		}
		//cout << v << " " << sz[v] << endl;
	}
	for(auto v : adj[u])
		if (v != p && v != bigChild)
			dfs(v, u, 0);
	if (bigChild != -1) {
		mx = max(mx, dfs(bigChild, u, 1));
		swap(vec[u], vec[bigChild]);
	}
	vec[u].push_back(u);
	modify(u, 1);
	mx = max(mx, cnt[col[u]]);
	for(auto v : adj[u]) {
		if (v == p || v == bigChild)
			continue;
		for(auto x : vec[v]) {
			modify(x, 1);
			mx = max(mx, cnt[col[x]]);
			vec[u].push_back(x);
		}
	}
	res[u] = sum[mx];
	if (keep == 0) {
		for(auto v : vec[u]) 
			modify(v, -1);
	}
	return mx;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> col[i];
	for(int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	countSize(1, 1);
	dfs(1, 1, 1);
	for(int i = 1; i <= n; i++)
		cout << res[i] << " ";
	return 0;
}