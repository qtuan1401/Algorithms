#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

const long long MOD = 1e9 + 7;

vector < long long > fact;

long long calcPow(long long a, int n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (res * a) % MOD;
        }
        n /= 2;
        a = (a * a) % MOD;
    }

    return res;
}

long long inv(long long x) {
    return calcPow(x, MOD - 2);
}

long long cnk(long long n, long long k) {
    long long p2 = (fact[k] % MOD * fact[n - k] % MOD) % MOD;
    return fact[n] * inv(p2) % MOD;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, k;
        cin >> n >> k;

        vector < int > marked(n, 1);


        for (int i = 0; i < k; i++) {
            int c, r;
            cin >> c >> r;
            c--; r--;
            marked[c]--;
            marked[r]--;
        }

        int tot = n;
        for (int i = 0; i < n; i++) tot -= marked[i] <= 0;

        // cout << tot << endl;
        n = tot;
        resetVec<long long>(fact, n + 1, 0LL);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;

        long long mul = 1;
        for (int i = 1; i <= n - n % 2; i += 2) {
            mul = mul * i % MOD;
        }

        long long ans = 0;
        for (int i = n % 2, cnt = n - n % 2; i <= n; i += 2, cnt -= 2) {
            // cout << i << " "<< cnk(n, i) << " " << mul << " " << cnt << endl;
            long long res = cnk(n, i) * mul % MOD;
            if (cnt != 0) res = res * calcPow(2, cnt / 2) % MOD;
            mul = mul * inv(cnt - 1) % MOD;
            // cout << res << endl;
            ans += res;
            ans %= MOD;
        }

        cout << ans << '\n';
    }
    return 0;
}