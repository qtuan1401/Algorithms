#include <bits/stdc++.h>

using namespace std;

int dd[10][10], a[10], c[10][10];
int n, m, ans, res;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        dd[u][v] = dd[v][u] = 1;
    }
    if (n <= 6)
        cout << m;
    else {
        for(int i = 1; i <= n; i++) 
            a[i] = i;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++) {
                res = m;
                for(int k = 1; k <= n; k++)
                    res -= (dd[i][k] && dd[j][k]);
                ans = max(ans, res);
            }
        cout << ans;
    }
    return 0;
}