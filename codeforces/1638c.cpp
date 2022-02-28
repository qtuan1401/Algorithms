#include <bits/stdc++.h>

using namespace std;

vector < int > a, sg, fw, f;

void up(int x, int val, int n) {
    while (x <= n) {
        fw[x] = max(fw[x], val);
        x += (x & (-x));
    }
}

int query(int x) {
    int res = 0;
    while (x > 0) {
        res = max(res, fw[x]);
        x -= (x & (-x));
    }
    return res;
}

void build(int id, int l, int r) {
    if (l == r) {
        sg[id] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    sg[id] = max(sg[id * 2], sg[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return -1;
    if (u <= l && r <= v) return sg[id];
    int mid = (l + r) >> 1;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}


int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        a.clear();
        a.resize(n + 1);

        f.clear();
        f.resize(n + 1);

        sg.clear();
        sg.resize((n + 1) * 4);

        fw.clear();
        fw.resize(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        build(1, 1, n);
        
        for (int i = n; i >= 1; i--) {
            up(a[i], i, n);
            f[i] = query(a[i]);
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (get(1, 1, n, 1, i) == a[i]) 
                res += get(1, 1, n, i, f[i]) <= a[i];
        }

        cout << res << '\n';
    }
    return 0;
}