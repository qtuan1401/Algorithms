#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

struct node {
    int pairs, open, close;
    node(const int _pairs = 0, const int _open = 0, const int _close = 0) {
        pairs = _pairs;
        open = _open;
        close = _close;
    }
};

node seg[MAXN * 4];
string s;

node add(node nodeL, node nodeR) {
    node res;
    
    int temp = min(nodeL.open, nodeR.close);

    res.pairs = nodeL.pairs + nodeR.pairs + temp;
    res.open = nodeL.open + nodeR.open - temp;
    res.close = nodeL.close + nodeR.close - temp;

    return res;
}

void build(int id, int l, int r) {
    if (l == r) {
        //cout << l << " " << s[l] << endl;
        if (s[l] == '(') 
            seg[id] = node(0, 1, 0);
        else 
            seg[id] = node(0, 0, 1);
        return ;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = add(seg[id * 2], seg[id * 2 + 1]);
}

node get(int id, int l, int r, int u, int v) {
    if (v < l || r < u)
        return node(0, 0, 0);
    if (u <= l && r <= v) 
        return seg[id];
    int mid = (l + r) / 2;
    return add(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    int n = s.size();
    s = "#" + s;
    build(1, 1, n);
    int q;
    cin >> q;
    //cout << get(1, 1, n, 1, 2).pairs << '\n';
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r).pairs * 2 << '\n';
    }
    return 0;
}