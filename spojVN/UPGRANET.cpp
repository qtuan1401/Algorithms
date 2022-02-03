#include <bits/stdc++.h>

using namespace std;

struct node {
	int u, v, w, id;
	node(int _u = 0, int _v = 0, int _w = 0, int _id = 0) {
		u = _u;
		v = _v;
		w = _w;
		id = _id;
	}
};

typedef pair < int, int > ii;
const int md = 1e5 + 10;

bool cmp(node a, node b) {
	return (a.w > b.w);
}

vector < ii > adj[md];
node graph[md];
bool dd[md];
int par[md], p[md][50], depth[md], cost[md][50], lab[md], nlog = 0;
int n, m;
long long res;

int root(int i) {
	if (lab[i] == i)
		return i;
	else
		return lab[i] = root(lab[i]);
}

void kruskal() {
	for(int i = 1; i <= m; i++) {
		int u = graph[i].u;
		int v = graph[i].v;
		//cout << u << " " << v << endl;
		int ru = root(u);
		int rv = root(v);
		//cout << ru <<" " << rv << endl;
		if (ru != rv) {
			dd[graph[i].id] = true;
			lab[rv] = ru;
			//cout << graph[i].u <<" " << graph[i].v <<" " << graph[i].w << " " << graph[i].id << endl;
			adj[u].push_back(ii(v, graph[i].w));
			adj[v].push_back(ii(u, graph[i].w));
		}
	}
}

void build(int u) {
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		int w = adj[u][i].second;
		if (par[u] != v) {
			par[v] = u;
			cost[v][0] = w;
			depth[v] = depth[u] + 1;
			build(v); 
		}
	}
}

void prepare() {
	for(int i = 1; i <= n; i++)
		p[i][0] = par[i];
	for(int k = 1; k <= 17; k++)
		for(int i = 1; i <= n; i++) {
			p[i][k] = p[p[i][k - 1]][k - 1];
			//cout << p[i][k] << endl;
			cost[i][k] = min(cost[i][k - 1], cost[p[i][k - 1]][k - 1]);
			//cout << cost[i][k] << endl;
		}

}

int lca(int u, int v) {
	if (depth[v] > depth[u])
		swap(v, u);
	int mn = 1e6 + 10;
	//cout << u <<"* " << v << endl;
	for(int i = 17; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v]) {
			mn = min(mn, cost[u][i]);
	//		cout << u <<" " << p[u][i] << endl;
			//cout << mn << endl;
			u = p[u][i];
		}
	//cout << u <<" " << v << endl;	
	if (u == v) {
	//	cout << u << endl;
		return mn;
	}
	for(int i = 17; i >= 0; i--)
		if (p[u][i] != p[v][i]) {
			mn = min(mn, min(cost[u][i], cost[v][i]));
		//	cout << 
			u = p[u][i];
			v = p[v][i];
		}
	mn = min(mn, min(cost[u][0], cost[v][0]));
	//cout << par[u] << endl;
	return mn;
}

int main() {
	//freopen("test1.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[i] = node(u, v, w, i);
	}
	for(int i = 1; i <= n; i++)
		lab[i] = i;
	sort(graph + 1, graph + 1 + m, cmp);
	kruskal();
	build(1);
	prepare();
	for(int i = 1; i <= m; i++) 
		if (!dd[graph[i].id]) { 
			//cout << i << endl;
			//cout << graph[i].u <<" " << graph[i].v << " " << graph[i].w << endl;
		//	cout << lca(graph[i].u, graph[i].v) << endl;
			res += lca(graph[i].u, graph[i].v) - graph[i].w;
		}
	cout << res;
	return 0;
}