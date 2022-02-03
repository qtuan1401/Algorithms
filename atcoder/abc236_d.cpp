#include <bits/stdc++.h>

using namespace std;

int getBit(int x, int i) {
    return (x >> i) & 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < vector < int > > a(2 * n, vector < int > (2 * n));
    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++)
            cin >> a[i][j];
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << 2 * n); mask++) {
        if (__builtin_popcount(mask) != n) continue;
        int sum = 0;
        bool ok = true;
        vector < vector < int > > num(2);
        for (int i = 2 * n - 1; i >= 0; i--) {
            if (getBit(mask, i)) {
                sum += 1;
                num[1].push_back(i);
            } else {
                sum -= 1;
                num[0].push_back(i);
            }
            if (sum < 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            vector < int > id(n);
            for (int i = 0; i < n; i++)
                id[i] = i;
            do {
                bool ok = true;
                int res = 0;
                for (int i = 0; i < n; i++) {
                    if (num[1][id[i]] < num[0][i]) {
                        ok = false;
                        break;
                    }
                    res ^= a[num[0][i]][num[1][id[i]]];
                }
                if (ok) ans = max(ans, res);
            } while (next_permutation(id.begin(), id.end()));
        }
    }
    cout << ans << '\n';
    return 0;
}