#include <bits/stdc++.h>

#define vall(a) (a.begin(), a.end())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const long double INF = -1e18;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n;
        cin >> n;
        vector < long double > pp(n), sum(n);

        vector < int > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        reverse(a.begin(), a.end());
        pp[0] = sum[0] = 1;
        for (int i = 1; i < n; i++) {
            pp[i] = 0.9 * pp[i - 1];
            sum[i] = sum[i - 1] + pp[i];
        }

        vector < vector < ld > > f(n + 1, vector < ld > (n + 1, INF));

        for (int i = 0; i <= n; i++) {
            f[i][0] = f[i][0] = 0;
        }

        long double ans = INF;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                f[i][j] = f[i - 1][j];
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i - 1] * pp[j - 1]);
                ans = max(ans, f[i][j] / sum[j - 1] - 1200.0 / sqrt(j));
            } 
        }
        
        cout << fixed << setprecision(12);
        cout << ans << '\n';
    }
    return 0;
}