#include <bits/stdc++.h>

using namespace std;

const int md = 1e5 + 10;

struct node {
	int u, v, id;
	node(int _u = 0, int _v = 0, int _id = 0) {
		u = _u;
		v = _v;
		id = _id;
	}
};

int n, m, mn, mx, best, uu, vv;
int fa[md], fb[md], par[md], siz[md];
node ans[md];
vector < node > path[3];
bool  dd[md];	

void init() {
	for(int i = 1; i <= n; i++)
		par[i] = i, siz[i] = 1;
}

void Union(int u, int v) {
	if (siz[u] <= siz[v])
		par[u] = v, siz[v] += siz[u];
	else
		par[v] = u, siz[u] += siz[v];
}

int root(int i) {
	if (par[i] == i)
		return i;
	else
		return par[i] = root(par[i]);
}

int main() {
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		//cout << n << " " << m << endl;
		path[1].clear();
		path[2].clear();
		for(int i = 1; i <= n; i++)
			dd[i] = false;
		//cout << n << " " << m << endl;
		for(int i = 1; i < n; i++)
			cin >> fa[i];
		for(int i = 1; i < n; i++)
			cin >> fb[i];
		for(int i = 1; i <= m; i++) {
			int u, v, type;
			cin >> u >> v >> type;
			//type--;
			//cout << u << " " << v << " " << type << endl;
			path[type].push_back(node(u, v, i));
		}
		init();
		mx = mn = 0;
		for(int i = 0; i < path[1].size(); i++) {
			uu = root(path[1][i].u);
			vv = root(path[1][i].v);
			if (uu != vv) {
				mx++;
				Union(uu, vv);
			}
		}
		init();
		for(int i = 0; i < path[2].size(); i++) {	
			uu = root(path[2][i].u);
			vv = root(path[2][i].v);
			if (uu != vv) 
				Union(uu, vv);
		}
		for(int i = 0; i < path[1].size(); i++) {
			uu = root(path[1][i].u);
			vv = root(path[1][i].v);
			if (uu != vv) {
				dd[path[1][i].id] = true;
				ans[++mn] = node(path[1][i].u, path[1][i].v, path[1][i].id);
				//cout << i << endl;
				Union(uu, vv);
			}
		}
		best = 2e9 + 10;
		int pos = 0;
		for(int i = mn; i <= mx; i++) 
			if (best > fa[i] + fb[n - 1 - i]) {
				//cout << i <<" " << n - 1 - i << endl;
				best = fa[i] + fb[n - 1 - i];
				pos = i;
			}
		//cout << mn <<" " << mx << endl;
		//cout << best << endl;
		init();
		for(int i = 1; i <= mn; i++) {
			int uu = root(ans[i].u);
			int vv = root(ans[i].v);
			if (uu != vv)
				Union(uu, vv);
			//cout << ans[i].u <<" " <<ans[i].v <<endl;
		}
		for(int i = 0; i < path[1].size(); i++) {
			if (dd[path[1][i].id])
				continue;
			if (mn == pos)
				break;
			uu = root(path[1][i].u);
			vv = root(path[1][i].v);
			if (uu != vv) {
				ans[++mn] = node(0, 0, path[1][i].id);
				Union(uu, vv);
			}
		}
		//cout << mn << endl;
		for(int i = 0; i < path[2].size(); i++) {
			uu = root(path[2][i].u);
			vv = root(path[2][i].v)	;
			if (mn == n - 1)
				break;
			if (uu != vv) {
				ans[++mn] = node(0, 0, path[2][i].id);
				Union(uu, vv);
			}
		}
		//cout << mn << endl;
		for(int i = 1; i <= mn; i++)
			cout << ans[i].id << " ";
		cout << '\n';
	}
	return 0;
}