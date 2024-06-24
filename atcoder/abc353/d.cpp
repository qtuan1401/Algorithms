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

long long calcPow(long long a, int n) {
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
        int n;
        cin >> n;
        vector < long long > a(n), cnt(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            long long x = a[i];
            while (x > 0) {
                cnt[i]++;
                x /= 10;
            }
        }

        vector < long long > sum(n, 0), digit(n, 0);
        digit[n - 1] = calcPow(10, cnt[n - 1]);
        sum[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            digit[i] = calcPow(10, cnt[i]) + digit[i + 1];
            digit[i] %= MOD;
            sum[i] = a[i] + sum[i + 1];
            sum[i] %= MOD;
        }

        long long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            // cout << a[i] << " " << digit[i + 1] << " " << cnt[i + 1] << endl;
            long long res = (a[i] * digit[i + 1]) % MOD;
            res += sum[i + 1];
            res %= MOD;
            ans += res;
            ans %= MOD;
        }

        cout << ans << '\n';
    }
    return 0;
}