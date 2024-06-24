#include <bits/stdc++.h>

using namespace std;

const long long INF = 5e18;

long long getGcd(long long a, long long b) {
    return b == 0 ? a : getGcd(b, a % b);
}

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int flipBit(int x, int i) {
    return x ^ (1 << i);
}

long long getLcm(vector < long long > & a, int bit) {
    long long res = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (!getBit(bit, i)) continue;
        if (res == 0) res = a[i];
        else res = (res * a[i]) / getGcd(a[i], res);
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
        vector < long long > p(3), a(n);
        for (int i = 0; i < 3; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector < long long > lcm(8, 0);
        for (int i = 1; i < 8; i++) {
            lcm[i] = getLcm(p, i);
        }

        vector < vector < long long > > f(n + 1, vector < long long > (8, INF));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i][0] = 0;
            for (int mask = 1; mask < 8; mask++) {
                f[i][mask] = min(f[i][mask], f[i - 1][mask]);
                for (int pre = 0; pre < 8; pre++) {
                    bool ok = true;
                    for (int j = 0; j < 3; j++) {
                        if (getBit(pre, j) && !getBit(mask, j)) {
                            ok = false;
                            break;
                        }
                    }
                
                    int cur = mask ^ pre;
                    if (!ok || cur == 0 || f[i - 1][pre] == INF) continue;
                    long long w = 0;
                    if (lcm[cur] > a[i - 1]) w = lcm[cur] - a[i - 1];
                    else {
                        long long remainder = a[i - 1] % lcm[cur];
                        if (remainder == 0) remainder = lcm[cur];
                        w = lcm[cur] - remainder;
                    }
                    f[i][mask] = min(f[i][mask], f[i - 1][pre] + w);
                }
            }   
        }

        long long mn = INF;
        for (int i = 1; i <= n; i++) {
            mn = min(mn, f[i][7]);
        }

        cout << mn << '\n';
    }
    return 0;
}