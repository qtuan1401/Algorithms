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

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector < vector < int > > tests(m);
        vector < int > res(m);
        for (int i = 0; i < m; i++) {
            int len;
            cin >> len;
            tests[i].resize(len);
            for (int j = 0; j < len; j++) {
                cin >> tests[i][j];
                tests[i][j]--;
            }
            char c;
            cin >> c;
            if (c == 'o') res[i] = 1;
            else res[i] = 0;
        }

        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            int valid = 0;
            for (int i = 0; i < m; i++) {
                int cnt = 0;
                for (int j = 0; j < tests[i].size(); j++) {
                    cnt += getBit(mask, tests[i][j]);
                }
                if (cnt >= k && res[i] == 1) valid++;
                if (cnt < k && res[i] == 0) valid++;
            }

            if (valid == m) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}