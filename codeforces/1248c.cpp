#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;
const int MOD = 1e9 + 7;

long long f[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    f[0] = 2;
    f[1] = 4;

    for (int i = 2; i < 100000; i++)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    
    cout << (f[n - 1] + f[m - 1] - 2 + MOD) % MOD;
    // cout << 
    return 0;
}