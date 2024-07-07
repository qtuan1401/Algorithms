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
    int tests = 1;
    while (tests--) {
        int n, k;
        cin >> n >> k;
        vector < int > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());

        int ans = a[n - 1 - k] - a[0];
        for (int i = 0; i < k; i++) {
            ans = min(ans, a[n - 1 - k + i + 1] - a[i + 1]);
        }

        cout << ans << '\n';
    }
    return 0;
}