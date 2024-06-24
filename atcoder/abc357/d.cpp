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

const long long MOD = 998244353;

long long calcPow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = (res * a) % MOD;
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
        long long n;
        cin >> n;
        int cnt = 0;
        long long m = n;
        while (m > 0) {
            cnt++;
            m /= 10;
        }
        // cout << cnt << " " << n << " " <<cnt * (n - 1) << " " << calcPow(10, 4) << " " << calcPow(10, 1ll * cnt * (n - 1))<< endl;

        long long mul = calcPow(10, cnt);
        long long q = calcPow(mul, n - 1);
        // cout << mul << " " << mul * (calcPow(10, 1ll * cnt * (n - 1)) + MOD - 1) % MOD << endl;
        long long ans = mul * (q + MOD - 1) % MOD;
        ans = ans * calcPow((mul - 1 + MOD) % MOD, MOD - 2) % MOD;
        ans = (n % MOD * ans % MOD + n % MOD) % MOD;
        cout << ans << '\n';
    }
    return 0;
}