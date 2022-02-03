#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

long long a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> a >> b >> c;
    long long res = a * (a + 1) / 2;
    res %= MOD;
    res *= (b * (b + 1) / 2) % MOD;
    res %= MOD;
    res *= (c * (c + 1) / 2) % MOD;
    res %= MOD;
    cout << res;
    return 0;
}