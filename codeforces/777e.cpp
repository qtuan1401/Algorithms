#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;

const int MXN = 1e5 + 10;
const long long oo = 1e18;

long long seg[MXN * 8], lazy[MXN * 8];
pair < int, int> temp[MXN * 2];
int a[MXN * 2];
long long h[MXN];
int n;

struct node {
    int a, b;
    long long h;
    node(const int & a = 0, const int & b = 0, const long long & h = 0) : a(a), b(b), h(h) { }
    bool operator < (const node & x) const {
        if (b == x.b)
            return a > x.a;
        return (b > x.b);
    }
} c[MXN];

void update(int id, int l, int r, int u, int v, long long val) {
	if (lazy[id] != 0) {
        if (seg[id] < lazy[id]) {
            seg[id] = lazy[id];
            if (l != r) {
                lazy[id * 2] = lazy[id];
                lazy[id * 2 + 1] = lazy[id]; 
            }
        }
		lazy[id] = 0;
	} 
	if (v < l || r < u)
		return ;
	if (u <= l && r <= v) {
        if (seg[id] < val) {
            seg[id] = val;
            if (l != r) {
                lazy[id * 2] = val;
                lazy[id * 2 + 1] = val;
            }
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
        if (seg[id] < lazy[id]) {
            seg[id] = lazy[id];
            if (l != r) {
                lazy[id * 2] = lazy[id];
                lazy[id * 2 + 1] = lazy[id]; 
            }
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
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp[i].first >> temp[i + n].first >> h[i];
        temp[i].second = i;
        temp[i + n].second = i + n;
    }
    sort(temp, temp + 2 * n);
    //for(int i = 0; i < 2 * n; i++)
    //    cout << temp[i].first << " ";
    int cnt = a[temp[0].second] = 1;
    for(int i = 1; i < 2 * n; i++)
        a[temp[i].second] = cnt += (temp[i].first != temp[i - 1].first);

    for(int i = 0; i < n; i++)
        c[i] = node(a[i], a[i + n], h[i]);

    sort(c, c + n);
    //for(int i = 0; i < n; i++)
    //    cout << c[i].a << " " << c[i].b << " " << c[i].h << endl;
    long long res = 0;
    for(int i = 0; i < n; i++) {
        //cout << c[i].a << " " << c[i].b << " " << c[i].h << endl;
        long long sum = get(1, 1, 2 * n, c[i].b, c[i].b);
        //cout << sum << " " << sum + c[i].h << endl;
        res = max(res, sum + c[i].h);
        update(1, 1, 2 * n, c[i].a + 1, c[i].b, sum + c[i].h);
        //cout << get(1, 1, 2 * n, 2, 2) << endl;
    }

    cout << res;
    return 0;
}