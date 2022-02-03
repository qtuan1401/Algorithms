#include <bits/stdc++.h>
using namespace std;
#define md int(2e5 + 5)
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FORR(i, a, b) for(int i = (a); i < (b); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define INF int(1e8)
int r, n, q, m;
struct node {
    int low, high;
} p[8 * md];
vector< int > adj[md];
int a[md], par[md], dd[md], amin[md], cnt, pos[md], Left, Right, res;
inline void dfs(int u) {
    FORR(i, 0, adj[u].size()) {
        int v = adj[u][i];
        if (v != par[u]) {
            par[v] = u;
            a[++r] = v;
            dfs(v);
            a[++r] = u;
        }
    }
}
inline void build(int l, int r, int k) {
    if (l == r) {
        p[k].low = p[k].high = pos[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, k * 2);
    build(mid + 1, r, k * 2 + 1);
    p[k].low = min(p[k * 2].low, p[k * 2 + 1].low);
    p[k].high = max(p[k * 2].high, p[k * 2 + 1].high);
}
inline void get(int a, int b, int l, int r, int k) {
    if (a <= l && r <= b) {
        Left = min(Left, p[k].low);
        Right = max(Right, p[k].high);
        return;
    }
    if (r < a || l > b)
        return;
    int mid = (l + r) >> 1;
    get(a, b, l, mid, k * 2);
    get(a, b, mid + 1, r, k * 2 + 1);
}
inline void build1(int l, int r, int k) {
    if (l == r) {
        amin[k] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build1(l, mid, k * 2);
    build1(mid + 1, r, k * 2 + 1);
    amin[k] = min(amin[k * 2], amin[k * 2 + 1]);
}
inline void get1(int a, int b, int l, int r, int k) {
    if (a <= l && r <= b) {
        res = min(res, amin[k]);
        return;
    }
    if (r < a || l > b)
        return;
    int mid = (l + r) >> 1;
    get1(a, b, l, mid, k * 2);
    get1(a, b, mid + 1, r, k * 2 + 1);
}
int main() {
//    freopen("test.inp.txt", "r", stdin);
    scanf("%d %d", &n, &q);
    REP(i, n - 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1] = 1;
    a[1] = 1;
    r = 1;
    dfs(1);
    //REP(i, r)
      //  cout << a[i] << " ";
    //cout << endl;
    REP(i, r)
        if (!pos[a[i]])
            pos[a[i]] = i;
    //REP(i, n)
      //  cout << pos[i] << " ";
    //cout << endl;
    build(1, n, 1);
    build1(1, r, 1);
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u == v) {
            printf("%d\n", u);
        }
        else {
            Left = INF;
            Right = -INF;
            get(u, v, 1, n, 1);
            //cout  << Left <<  " "<< Right << endl;
            res = INF;
            get1(Left, Right, 1, r, 1);
            printf("%d\n", res);
        }
    }
    return 0;
}

