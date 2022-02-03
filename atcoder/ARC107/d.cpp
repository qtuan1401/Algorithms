#include <bits/stdc++.h>

using namespace std;

const int MXN = 3e3 + 10;
const int MOD = 998244353;

int n, k;
int f[MXN * 2][MXN * 2];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i <= k; i++)
        f[0][i] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = k; j >= 1; j--)
            f[i][j] = (f[i - 1][j - 1] + f[i][j * 2]) % MOD;
    /*for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++)
            cout << f[i][j] << " ";
        cout << endl;
    }*/
    cout << f[n][k];
    return 0;
}