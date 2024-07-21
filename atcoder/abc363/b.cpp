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
        int n, t, p;
        cin >> n >> t >> p;
        vector < int > a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x >= t) {
                p--;
                continue;
            }
            a.push_back(t - x);
        }
        sort(a.begin(), a.end());
        int ans = 0;
        if (p > 0) ans = a[p - 1];
        cout << ans << '\n';
    }
    return 0;
}