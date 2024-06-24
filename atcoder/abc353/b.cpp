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
        int remain = k;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (remain < x) {
                remain = k;
                ans++;
            }
            remain -= x;
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}