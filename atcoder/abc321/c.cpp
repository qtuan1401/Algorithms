#include <bits/stdc++.h>

using namespace std;

long long ans = 0;
vector < vector < long long > > f, sum;

void memo(int i, int j) {
    if (f[i][j] != -1) return;
    if (i <= 0 || j <= 0) return;
    long long tot = sum[i - 1][9];
    for (int digit = i - 1; digit <= 9; digit++) {
        long long res = 0;
        for (int j = i - 2; j <= digit - 1; j++) {
            memo(i - 1, j);
            res += f[i - 1][j];
        }
        f[i][digit] = res;
        tot += res;
        sum[i][digit] = tot;
    }
}

int main() {
    freopen("../test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);

    f.resize(11, vector < long long > (10, -1));
    sum.resize(11, vector < long long > (10, 0));
    for (int i = 0; i <= 9; i++) {
        f[0][i] = 0;
        f[1][i] = 1;
        sum[1][i] = i;
    }

    for (int i = 2; i <= 10; i++) {
        f[i][0] = 0;
    }

    for (int i = 0; i <= 10; i++)
        for (int j = 0; j <= 9; j++) memo(i, j);
    long long k;
    while (cin >> k) {

        if (k < 10) {
            cout << k << '\n';
            return 0;
        }

        long long ans = 0;
        for (int i = 10; i >= 1; i--) {
            long long tot = sum[i - 1][9];

            if (i > 1 && tot + 1 == k) k = 0;
            if (k == 0) {
                ans = ans * 10 + i - 1;
                continue;
            }
            if (tot >= k) continue;
            int cur = i - 1;
            for (int j = i - 1; j <= 9; j++) {
                if (sum[i][j] >= k) {
                    cur = j;
                    break;
                }
            }
            k -= sum[i][cur - 1] + (i == 2);
            ans = ans * 10 + cur;
            if (i > 1) k += sum[i - 2][9];
        }
        cout << ans << '\n';
    }
    return 0;
}