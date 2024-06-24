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
        long long n, a, b;
        cin >> n >> a >> b;
        long long k = min(min(n, b), max(0LL, b - a));
        long long ans = b * k - k * (k - 1) / 2 + (n - k) * a;
        cout << ans << '\n';
    }
    return 0;
}
