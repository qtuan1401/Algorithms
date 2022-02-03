#include <bits/stdc++.h>

using namespace std;

const int md = 1e5 + 10;

int num[md], low[md], root[md], u[md], v[md], deg_in[md], deg_out[md], par[md];
int n, m, cnt, r, in, out;
vector< int > adj[md];
stack< int > st;

void tarjan(int u) {
	st.push(u);
	num[u] = low[u] = ++cnt;
	for(int i=0;i<adj[u].size();i++) {
		int v = adj[u][i];
		if (num[v])
			low[u] = min(num[v], low[u]);
		else {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if (low[u] == num[u]) {
		r++;
		int v;
		do  {
			v = st.top();
			root[v] = r;
			st.pop();
			num[v] = low[v] = 1e9;
		} while (v != u);
		par[r] = u;
	}
}

int main() {
//	freopen("test.inp", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++) {
		cin >> u[i] >> v[i];
		adj[u[i]].push_back(v[i]);
	}

	for(int i=1;i<=n;i++) 
		if (!num[i])
			tarjan(i);

	for(int i=1;i<=m;i++) {
		if (root[u[i]] != root[v[i]]) {
			deg_in[root[u[i]]]++;
			deg_out[root[v[i]]]++;
		}
	}

	for(int i=1;i<=r;i++)
		if (deg_in[i] == 0)
			in++;
		else if (deg_out[i] == 0)
			out++;

	if (in == 1 && out == 1) {
		cout << "YES\n";
		for(int i=1;i<=r;i++) {
			if (deg_in[i] == 0) {
				cout << par[i] << " ";
				break;
			}
		}
		for(int i=1;i<=r;i++) {
			if (deg_out[i] == 0) {
				cout << par[i];
				break;
			}
		}
	} else cout << "NO";
	return 0;
}