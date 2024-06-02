#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

long long getBit(long long x, int i) {
    return (x >> i) & 1;
}

vector < long long > pp;

long long calc(int len, long long m) {
    long long cnt = 0, ans = 0;
    if (len < 0) return 0;
    for (int i = 0; i <= len; i++) cnt += getBit(m, i);
    long long v1 = 0, v2 = 0;
    if (cnt > 0) v1 = pp[cnt - 1];
    if (len + 1 - cnt >= 0) v2 = pp[len + 1 - cnt];
   
    long long res = ((v1 * v2) % MOD * cnt) % MOD;
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    pp.resize(61, 0LL);
    pp[0] = 1;
    for (int i = 1; i <= 60; i++) pp[i] = (pp[i - 1] * 2) % MOD;
    while (tests--) {
        long long n, m;
        cin >> n >> m;

        long long cnt = 0;
        int lim = 0;
        for (int i = 0; i < 60; i++) {
            if (getBit(n, i)) lim = i;
        }

        long long ans = 0;
        for (int i = 0; i < 60; i++) {
            if (getBit(n, i) == 1 && getBit(m, i)) ans++;
        }
        long long c = 0;
        for (int i = lim; i >= 0; i--) {
            if (getBit(n, i)) {
                long long t = pp[i];
                ans += c * t % MOD;
                // cout << i << " " << c * t << endl;
                ans %= MOD; 
                ans += calc(i - 1, m);
                ans %= MOD;
                c += getBit(m, i);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}