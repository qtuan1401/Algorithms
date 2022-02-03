#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < double > p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    double f[2][n + 1][n + 1];
    for (int k = 0; k < 2; k++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                f[k][i][j] = 0;
    
    f[0][0][1] = 1 - p[0];
    f[0][1][0] = p[0];

    for (int i = 1; i < n; i++) {
        int id = (i & 1);
        for (int j = 0; j <= n; j++) {
            int k = i + 1 - j;
            if (j > 0)
                f[id][j][k] += f[1 - id][j - 1][k] * p[i];
            if (k > 0)
                f[id][j][k] += f[1 - id][j][k - 1] * (1 - p[i]);
        }
    } 

    int id = (n - 1) & 1;
    double res = 0;
    for (int i = (n + 1) / 2; i <= n; i++)
        res += f[id][i][n - i];
    cout << fixed << setprecision(10);
    cout << res;
    return 0;
}