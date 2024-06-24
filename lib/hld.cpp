// codeforces 1975e

#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

const int MXN = 2e5 + 10;

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

int deg[MXN], child[MXN], par[MXN], depth[MXN], posVtx[MXN], chainHead[MXN], chainId[MXN], vtx[MXN];
vector < int > adj[MXN];
int n, m, nChain, cnt, tot;
int seg[MXN * 4];
vector < int > children[MXN];

void calcChild(int u) {
    child[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (par[u] == v || depth[u] == depth[v])
            continue;
        calcChild(v);
        child[u] += child[v];
    }
} 

void bfs(int root) {
    queue < int > qu;
    qu.push(root);
    depth[root] = 1;
    while (qu.size()) {
        int u = qu.front(); qu.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (par[u] == v || depth[v] > 0)
                continue;
            par[v] = u;
            depth[v] = depth[u] + 1;
            children[u].push_back(v);
            qu.push(v);
        }
    }
}

void hld(int u) {
    if (chainHead[nChain] == 0)
        chainHead[nChain] = u;
    chainId[u] = nChain;
    posVtx[u] = ++tot;
    vtx[tot] = u;
    int mxVtx = -1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (par[u] == v || depth[u] == depth[v])
            continue;
        if (mxVtx == -1 || child[v] > child[mxVtx])
            mxVtx = v;
    }
    if (mxVtx > -1)
        hld(mxVtx);
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (par[u] != v && v != mxVtx && depth[u] != depth[v]) {
            nChain++;
            hld(v);
        }
    }
}

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r)
        return ;
    
    if (l == r && r == pos) {
        seg[id] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    // cout << id << " " << l << " " << r << " " << u << " " << v << endl;
    if (v < l || r < u)
        return 0;
    if (u <= l && r <= v)
        return seg[id];
    int mid = (l + r) >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int getLca(int u, int v) {
    while (chainId[u] != chainId[v]) {
        if (depth[chainHead[chainId[u]]] > depth[chainHead[chainId[v]]])
            swap(u, v);
        v = par[chainHead[chainId[v]]];
    }
    if (depth[u] > depth[v])
        return v;
    return u;
}

int jump(int v, int t) {
    int res = 0;
    // cout << v << " " << t << endl;
    while (chainId[v] != chainId[t]) {
        // cout << v << " *** " << t << " " << endl;
        res += get(1, 1, n, posVtx[chainHead[chainId[v]]], posVtx[v]);
        v = par[chainHead[chainId[v]]];
    }
    // cout << posVtx[t] << " ** " << posVtx[v] << endl;
    res += get(1, 1, n, posVtx[t], posVtx[v]);
    return res;
}  

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int q;
        cin >> n >> q;
        vector < int > c(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bfs(1);
        calcChild(1);
        hld(1);

        int blacks = 0;      

        set < pii > b;
        set < int > leaves;
        for (int i = 1; i <= n; i++) {
            update(1, 1, n, posVtx[i], c[i]);
            if (c[i] == 1) {
                b.insert(pii(depth[i], i));
                deg[i]++;
                deg[par[i]]++;
            }
            blacks += c[i];
        }

        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1 && c[i] == 1) leaves.insert(i);
        }
        int u, v, top;

        deg[0] = 1000000000;

        while (q--) {
            int x;
            cin >> x;
            // cout << x << " " << c[x] << endl;
            if (c[x] == 0) {
                blacks++;
                b.insert(pii(depth[x], x));
                deg[x]++;
                if (deg[x] == 1) leaves.insert(x);
                if (leaves.find(par[x]) != leaves.end()) {
                    leaves.erase(leaves.find(par[x]));
                } 
                deg[par[x]]++;
            } else {
                blacks--;
                deg[x]--;
                if (leaves.find(x) != leaves.end()) leaves.erase(leaves.find(x));
                deg[par[x]]--;
                if (c[par[x]] == 1 && deg[par[x]] == 1) leaves.insert(par[x]);
                b.erase(b.find(pii(depth[x], x)));
            }
            c[x] = 1 - c[x];
            update(1, 1, n, posVtx[x], c[x]);
            if (b.size() == 0) {
                cout << "No\n";
                continue;
            } else if (b.size() == 1) {
                cout << "Yes\n";
                continue;
            }
            // find u v
            int top = b.begin() -> second; // lowest always lca
            int u = b.rbegin() -> second; // furthest 
            int v = u;
            for (auto & l : leaves) {
                if (l != top && l != u)  {
                    v = l;
                    break;
                }
            }
            if (getLca(u, top) != top || getLca(v, top) != top) {
                cout << "No\n";
                continue;
            }

            if (getLca(u, v) != u && getLca(u, v) != v && getLca(u, v) != top) {
                cout << "No\n";
                continue;
            }
            int cur = 0;
            int totVtx = 0;
            if (u == v) {
                if (depth[u] < depth[v]) u = v;  
                cur = jump(u, top);
                totVtx = depth[u] - depth[top] + 1;
            } else {
                cur = jump(u, top) + jump(v, top) - c[top];
                totVtx = depth[u] + depth[v] - depth[top] * 2 + 1;
            }
            // cout << u << " " << v << " " << cur << " " << totVtx << " " << depth[u] << " " << depth[v] << " " << depth[top] << endl;

            if (cur == blacks && cur == totVtx) {
                cout << "Yes\n";
            } else cout << "No\n";
        }

        // reset
        for (int i = 1; i <= n; i++) {
            child[i] = 0;
            par[i] = 0;
            depth[i] = 0;
            posVtx[i] = 0;
            chainHead[i] = 0;
            deg[i] = 0;
            chainId[i] = 0;
            vtx[i] = 0;
            adj[i].clear();
            children[i].clear();
        }

        for (int i = 1; i <= n * 4; i++) {
            seg[i] = 0;
        }
        nChain = cnt =  tot = 0;
    }
    return 0;
}