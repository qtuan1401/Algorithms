#include <bits/stdc++.h>

using namespace std;

vector < int > seg, lazy;

void update(int id, int l, int r, int u, int v, int val) {
    if(lazy[id] != 0) {
        seg[id] += lazy[id];
        if (l != r) {
            lazy[id * 2 + 1] += lazy[id];             
            lazy[id * 2 + 2] += lazy[id];              
        }
        lazy[id] = 0;                                  
    }
    if (l > r || l > v || r < u)
        return ;
    if(u <= l && r <= v) {
        seg[id] += val;
        if(l != r) {
            lazy[id * 2 + 1] += val;
            lazy[id * 2 + 2] += val;
        }
        return ;
    }
    int mid = (l + r) / 2;
    update(id * 2 + 1, l, mid, u, v, val);      
    update(id * 2 + 2, mid + 1, r, u, v, val);  
    seg[id] = max(seg[id * 2 + 1], seg[id * 2 + 2]);
}

int query(int id, int l, int r, int u, int v) {
    if (l > r || l > v || r < u)
        return 0;
    if (lazy[id] != 0) {
        seg[id] += lazy[id];
        if (l != r) {
            lazy[id * 2 + 1] += lazy[id];             
            lazy[id * 2 + 2] += lazy[id];              
        }
        lazy[id] = 0;                                  
    }
    if (u <= l && r <= v)
        return seg[id];
    int mid = (l + r) / 2;
    int p1 = query(id * 2 + 1, l, mid, u, v);
    int p2 = query(id * 2 + 2, mid + 1, r, u, v);
    return max(p1, p2);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {

        int n;
        cin >> n;
        vector < char > c(n);
        vector < int > l(n), r(n);

        vector < int > val;
        for (int i = 0; i < n; i++) {
            cin >> c[i] >> l[i] >> r[i];
            val.push_back(l[i]);
            val.push_back(r[i]);
        }

        sort(val.begin(), val.end());
        val.erase(unique(val.begin(), val.end()), val.end());

        int len = val.size();
        seg.resize(len * 8, 0);
        lazy.resize(len * 8, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int pl = lower_bound(val.begin(), val.end(), l[i]) - val.begin();
            int pr = lower_bound(val.begin(), val.end(), r[i]) - val.begin();

            int w = c[i] == '+' ? 1 : -1;
            cnt += w;
            update(0, 0, len - 1, pl, pr, w);
            // cout << query(0, 0, len - 1, 0, len - 1) << endl;
            if (query(0, 0, len - 1, 0, len - 1) == cnt) cout << "NO\n";
            else cout << "YES\n";
        }

    }
    return 0;
}