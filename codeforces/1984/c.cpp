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

const long long INF = 1e15;
const long long MOD = 998244353;

long long calc(long long a, long long b, int type) {
    if (type == 0) return a + b;
    return abs(a + b);
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector < int > a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector < long long > mx(n + 1, -INF), mn(n + 1, INF);
        vector < long long > cntMx(n + 1, 0), cntMn(n + 1, 0);
        mx[0] = mn[0] = 0;
        cntMx[0] = cntMn[0] = 1;
        for (int i = 1; i <= n; i++) {
            long long v1 = calc(mx[i - 1], a[i], 0);
            long long v2 = calc(mx[i - 1], a[i], 1);
            long long v3 = calc(mn[i - 1], a[i], 0);
            long long v4 = calc(mn[i - 1], a[i], 1);
            mx[i] = max(max(v1, v2), max(v3, v4));
            mn[i] = min(min(v1, v2), min(v3, v4));

            // max
            if (mx[i] == v1) cntMx[i] += cntMx[i - 1];
            cntMx[i] %= MOD;
            if (mx[i] == v2) cntMx[i] += cntMx[i - 1];
            cntMx[i] %= MOD;
            if (mx[i - 1] != mn[i - 1]) {
                if (mx[i] == v3) cntMx[i] += cntMn[i - 1];
                cntMx[i] %= MOD;
                if (mx[i] == v4) cntMx[i] += cntMn[i - 1];
                cntMx[i] %= MOD;
            }

            // min
            if (mn[i] == v3) cntMn[i] += cntMn[i - 1];
            cntMn[i] %= MOD;
            if (mn[i] == v4) cntMn[i] += cntMn[i - 1];
            cntMn[i] %= MOD;
            if (mx[i - 1] != mn[i - 1]) {
                if (mn[i] == v1) cntMn[i] += cntMx[i - 1];
                cntMn[i] %= MOD;
                if (mn[i] == v2) cntMn[i] += cntMx[i - 1];
                cntMn[i] %= MOD;
            }
        }
        cout << cntMx[n] << '\n';
    }
    return 0;
}