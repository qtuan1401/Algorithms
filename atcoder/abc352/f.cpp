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
typedef pair < int, pii > piii;

vector < vector < pii > > adj;
vector < int > sum;
vector < vector < int > > isValid, vet, memo;
vector < int > marked;

int n, roots;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int flipBit(int x, int i) {
    return x ^ (1 << i);
}

void dfs(int u, int tot, int col) {
    marked[u] = col;
    vet[col].push_back(u);
    for (auto & p : adj[u]) {
        int v = p.first, w = p.second;
        if (marked[v] != -1) continue;
        sum[v] = tot - w;
        dfs(v, tot - w, col);
    }
}

bool isDuplicated(int mask1, int mask2) {
    for (int i = 0; i < n; i++) {
        if (getBit(mask1, i) == 1 && getBit(mask2, i) == 1) return true;
    }

    return false;
}

bool check(int mask, int i, int val) {
    int nxtMask = 0;
    for (auto & e : vet[i]) {
        if (val + sum[e] < 0 || val + sum[e] >= n) return false;
        nxtMask = flipBit(nxtMask, val + sum[e]);
    }
    return !isDuplicated(mask, nxtMask);
}

bool calc(int u, int p) {
    if (p >= roots) {
        return true;
    }
    if (memo[u][p] != -1) return memo[u][p];
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (getBit(u, i) == 0) {
            if (check(u, p, i)) {
                int val = i;
                int mask = u;
                for (auto & e : vet[p]) {
                    mask = flipBit(mask, val + sum[e]);
                }
                if (calc(mask, p + 1)) {
                    ok = true;
                    isValid[p][i] = true;
                }
            }
        }
    }
    return memo[u][p] = ok;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int m;
        cin >> n >> m;
        sum.resize(n);
        vet.resize(n);
        for (int i = 0; i < n; i++) sum[i] = 0;
        adj.resize(n); 
        resetVec(isValid, n, vector < int > (n, 0));
        resetVec(memo, 1 << n, vector < int > (n, -1));
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u].push_back(pii(v, w));
            adj[v].push_back(pii(u, -w));
        }
        int cnt = 0;
        roots = 0;
        marked.resize(n);
        for (int i = 0; i < n; i++) marked[i] = -1;
        for (int i = 0; i < n; i++) {
            if (marked[i] != -1) continue;
            dfs(i, 0, roots);
            roots++;
        }
        calc(0, 0);
        vector < int > ans(n, 0);
        for (int i = 0; i < roots; i++) {
            int cnt = 0, val = 0;
            for (int j = 0; j< n; j++) {
                if (isValid[i][j]) {
                    cnt++;
                    val = j;
                }
            }
            if (cnt > 1) {
                for (auto & e : vet[i]) {
                    ans[e] = -1;
                }
            } else {
                for (auto & e : vet[i]) {
                    ans[e] = sum[e] + val + 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << '\n';
    }
    return 0;
}