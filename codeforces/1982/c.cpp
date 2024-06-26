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
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        long long l, r;
        cin >> n;
        cin >> l >> r;
        vector < int > a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long sum = 0;
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            sum += a[i];
            while (j < i && sum > r) {
                sum -= a[j];
                j++;
            }

            if (l <= sum && sum <= r) {
                ans++;
                sum = 0;
                j = i + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}