#include <bits/stdc++.h>

using namespace std;

const int MXN = 505;

int n, m;
int x[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    double res = 0.0;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        res = max(res, 1.0 * (x[u] + x[v]) / w);
    }
    cout << fixed << setprecision(10);
    cout << res;
    return 0;
}