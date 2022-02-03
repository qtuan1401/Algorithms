#include <bits/stdc++.h>

using namespace std;

const long long MXN = 4e5 + 10;
const long long oo = 1e15;

long long child[MXN], par[MXN], depth[MXN], seg[MXN], lazy[MXN], posVtx[MXN], chainHead[MXN], chainId[MXN], tot, vtx[MXN];
vector < long long > adj[MXN];
long long n, m, nChain;

void buildTree(long long u) {
    child[u] = 1;
    for(long long i = 0; i < adj[u].size(); i++) {
        long long v = adj[u][i];
        if (par[u] == v)
            continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        buildTree(v);
        child[u] += child[v];
    }
}

void hld(long long u) {
    if (chainHead[nChain] == 0)
        chainHead[nChain] = u;
    chainId[u] = nChain;
    posVtx[u] = ++tot;
    vtx[tot] = u;
    long long mxVtx = -1;
    for(long long i = 0; i < adj[u].size(); i++) {
        long long v = adj[u][i];
        if (par[u] == v)
            continue;
        if (mxVtx == -1 || child[v] > child[mxVtx])
            mxVtx = v;
    }
    if (mxVtx > -1)
        hld(mxVtx);
    for(long long i = 0; i < adj[u].size(); i++) {
        long long v = adj[u][i];
        if (par[u] != v && v != mxVtx) {
            nChain++;
            hld(v);
        }
    }
}

void update(long long id, long long l, long long r, long long u, long long v, long long val) {
    if (lazy[id] != oo) {
        seg[id] = min(seg[id], lazy[id] - 2ll * depth[vtx[r]]);
        if (l != r) {
            lazy[id * 2] = min(lazy[id * 2], lazy[id]);
            lazy[id * 2 + 1] = min(lazy[id * 2 + 1], lazy[id]);
        }
        lazy[id] = oo;
    }
    if (v < l || r < u)
        return ;
    //cout << seg[id] << " " << l << " " << r << " " << val << " " << depth[vtx[r]] << endl;
    if (u <= l && r <= v) {
        seg[id] = min(seg[id], val - 2ll * depth[vtx[r]]);
        //cout << seg[id] << " " << l << " " << r << " " << val << " " << depth[vtx[r]] << endl;
        if (l != r) {
            lazy[id * 2] = min(lazy[id * 2], val);
            lazy[id * 2 + 1] = min(lazy[id * 2 + 1], val);
        }
        return ;
    }
    long long mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

long long get(long long id, long long l, long long r, long long u, long long v) {
    if (v < l || r < u)
        return oo;
    if (lazy[id] != oo) {
        seg[id] = min(seg[id], lazy[id] - 2 * depth[vtx[r]]);
        if (l != r) {
            lazy[id * 2] = min(lazy[id * 2], lazy[id]);
            lazy[id * 2 + 1] = min(lazy[id * 2 + 1], lazy[id]);
        }
        lazy[id] = oo;
    }
    if (u <= l && r <= v)
        return seg[id];
    long long mid = (l + r) >> 1;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

long long solve(long long v, long long val, long long type) {
    long long res = oo;
    while (v > 0) {
        if (type == 0) {
            update(1, 1, n, posVtx[chainHead[chainId[v]]], posVtx[v], val);
        } else
            res = min(res, get(1, 1, n, posVtx[chainHead[chainId[v]]], posVtx[v]));
        v = par[chainHead[chainId[v]]];
    }
    return res;
}

void solve() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout); 
    cin >> n >> m;
    nChain = 0; tot = 0;
    fill(child, child + MXN, 0);
    fill(par, par + MXN, 0);
    fill(depth, depth + MXN, 0);
    fill(seg, seg + MXN, 0);
    fill(lazy, lazy + MXN, 0);
    fill(posVtx, posVtx + MXN, 0);
    fill(chainHead, chainHead + MXN, 0); 
    fill(chainId, chainId + MXN, 0);
    fill(vtx, vtx + MXN, 0);
    for(long long i = 1; i <= n; i++)
        adj[i].clear();
    for(long long i = 0; i < n - 1; i++) {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[1] = 1;
    buildTree(1);
    hld(1);
    fill(seg, seg + MXN, oo);
    fill(lazy, lazy + MXN, oo);
    update(1, 1, n, posVtx[1], posVtx[1], depth[1]);
    while (m--) {
        long long type, v;
        cin >> type >> v;
        if (type == 1) {
            long long val;
            cin >> val;
            solve(v, depth[v] + val, 0);
        } else {
            cout << min(depth[v], solve(v, depth[v] + val, 1) + depth[v]) << '\n';
        }
    }
    return 0;
}

long long main() {
    ios_base::sync_with_stdio(0);
    for(long long tests = 1; tests <= 130; tests++) {
        /*string temp = "";
        if (tests <= 9)
            temp = "0";
        string inFile = "ANTS" + temp + to_string(tests) + ".inp";
        string outFile = "test" + to_string(tests) + ".inp";
        ifstream fin (inFile);
        ofstream fout (outFile);*/

    }