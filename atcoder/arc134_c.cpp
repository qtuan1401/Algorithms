#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int inv;

int calcPow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1)
            res = (1ll * res * a) % MOD;
        a = (1ll * a * a) % MOD;
        n >>= 1;
    }
    return res;
}

int nck(int n, int k) {
    int fact = 1;
    for (int i = n; i > n - k; i--) 
        fact = (1ll * fact * i) % MOD;
    return (1ll * fact * calcPow(inv, MOD - 2)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    inv = 1;
    for (int i = 1; i < k; i++) 
        inv = (1ll * inv * i) % MOD;
    vector < int > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[0] -= k;
    long long sum = 0;
    for (int i = 1; i < n; i++)
        sum += a[i];
    if (sum > a[0]) {
        cout << "0\n";
        return 0;
    }

    a[0] -= sum;
    int res = nck(a[0] + k - 1, k - 1);
    for (int i = 1; i < n; i++)
        res = (1ll * res * nck(a[i] + k - 1, k - 1)) % MOD;

    cout << res << '\n';
    return 0;
}