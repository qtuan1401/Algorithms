#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;
const int lim = 1e6 + 10;

typedef pair < int , int > II;

long long sz[lim * 4], sum[lim * 4];
int x[MXN], t[MXN];
vector < II > adj[MXN];


void update(int id, int l, int r, int p, int val) {
    //cout << id << " " << l << " " << r << " " << p << " " << val << endl;
    if (l == r && r == p) {
        sz[id] += val;
        sum[id] += 1ll * p * val;
        return ;
    }
    int mid = (l + r) / 2;
    if (p <= mid)
        update(id * 2, l, mid, p, val);
    else 
        update(id * 2 + 1, mid + 1, r, p, val);
    sz[id] = sz[id * 2] + sz[id * 2 + 1];
    sum[id] = sum[id * 2] + sum[id * 2 + 1];
}

long long get(int id, int l, int r, long long tm) {
    if (l == r)
        return min(tm / l, sz[id]);
    int mid = (l + r) / 2;
    if (tm > sum[id * 2])
        return sz[id * 2] + get(id * 2 + 1, mid + 1, r, tm - sum[id * 2]);
    else 
        return get(id * 2, l, mid, tm);
}

long long dfs(int u, long long tm) {
    //cout << u << endl;
    //cout << lim << " " << t[u] << " " << x[u] << endl;
    update(1, 1, lim, t[u], x[u]);
    //cout << u << endl;
    long long ans = get(1, 1, lim, tm), mx1 = 0, mx2 = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        II cur = adj[u][i];
        long long dst = 2ll * cur.second;
        if (tm < dst) continue;
        //cout << cur.first << " " << cur.second << endl;
        long long res = dfs(cur.first, tm - dst);
        if (res > mx1) {
            mx2 = mx1;
            mx1 = res;
        } else if (res > mx2) {
            mx2 = res;
        }
    }
    update(1, 1, lim, t[u], -x[u]);
    if (u == 1) 
        return max(ans, mx1);
    else 
        return max(ans, mx2);
}

int main() {
    ios_base::sync_with_stdio(0);

    int n; long long T;
    cin >> n >> T;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    for(int i = 1; i <= n; i++)
        cin >> t[i];
    for(int i = 2; i <= n; i++) {
        int p, l;
        cin >> p >> l;
        //cout << p << " " << i << endl;
        adj[p].push_back(II(i, l));
    }

    cout << dfs(1, T);
}