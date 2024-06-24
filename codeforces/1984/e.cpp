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

vector < vector < int > > adj;
vector < int > child;
int ans, root;

int getSize(int u, int p) {
    // if (u == 1 || u == 0) cout << adj[p].size() << " " << child[u] << endl;
    return (int)adj[p].size() + child[u] - (p != 0);
}

void dfs(int u, int p) {
    if (u != 0 && adj[u].size() == 1) {
        // cout << u + 1 << endl;
        ans++;
        return;
    }
    int sz = getSize(u, p);

    int flag = 0;
    for (auto & v : adj[u]) {
        if (v == p) continue;
        if (flag == 0 && sz == 1 && p != root) {
            ans++;
            child[v]++;
            flag = 1;
        }
        dfs(v, u);
    }
}

void calc(int u, int p) {
    if (u != 0 && adj[u].size() == 1 && adj[p].size() == 2 && ans == 0) {
        root = u;
        ans++;
        return;
    }
    for (auto & v : adj[u]) {
        if (v == p) continue;
        calc(v, u);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        // cout << n << endl;
        adj.clear();
        adj.resize(n);
        resetVec(child, n, 0);
        vector < int > uu(n), vv(n);
        ans = 0; root = 0;
        for (int i = 0; i < n - 1; i++) {
            cin >> uu[i] >> vv[i];
            uu[i]--;
            vv[i]--;
            adj[uu[i]].push_back(vv[i]);
            adj[vv[i]].push_back(uu[i]);
        }
        
        if (adj[0].size() > 1) calc(0, 0);
        else ans++;
        if (root != 0) {
            adj.clear();
            adj.resize(n);
            for (int i = 0; i < n - 1; i++) {
                if (uu[i] == root || vv[i] == root) continue;
                adj[uu[i]].push_back(vv[i]);
                adj[vv[i]].push_back(uu[i]);
                // cout << uu[i] + 1 << " " << vv[i] + 1 << endl;
            }
        }
        dfs(0, 0);
       
        cout << ans << '\n';
    }
    return 0;
}