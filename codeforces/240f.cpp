#include <bits/stdc++.h>

using namespace std;

const int md = 1e5 + 10;

int sg[md << 3][30], lazy[md << 3][30], cnt[30];
int n, q;
string s;

void build(int k, int l, int r) {
    if (l == r) {
        sg[k][s[l] - 'a'] = 1;
        for(int i = 0; i <= 25; i++)
            lazy[k][i] = -1;
        return ;
    }
    int mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    for(int i = 0; i <= 25; i++) {
        sg[k][i] = sg[k << 1][i] + sg[k << 1 | 1][i];
        lazy[k][i] = -1;
    }
}

void propagate(int k, int l, int r, int i) {
    sg[k][i] = lazy[k][i] * (r - l + 1);
    if (l != r)
        lazy[k << 1][i] = lazy[k << 1 | 1][i] = lazy[k][i];
    lazy[k][i] = -1;
}

void update(int k , int l, int r, int u, int v, int val, int i) {
    if (lazy[k][i] != -1)
        propagate(k, l, r, i);
    if (u > r || l > v)
        return ;
    if (u <= l && r <= v) {
        lazy[k][i] = val;
        sg[k][i] = val * (r - l + 1);
        if (l != r)
            lazy[k << 1][i] = lazy[k << 1 | 1][i] = lazy[k][i];
        lazy[k][i] = -1;
        return ;
    }
    int mid = (l + r) >> 1;
    update(k << 1, l, mid, u, v, val, i);
    update(k << 1 | 1, mid + 1, r, u, v, val, i);
    sg[k][i] = sg[k << 1][i] + sg[k << 1 | 1][i];
}

int get(int k, int l, int r, int u, int v, int i) {
    if (lazy[k][i] != -1)
        propagate(k, l, r, i);
    if (u > r || l > v)
        return 0;
    if (u <= l && r <= v)
        return sg[k][i];
    int mid = (l + r) >> 1;
    return get(k << 1, l, mid, u, v, i) + get(k << 1 | 1, mid + 1, r, u, v, i);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    cin >> s;
    s = '#' + s;
    build(1, 1, n);
    while (q--) {
        int u, v;
        cin >> u >> v;
        bool ok = false;
        int zz = 0;
        for(int i = 0; i <= 25; i++) {
            cnt[i] = get(1, 1, n, u, v, i);
            //cout << cnt[i] << " ";
            if (cnt[i] & 1) {
                if (++zz == 2)
                    ok = true;
                if ((v - u + 1) % 2 == 0)
                    ok = true;
                //cout << zz << endl;
            }
        }
       // cout << endl;
       // cout << ok << endl;
        if (ok)
            continue;
        int l = u;
        int r = v;
        for(int i = 0; i <= 25; i++)
            if (cnt[i])
                update(1, 1, n, u, v, 0, i);
        int ss = -1;
        for(int i = 0; i <= 25; i++) {
            if (cnt[i] == 0)
                continue;
            if (cnt[i] & 1)
                ss = i;
            int val = cnt[i] >> 1;
            if (l + val - 1 < l || r - val + 1 > r)
                continue;
            //cout << l <<" " << l + val - 1 <<" " << r - val + 1 << " " << r << endl;
            update(1, 1, n, l, l + val - 1, 1, i);
            update(1, 1, n, r - val + 1, r, 1, i);
            l += val;
            r -= val;
        }
        //cout << l << " " << ss << endl;
        //cout << get(1, 1, n, 5, 7, 1) << endl;
        if (ss != -1)
            update(1, 1, n, l, l, 1, ss);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 25; j++)
            if (get(1, 1, n, i, i, j) == 1) {
                cout << char(j + 'a');
                break;
            }
    }
    return 0;
}
