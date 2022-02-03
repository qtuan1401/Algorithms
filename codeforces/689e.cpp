#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair < int, int > II;
 
const int MOD = 1e9 + 7;
const int LIM = 1e6 + 10;
int n, k;
II c[LIM];
int sum[LIM], a[LIM], b[LIM];
long long fact[LIM], revFact[LIM];
 
long long calcPow(long long x, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}
 
long long calc(long long x, long long y) {
    // cout << x << " " << y << endl;
    return (fact[x] * calcPow((fact[y] * fact[x - y]) % MOD, MOD - 2) % MOD) % MOD;
}
 
int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < 3 * n; i += 3) {
        cin >> c[i].first >> c[i + 1].first;
        c[i + 2].first = c[i + 1].first + 1;
        c[i].second = i;
        c[i + 1].second = i + 1;
        c[i + 2].second = i + 2;
    }
    sort(c, c + 3 * n);
    int cnt = 1;
    a[c[0].second] = cnt;
    b[1] = c[0].first;
    for (int i = 1; i < 3 * n; i++) {
        a[c[i].second] = cnt += c[i].first != c[i - 1].first;
        b[cnt] = c[i].first;
    }
    for (int i = 0; i < 3 * n; i += 3) {
        sum[a[i]]++;
        sum[a[i + 2]]--;
        // cout << a[i] << " " << a[i + 1] << endl;
    }
    // cout << cnt << endl;
    fact[0] = 1;
    for (int i = 1; i <= 1e6; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    // for (int i = 0; i <= cnt; i++)
    //     cout << fact[i] << " ";
    // cout << endl;
    // cout << calc(3, 2) << endl;
    for (int i = 1; i <= cnt; i++)
        sum[i] += sum[i - 1];
    // for (int i = 1; i <= cnt; i++)
    //     cout << sum[i] << " ";
    // cout << endl;
    long long res = 0;
    b[cnt + 1] = b[cnt] + 1;
    for (int i = 1; i <= cnt; i++) {
        // cout << sum[i] << " " << k << endl;
        if (sum[i] < k)
            continue;
        // cout << b[i] << " " <<  b[i + 1] << endl;
        int temp = 1;
        if (sum[i + 1] >= k)
            temp = b[i + 1] - b[i];
        // cout << b[i + 1] << " " << b[i] << " " << temp << endl;
        res += 1ll * temp * calc(sum[i], k);
        // cout << b[i] << " " << b[i - 1] << " " << calc(sum[i], k) << endl;
        res %= MOD;
    }
    cout << res;
    return 0;
}