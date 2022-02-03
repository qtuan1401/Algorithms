#include <bits/stdc++.h>

using namespace std;

const int md = 1e5 + 10;

struct node {
    int gcd = 0, mn = 1e9 + 10, cnt = 0;
    node(int _gcd = 0, int _mn = 0, int _cnt = 0) {
        gcd = _gcd;
        mn = _mn;
        cnt = _cnt;
    }
} seg[md * 4];

vector < int > v, cnt[md];
int a[md];
int n, m;

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = node(a[l], a[l], 1);
        return ;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id].gcd = __gcd(seg[id * 2].gcd, seg[id * 2 + 1].gcd);
    seg[id].mn = min(seg[id * 2].mn, seg[id * 2 + 1].mn);
    if (seg[id * 2].mn < seg[id * 2 + 1].mn) 
        seg[id].cnt = seg[id * 2].cnt;
    else if (seg[id * 2].mn > seg[id * 2 + 1].mn) 
        seg[id].cnt = seg[id * 2 + 1].cnt;
    else 
        seg[id].cnt = seg[id * 2].cnt + seg[id * 2 + 1].cnt;
}

node get(int id, int l, int r, int u, int v) {
    if (l > v || r < u)
        return node(0, 1e9 + 10, 0);
    if (u <= l && r <= v)
        return seg[id];
    int mid = (l + r) >> 1;
    node L = get(id * 2, l, mid, u, v); 
    node R = get(id * 2 + 1, mid + 1, r, u, v);
    int gcd = __gcd(L.gcd, R.gcd);
    int mn = min(L.mn, R.mn);
    int cnt = 0;
    if (L.mn > R.mn) 
        cnt = R.cnt;
    else if (L.mn < R.mn)  
        cnt = L.cnt;
    else 
        cnt = L.cnt + R.cnt;
    return node(gcd, mn, cnt);
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        node cur = get(1, 1, n, l, r);
        cout << r - l + 1 - cur.cnt * (cur.gcd == cur.mn);
        cout << '\n';
    }
    return 0;
}