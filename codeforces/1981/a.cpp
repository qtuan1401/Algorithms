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

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int l, r;
        cin >> l >> r;
        long long x = 1;
        long long ans = 0;
        while (x * 2 <= r) {
            x *= 2;
            ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}