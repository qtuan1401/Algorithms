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

int getBit(int x, int i) {
    return (x >> i) & 1;
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
        vector < int > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int mx = 1;
        for (int j = 0; j < 20; j++) {
            int pre = -1;
            for (int i = 0; i < n; i++) {
                if (getBit(a[i], j)) {
                    mx = max(mx, i - pre);
                    pre = i;
                }
            }
            if (pre > -1)
            mx = max(mx, n - 1 - pre + 1);
        }

        cout << mx << '\n';
    }
    return 0;
}