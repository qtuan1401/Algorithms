#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int seg[25][MXN * 8], lazy[25][MXN * 8], bit[25][MXN * 8];
int n;

void build(int id, int l, int r, int b) {
    if (l == r) {
        seg[b][id] = bit[b][l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid, b);
    build(id * 2 + 1, mid + 1, r, b);
    seg[b][id] = seg[b][id * 2] + seg[b][id * 2 + 1];
}

inline int getBit(int x, int i) {
    return (x >> i) & 1;
}

void update(int id, int l, int r, int u, int v, int b) {
    if (lazy[b][id] == 1) {
        seg[b][id] = (r - l + 1) - seg[b][id];
        if (l != r) {
            lazy[b][id * 2] ^= 1;
            lazy[b][id * 2 + 1] ^= 1;  
        }
        lazy[b][id] = 0;
    }
    if (v < l || r < u)
        return ;
    if (u <= l && r <= v) {
        seg[b][id] = (r - l + 1) - seg[b][id];
        if (l != r) {
            lazy[b][id * 2] ^= 1;
            lazy[b][id * 2 + 1] ^= 1;
        }
        return ;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, b);
    update(id * 2 + 1, mid + 1, r, u, v, b);
    seg[b][id] = seg[b][id * 2] + seg[b][id * 2 + 1];
}

int get(int id, int l, int r, int u, int v, int b) {
    if (v < l || r < u)
		return 0;
    if (lazy[b][id] == 1) {
        seg[b][id] = (r - l + 1) - seg[b][id];
        if (l != r) {
            lazy[b][id * 2] ^= 1;
            lazy[b][id * 2 + 1] ^= 1;
        }
        lazy[b][id] = 0;
    }
    if (u <= l && r <= v)
        return seg[b][id];
    int mid = (l + r) >> 1;
    return get(id * 2, l, mid, u, v, b) + get(id * 2 + 1, mid + 1, r, u, v, b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < 20; j++)
            bit[j][i] = getBit(x, j);
    }
    for(int i = 0; i < 20; i++)
        build(1, 1, n, i);
    int q;
    cin >> q;
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            long long res = 0;
            for(int i = 0; i < 20; i++)
                res += (1ll << i) * get(1, 1, n, l, r, i);
            cout << res << '\n';
        } else {
            int x;
            cin >> x;
            for(int i = 0; i < 20; i++)
                if (getBit(x, i))
                    update(1, 1, n, l, r, i);
        }
    }
    return 0;
}