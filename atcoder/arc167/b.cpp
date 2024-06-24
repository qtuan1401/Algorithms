#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

long long calcMul(long long a, long long b, long long mod = MOD) {
    return (a % mod) * (b % mod) % mod;
}

long long calcPow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a;
            res %= MOD;
        }

        a = (a * a) % MOD;
        n /= 2;
    }

    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        long long a, b;
        cin >> a >> b;

        vector < int > cnt;

        long long ta = a;
        for (long long i = 2; i * i <= ta; i++) {
            if (ta % i != 0) continue;
            cnt.push_back(0);
            while (ta % i == 0) {
                ta /= i;
                cnt.back()++;
            }
        }

        if (ta > 1) {
            cnt.push_back(1);
        }

        long long tot = 1;
        long long lst = 1;
        for (auto & e : cnt) {
            lst *= (calcMul(b, e, 2) + 1) % 2;
            lst %= 2;
            tot *= (calcMul(b, e) + 1) % MOD;
            tot %= MOD;
        }
        tot = calcMul(tot, b);
        lst = calcMul(lst, b, 2);
        if (lst & 1) 
            tot = (tot - 1 + MOD) % MOD;

        cout << calcMul(tot, calcPow(2ll, MOD - 2)) << endl;
    } 
    return 0;
}