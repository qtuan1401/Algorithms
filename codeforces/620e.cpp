#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 10;

long long lazy[MAXN * 4], seg[MAXN * 4];
int a[MAXN], st[MAXN], fn[MAXN], pos[MAXN], c[MAXN];
int n, m, cnt;
vector < int > adj[MAXN];

void update(int id, int l, int r, int u, int v, long long val) {
    //if (bit == 1)
    //    cout << id << " " << lazy[bit][id] << " " << val << endl;
	if (lazy[id] != -1) {
		seg[id] = lazy[id];
		if (l != r) {
			lazy[id * 2] = lazy[id];
			lazy[id * 2 + 1] = lazy[id]; 
		}
		lazy[id] = -1;
	} 
	if (v < l || r < u)
		return ;
	if (u <= l && r <= v) {
        //if (bit == 1)
        //    cout << bit << " " << id << " " << l << " " << r << " " << val << endl;
		seg[id] = val;
		if (l != r) {
			lazy[id * 2] = val;
			lazy[id * 2 + 1] = val;
		}
		return ;
	}
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);
	seg[id] = seg[id * 2] | seg[id * 2 + 1];
}

long long get(int id, int l, int r, int u, int v) {
	if (v < l || r < u)
		return 0;
	if (lazy[id] != -1) {
		seg[id] = lazy[id];
		if (l != r) {
			lazy[id * 2] = lazy[id];
			lazy[id * 2 + 1] = lazy[id];
		}
		lazy[id] = -1;
	}
	if (u <= l && r <= v)
		return seg[id];
	int mid = (l + r) >> 1;
	return get(id * 2, l, mid, u, v) | get(id * 2 + 1, mid + 1, r, u, v);
}

void buildTree(int u, int p) {
    st[u] = ++cnt;
    a[cnt] = u;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p)
            continue;
        buildTree(v, u);
    }
    fn[u] = cnt;
}

int main() {
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    buildTree(1, 1);

    //for(int i = 1; i <= n; i++)
    //    cout << a[i] << " ";

    for(int i = 1; i <= 4 * n; i++)
        lazy[i] = -1;

    for(int i = 1; i <= n; i++) {
        //cout << pos[a[i]] << " " << c[a[i]] << endl;
        update(1, 1, n, st[a[i]], st[a[i]], (1ll << c[a[i]]));
    }

    //cout << endl << endl << endl;

    while (m--) {
        int type, v, col;
        cin >> type >> v;
        //cout << v << " " << st[v] << " " << fn[v] << endl;
        if (type == 1) {
            cin >> col;
            update(1, 1, n, st[v], fn[v], (1ll << col));
            //c[v] = col;
        } else {
            int sum = 0;
            long long temp = get(1, 1, n, st[v], fn[v]);
            cout << __builtin_popcountll(temp) << '\n';
        }
        //for(int i = 1; i <= n; i++)
        //    for(int j = 1; j <= 60; j++)
        //        if (get(1, 1, n, st[a[i]], st[a[i]], j))
        //            cout << "(" << a[i] << " " << j << ") ";
        //cout << endl;
        //return 0;
    }
	return 0;
}
