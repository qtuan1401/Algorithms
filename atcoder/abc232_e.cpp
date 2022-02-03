#include <bits/stdc++.h>

using namespace std;

#define y1 this_is_y1

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    int h, w, k;
    cin >> h >> w >> k;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector < vector < long long > > row(k + 1, vector < long long > (2, 0));
    row[0][0] = 1; row[0][1] = 0;
    row[1][0] = 0; row[1][1] = 1;
    for (int i = 1; i <= k; i++) {
        row[i][0] = row[i - 1][1] * (h - 1) % MOD;
        row[i][1] = (row[i - 1][1] * (h - 2) + row[i - 1][0]) % MOD;
    }

    vector < vector < long long > > col(k + 1, vector < long long > (2, 0));
    col[0][0] = 1; col[0][1] = 0;
    col[1][0] = 0; col[1][1] = 1;
    for (int i = 1; i < k; i++) {
        col[i][0] = col[i - 1][1] * (w - 1) % MOD;
        col[i][1] = (col[i - 1][1] * (w - 2) + col[i - 1][0]) % MOD;
    }

    long long res = 0;
    for (int i = 0; i <= k; i++) {
        res += ((row[i][x1 != x2] + 1) * col[k - i][y1 != y2]);
        res %= MOD;
    }

    cout << res;
    return 0;
}