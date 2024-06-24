// atcoder abc327
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

const int LIM = 2e5;

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
        int n, d, w;
        cin >> n >> d >> w;
        vector < vector < int > > pos(LIM + 1);
        for (int i = 0; i < n; i++) {
            int t, x;
            cin >> t >> x;
            x--;
            pos[t].push_back(x);
        }

        seg.resize(LIM * 8, 0);
        lazy.resize(LIM * 8, 0);
        for (int i = 1; i <= min(d, LIM); i++) {
            for (auto & e : pos[i]) {
                update(0, 0, LIM - 1, e, min(LIM - 1, e + w - 1), 1);
            }          
        }

        int ans = query(0, 0, LIM - 1, 0, LIM - 1);
        for (int i = d + 1; i <= LIM; i++) {
        
            for (auto & e : pos[i - d]) {
                update(0, 0, LIM - 1, e, min(LIM - 1, e + w - 1), -1);
            }
            for (auto & e : pos[i]) {
                update(0, 0, LIM - 1, e, min(LIM - 1, e + w - 1), 1);
            }

            // if (query(0, 0, LIM - 1, 0, LIM - 1) != 0) {
            //     cout << i << " " <<  query(0, 0, LIM - 1, 0, LIM - 1) << endl;
            //     cout << i - d - 1 << endl;
            // }
            ans = max(ans, query(0, 0, LIM - 1, 0, LIM - 1));
        }

        cout << ans << '\n';
    }
    return 0;
}