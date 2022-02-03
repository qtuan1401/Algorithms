#include <bits/stdc++.h>
 
using namespace std;
 
struct node {
    int x, y, w, id;
    bool check;
    node(int a = 0, int b = 0, int c = 0, bool d = false, int _id = 0) {
        x = a;
        y = b;
        w = c;
        check = d;
        id = _id;
    }
};
 
const int MXN = 2e5 + 10;
 
typedef pair<int, int> ii;
 
vector< ii > adj[MXN];
node graph[MXN];
int edge[MXN][20], m[MXN][20], lab[MXN], depth[MXN], par[MXN];
long long ans[MXN];
int n, len;
long long sum;
 
bool cmp(const node & a, const node & b) {
    return a.w < b.w;
}
 
int root(int i) {
    while (lab[i] > 0)
        i = lab[i];
    return i;
}
 
void Union(int i, int j) {
    int temp = lab[i] + lab[j];
    if (lab[i] < lab[j]) {
        lab[j] = i;
        lab[i] = temp;
    } else {
        lab[i] = j;
        lab[j] = temp;
    }
}
 
void kruksal() {
    for(int i=1;i<=len;i++) {
        int u = graph[i].x;
        int v = graph[i].y;
        int uu = root(u);
        int vv = root(v);
        if (uu != vv) {
            Union(uu, vv);
            adj[u].push_back(ii(v, graph[i].w));
            adj[v].push_back(ii(u, graph[i].w));
            graph[i].check = 1;
            sum += graph[i].w;
        }
    }
}
 
void dfs(int u) {
    for(int i=0;i<adj[u].size();i++) {
        int v = adj[u][i].first;
        if (par[u] != v) {
            par[v] = u;
            depth[v] = depth[u] + 1;
            edge[v][0] = adj[u][i].second;
            dfs(v);
        }
    }
}
 
void prepare() {
    for(int i=1;i<=n;i++)
        m[i][0] = par[i];
    for(int k=1;k<=17;k++)
        for(int i=1;i<=n;i++) {
            m[i][k] = m[m[i][k - 1]][k - 1];
            edge[i][k] = max(edge[i][k - 1], edge[m[i][k - 1]][k - 1]);
        }
}
 
int lca(int u, int v) {
    if (depth[v] > depth[u])
        return lca(v, u);
    int res = -1;
    for(int i=17;i>=0;i--)
        if (depth[m[u][i]] >= depth[v]) {
            res = max(res, edge[u][i]);
            u = m[u][i];
        }
    if (u == v) 
        return res;
    for(int i=17;i>=0;i--)
        if (m[u][i] != m[v][i]) {
            res = max(res, max(edge[u][i], edge[v][i]));
            u = m[u][i];
            v = m[v][i];
        }
    res = max(res, max(edge[u][0], edge[v][0]));
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> len;
    //cout << n << len << endl;
    for(int i=1;i<=len;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[i] = node(u, v, w, 0, i);
    }
    sort(graph + 1, graph + 1 + len, cmp);
    for(int i=1;i<=n;i++) 
        lab[i] = depth[i] = -1;
    kruksal();
    //for(int i=1;i<=len;i++)
    //  if (graph[i].check)
    //      cout << graph[i].x << " " << graph[i].y << endl;
    for(int i=1;i<=n;i++)
        if (depth[i] < 0) {
            depth[i] = 0;
            dfs(i);
        }
    prepare();
    for(int i=1;i<=len;i++) 
        if (!graph[i].check) {
            long long mx = lca(graph[i].x, graph[i].y);
            //cout << Max << endl;
            ans[graph[i].id] = sum - mx + graph[i].w;
        } else ans[graph[i].id] = sum;
    for(int i=1;i<=len;i++)
        cout << ans[i] << '\n';
    return 0;
}