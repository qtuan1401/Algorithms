#include <bits/stdc++.h>
using namespace std;

const int lim = 1e6;
const long long oo = 1e15;
const int MAXN = 1e6 + 10;

long long lazy[MAXN * 8], seg[MAXN * 8], b[MAXN];
int n, m, p;

struct node {
	int ca, cb, c, id;
	bool operator < (const node &x) const {
		if (ca == x.ca)
			return id > x.id;
		return ca < x.ca;
	}
} a[MAXN];

void build(int id, int l, int r) {
	if (l == r) {
		seg[id] = b[l];
		return ;
	}
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}

void update(int id, int l, int r, int u, int v, long long val) {
	if (lazy[id] != 0) {
		seg[id] += lazy[id];
		if (l != r) {
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id]; 
		}
		lazy[id] = 0;
	} 
	if (v < l || r < u)
		return ;
	if (u <= l && r <= v) {
		seg[id] += val;
		if (l != r) {
			lazy[id * 2] += val;
			lazy[id * 2 + 1] += val;
		}
		return ;
	}
	int mid = (l + r) >> 1;
	update(id * 2, l, mid, u, v, val);
	update(id * 2 + 1, mid + 1, r, u, v, val);
	seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}

long long get(int id, int l, int r, int u, int v) {
	if (v < l || r < u)
		return -oo;
	if (lazy[id] != 0) {
		seg[id] += lazy[id];
		if (l != r) {
			lazy[id * 2] += lazy[id];
			lazy[id * 2 + 1] += lazy[id];
		}
		lazy[id] = 0;
	}
	if (u <= l && r <= v)
		return seg[id];
	int mid = (l + r) >> 1;
	return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
	//freopen("test.in", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> p;
	for(int i = 1; i <= n; i++) { 
		cin >> a[i].ca >> a[i].c;
		a[i].id = 1;
	}
	for(int i = 1; i <= lim; i++)
		b[i] = -1e15;
	for(int i = 1; i <= m; i++) {
		long long x, c;
		cin >> x >> c;
		b[x] = max(b[x], -c);		
	}
	build(1, 1, lim);	
	for(int i = n + 1; i <= n + p; i++) {
		cin >> a[i].ca >> a[i].cb >> a[i].c;
		a[i].id = 0;
	}
	//cout << get(1, 1, lim, 1, lim) << endl;
	//update(1, 1, lim, 2, lim, 4);
	//cout << get(1, 1, lim, 1, lim) << endl;
	//for(int i = 1; i <= 10; i++)
	//	cout << get(1, 1, lim, i, i) << " ";
	n += p;
	sort(a + 1, a + 1 + n);
	long long ans = -1e18;
	for(int i = 1; i <= n; i++) {
		//cout << "(" << a[i].ca << " " << a[i].id << ") ";
		if (a[i].id == 1) {
			ans = max(ans, get(1, 1, lim, 1, lim) - a[i].c);
		//	cout << ans << " " << get(1, 1, lim, 1, lim) << endl;
		} else {
		//	cout << a[i].cb << " " << a[i].c << endl;
			update(1, 1, lim, a[i].cb + 1, lim, a[i].c);
		}
	}
	
	cout << ans;
	return 0;
}
