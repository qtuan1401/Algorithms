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
        int n, m;
        cin >> n >> m;
        long long cnt = 0;
        for (long long i = 1; i <= m; i++) {
            for (long long j = i; j <= n; j += i) {
                long long a = (j - 1) * i;
                if (a > 0 && a <= n) cnt++;
            }
        }
        cout << cnt + 1 << '\n';
    }
    return 0;
}