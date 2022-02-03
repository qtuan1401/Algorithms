#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10;

int a[MAXN], f[MAXN][MAXN];
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        f[i][0] = a[i];
    for(int k = 1; k < n; k++) {
        for(int i = 0; i < n - k; i++)
            f[i][k] = f[i][k - 1] ^ f[i + 1][k - 1];
    }

    for(int k = 1; k < n; k++)
        for(int i = 0; i < n; i++)
            f[i][k] = max(f[i][k], max(f[i][k - 1], f[i + 1][k - 1]));

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << f[l][r - l] << '\n';
    }
    return 0;
}