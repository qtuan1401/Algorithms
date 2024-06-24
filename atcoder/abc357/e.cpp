#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

vector < int > num, low, marked;
vector < long long> vtx;
stack < int > stk;
int id, scc;
vector < vector < int > > adj;

void tarjan(int u) {
    num[u] = low[u] = ++id;
    stk.push(u);
    for (auto & v : adj[u]) {
        if (marked[v] != -1) continue;
        if (!num[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        int v;
        do {
            v = stk.top();
            stk.pop();
            marked[v] = scc;
            vtx[scc]++;
        }
        while (v != u);
        scc++;
    }
}

long long ans;
vector < int > topo;

void dfs(int u) {
    marked[u] = 1;
    for (auto & v : adj[u]) {
        if (!marked[v]) dfs(v);
    }
    topo.push_back(u);
    marked[u] = 2;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n;
        adj.resize(n);
        resetVec(num, n, 0);
        resetVec(low, n, 0);
        resetVec(marked, n, -1);
        resetVec(vtx, n, 0LL);
        id = 0; scc = 0;
        vector < int > v(n);
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            v[i]--;
            adj[i].push_back(v[i]);
        }

        for (int i = 0; i < n; i++) {
            if (!num[i]) tarjan(i);
        }

        adj.clear();
        adj.resize(scc);
        // cout << ans << endl;
        for (int i = 0; i < scc; i++) {
            ans += vtx[i] * vtx[i];
            // cout << vtx[i] << " ";
        }
        // cout << ans << endl;
        for (int i = 0; i < n; i++) {
            int x = marked[i];
            int y = marked[v[i]];
            // cout << x << " " << y << endl;
            if (x == y) continue;
            adj[x].push_back(y);
            // cout << x << " " << y << " " << i << " " << v[i] << endl;
        }

        resetVec(marked, scc, 0);
        for (int i = 0; i < scc; i++)  {
            if (marked[i]) continue;
            dfs(i);
        }
        reverse(topo.begin(), topo.end());

        vector < long long > sum(scc, 0);
        for (int i = 0; i < scc; i++) {
            int u = topo[i];
            ans += sum[u] * vtx[u];
            sum[u] += vtx[u];
            for (auto & v : adj[u]) {
                // cout << i << " * " << v << " " << sum[u] << endl;
                sum[v] += sum[u];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}