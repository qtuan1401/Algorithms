#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > II;

const int MXN = 5e5 + 10;
const int INF = 1e9;

int seg[MXN * 4], a[MXN], ans[MXN], nxt[MXN];
vector < II > q[MXN];
int n, m;

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        seg[id] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        update(id * 2, l, mid, pos, val);
    else 
        update(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u)
        return INF;
    if (u <= l && r <= v)
        return seg[id];
    int mid = (l + r) >> 1;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    map < int, int > mp;

    for(int i = n; i >= 1; i--) {
        if (mp[a[i]] != 0) {
            nxt[i] = mp[a[i]];
        } else {
            nxt[i] = -1;
        }
        mp[a[i]] = i;
    }

    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        q[l].push_back(II(r, i));
    }
    fill(seg, seg + MXN * 4, INF);
    for(int i = n; i >= 1; i--) {
        if (nxt[i] != -1) {
            update(1, 1, n, nxt[i], nxt[i] - i);
            //cout << i << " "  << nxt[i] << " " << nxt[i] - i << endl;
            //cout << get(1, 1, n, i, nxt[i]) << endl;
        }
        for(int j = 0; j < q[i].size(); j++) {
            int res = get(1, 1, n, i, q[i][j].first);
            if (res == INF)
                ans[q[i][j].second] = -1;
            else
                ans[q[i][j].second] = res;
        }
    }

    for(int i = 0; i < m; i++)
        cout << ans[i] << '\n';
    return 0;
}