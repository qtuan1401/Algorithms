#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

bool getBit(long long x, int i) {
    return (x >> i) & 1;
}

long long calcPow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    vector < long long > pp2(61);
    pp2[0] = 1;
    for (int i = 1; i <= 60; i++)
        pp2[i] = pp2[i - 1] * 2;
    while (T--) {
        int m;
        long long n;
        cin >> n >> m;
        if (n == 1) {
            cout << m << '\n';
            continue;
        }
        if (m == 1) {
            cout << 0 << '\n';
            continue;
        }
        long long sum = 0;
        for (int i = 1; i < m; i++)
            sum = (sum + i * i) % MOD;
        long long res = 0;
        for (int i = 1; i <= 59; i++) {
            if (pp2[i + 1] != n + 1) continue;
            if (i == 1) {
                res = calcPow(sum, pp2[i - 1]);
                break;
            }
            // cout << i << endl;
            for (int j = 0; j + 1 < m; j++) {
                // cout << sum << " " << i << endl;;
                sum = (sum - j * j + MOD) % MOD;
                res = (res + calcPow(sum, pp2[i - 1])) % MOD; 
            }
            break;
        }
        cout << res << '\n';
    }
    return 0;
}