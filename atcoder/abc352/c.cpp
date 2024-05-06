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
        int n;
        cin >> n;
        vector < int > a(n), b(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            sum += a[i];
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long height = sum - a[i] + b[i];
            ans = max(ans, height);
        }

        cout << ans << '\n';
    }
    return 0;
}