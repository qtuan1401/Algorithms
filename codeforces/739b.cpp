#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

long long a[MXN], f[MXN], sum[MXN];
int n;

vector < pair < long long, int > > adj[MXN], path;

void dfs(int u) {
	f[u]++;
    int pos = lower_bound(path.begin(), path.end(), make_pair(sum[u] - a[u], -1)) - path.begin() - 1;  
	f[path[pos].second]--;
	path.push_back(make_pair(sum[u], u));
	for (int i = 0; i < adj[u].size(); i++) {
        pair < long long, int > cur = adj[u][i];
        long long w = cur.first;
        int v = cur.second;
		sum[v] = sum[u] + w;
		dfs(v);
		f[u] += f[v];
	}
	path.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    path.push_back(make_pair(-1e16, 0));
	
	for(int i = 1; i < n; i++) {
		int v, w;
		cin >> v >> w;
		adj[v].push_back(make_pair(w, i + 1));
	}

	dfs(1);

	for(int i = 1; i <= n; i++) 
        cout << f[i] - 1 << " ";
}