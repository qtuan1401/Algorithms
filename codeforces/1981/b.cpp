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

long long getBit(long long x, int i) {
    return (x >> i) & 1LL;
}

long long onBit(long long x, int i) {
    return (1LL << i) | x;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        long long l = max(0, n - m);
        long long r = n + m;

        long long ans = n;
        int on = 0;
        // cout << l << " " << r << " " << ans << endl;
        for (int i = 32; i >= 0; i--) {
            // cout << ans << endl;
            if (on) {
                ans = onBit(ans, i);
                continue;
            }
            if (getBit(r, i)) ans = onBit(ans, i);
            if (getBit(r, i) == 1 && getBit(l, i) == 0) on = 1;
            // cout << i << " " << ans << endl;
        }

        cout << ans << '\n';
    }
    return 0;
}