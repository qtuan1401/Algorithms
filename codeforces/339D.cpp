#include <bits/stdc++.h>

using namespace std;

const int md = 1e5 + 10;
const int N = 20;

int n, m;
int a[N][(1 << N)];

int calc(int x, int y, int type) {
    if (type == 1)
        return x ^ y;
    return x | y;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= (1 << n); i++)
        cin >> a[n][i];
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= (1 << i); j += 2)
            a[i - 1][(j + 1) / 2] = calc(a[i][j], a[i][j + 1], ((i - 1) % 2 == n % 2));
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        a[n][u] = v;
        int nu = 0;
        for(int i = n; i >= 1; i--, u = nu) {
            nu = u / 2 + u % 2;
            int p = -1;
            if (u & 1)
                p = 1;
            a[i - 1][nu] = calc(a[i][u], a[i][u + p], (i - 1) % 2 == n % 2);
        }
        cout << a[0][1] << '\n';
    }
    return 0;
}