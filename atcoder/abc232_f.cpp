#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int offBit(int x, int i) {
    return x ^ (1 << i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long x, y;
    int n;
    cin >> n >> x >> y;
    vector < int > a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector < long long > f(1 << n, INF);
    f[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int pos = __builtin_popcount(mask);
        for (int j = 0; j < n; j++) {
            if (getBit(mask, j)) {
                int pre = offBit(mask, j);
                int cnt = 0;
                for (int k = 0; k < n; k++)
                    cnt += (getBit(pre, k) && k > j);
                f[mask] = min(f[mask], f[pre] + y * (j + cnt - pos + 1) + x * abs(b[pos - 1] - a[j]));
            }
        }
    }
    cout << f[(1 << n) - 1] << '\n';
    return 0;
}