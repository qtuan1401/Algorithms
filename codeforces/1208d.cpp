#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const long long oo = 1e12;

long long seg[MAXN * 8], lazy[MAXN * 8], a[MAXN], ans[MAXN];
int n;

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

void propagate(int id, int l, int r) {
    if (lazy[id] != 0) {
        seg[id] += lazy[id];
        if (l != r) {
            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
        }
        lazy[id] = 0;
    } 
}

void update(int id, int l, int r, int u, int v, long long val) {
    propagate(id, l, r);
    if (v < l || u > r)
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
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

long long get(int id, int l, int r, int u, int v) {
    if (v < l || u > r)
        return oo;
    propagate(id, l, r);
    if (u <= l && r <= v)
        return seg[id];
    int mid = (l + r) >> 1;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int bsR(int l, int r) {
    int pos = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (get(1, 1, n, mid, n) == 0) {
            pos = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return pos;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    //return 0;
    for(int i = 1; i <= n; i++) {
        int pos = bsR(1, n);
        ans[pos] = i;
        update(1, 1, n, pos + 1, n, -i);
        update(1, 1, n, pos, pos, oo);
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}