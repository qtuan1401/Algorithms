#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e6 + 10;

int f[MXN], sum[10][MXN];
int n;

int calc(int x) {
    if (x < 10)
        return x;
    if (f[x] > 0)
        return f[x];
    int res = 1, n = x;
    while (x > 0) {
        if (x % 10 > 0)
            res *= (x % 10);
        x /= 10;
    }
    return f[n] = calc(res);
}

int main() {
    ios_base::sync_with_stdio(0);
    for(int i = 1; i <= 1000000; i++)
        f[i] = calc(i);
    for(int i = 1; i <= 9; i++) 
        for(int j = 1; j <= 1000000; j++)
            sum[i][j] = sum[i][j - 1] + (f[j] == i);
    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << sum[k][r] - sum[k][l - 1] << '\n';
    }
    return 0;
}