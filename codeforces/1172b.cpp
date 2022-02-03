#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int MOD = 998244353;

int n;
long long fac[MAXN], deg[MAXN];
long long res = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
    //    cout << u << " " << v << endl;
        deg[u]++; deg[v]++;
    }

    fac[1] = 1;
    for(int i = 2; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
    //dfs(1, 0);
    for(int i = 1; i <= n; i++)
        res = (res * fac[deg[i]]) % MOD;
    //cout << res << endl;
    cout << (res * n) % MOD;
    return 0;
}
