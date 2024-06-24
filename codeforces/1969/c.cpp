#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

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
        int n, k;
        cin >> n >> k;
        vector < long long > a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector < vector < long long > > minVal(n + 1, vector < long long > (11, INF));
        for (int i = 1; i <= n; i++) {
            minVal[i][0] = a[i];
            for (int j = 1; j <= k; j++) {
                if (i + j > n) break;
                minVal[i][j] = min(minVal[i][j - 1], a[i + j]);
            }
        }

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 0; j <= k; j++) cout << minVal[i][j] << " ";
        //     cout << endl;
        // }

        vector < vector < long long > > f(n + 1, vector < long long > (11, INF));
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j1 = 0; j1 <= k; j1++) {
                f[i][j1] = min(f[i][j1], f[i - 1][j1] + a[i]);
                for (int j2 = j1 + 1; j2 <= k; j2++) {
                    int len = j2 - j1;
                    // cout << i << " " << j1 << " " << j2 << " " << len << " " << minVal[i - len][len] << endl;
                    if (i - len - 1 < 0 || minVal[i - len][len] == INF) continue;
                    // cout << len << " " << minVal[i - len + 1][len] << " " << f[i - len][j1] << " " << minVal[i - len + 1][len] * (len + 1) << endl;
                    // cout << f[i - len][j1] + 1ll * minVal[i - len + 1][len] * (len + 1) << endl;
                    f[i][j2] = min(f[i][j2], f[i - len - 1][j1] + 1ll * minVal[i - len][len] * (len + 1));  
                }
            }
        }

        long long ans = INF;
       
        for (int j = 0; j <= k; j++) {
            ans = min(ans, f[n][j]);
        }

        cout << ans << '\n';
    }
    return 0;
}