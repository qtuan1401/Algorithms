#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > II;
const int MXN = 1e5 + 10;
const long long INF = 1e18;

long long seg[MXN * 4];
int n, p;
long long ans[MXN], a[MXN];

void update(int id, int l, int r, int pos, long long v) {
    if (pos < l || pos > r)
        return ;
    if (l == r) {
        seg[id] = v;
        return ;
    }

    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, v);
    update(id * 2 + 1, mid + 1, r, pos, v);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

long long get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return INF;
    if (u <= l && r <= v)
        return seg[id];
    int mid = (l + r) >> 1;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int bs(int l, int r, long long v) {
    int pos = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (get(1, 1, n, 1, mid) <= v) {
            pos = mid;
            r = mid - 1;
        } else 
            l = mid + 1;
    }
    return pos;
}

II c[MXN];

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> p;
    fill(seg, seg + MXN, INF);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }

    long long mn = get(1, 1, n, 1, n);
    for (int i = 1; i <= n; i++) {
        int pos = bs(1, n, mn);
        if (pos == -1) 
            mn = get(1, 1, n, 1, n);
        if (mn == INF)
            break;
        pos = bs(1, n, mn);
        mn += p;
        ans[pos] = mn;
        // cout << pos << endl;
        int x = pos - 1;
        while (x > 0) {
            int z = get(1, 1, n, 1, x);
            if (z == INF || z >= mn)
                break;
            int np = bs(1, x, z);
            // cout << np << " * ";
            if (np == -1)
                break;
            mn += p;
            ans[np] = mn;
            update(1, 1, n, np, INF);
            x = np - 1;
        }
        // cout << endl;
        update(1, 1, n, pos, INF);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}