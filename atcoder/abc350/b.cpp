#include <bits/stdc++.h>

using namespace std;

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
        int n, q;
        cin >> n >> q;
        vector < int > a(n);
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            x--;
            a[x] = 1 - a[x];
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += a[i] == 0;
        cout << cnt;
    }
    return 0;
}