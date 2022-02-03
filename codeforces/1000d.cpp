#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;
const int MOD = 998244353;

long long f[MAXN], a[MAXN], c[MAXN][MAXN];
int n;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i <= 1000; i++)
        for(int j = 0; j <= i; j++)
            if (j == 0 || i == j)
                c[i][j] = 1;
            else 
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    f[n] = 1;
    for(int i = n - 1; i >= 0; i--) {
        if (a[i] > 0 && i + a[i] < n) {
            for(int j = i + a[i]; j < n; j++) {
                //cout << i << " " << j << " " << c[j - i][a[i]] << endl;
                f[i] = (f[i] + (c[j - i][a[i]] * (f[j + 1])) % MOD) % MOD;
            }
        }
    }
    long long res = 0;
    //cout << f[1] << endl;
    for(int i = 0; i < n; i++)
        res = (res + f[i]) % MOD;
    cout << res;
    return 0;
}