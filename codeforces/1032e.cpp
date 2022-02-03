#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int cnt[MAXN];
bool f[MAXN * MAXN][MAXN][2];
int n, res, tot;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tot += x;
        cnt[x]++;
    }
    for(int i = 1; i <= 100; i++) {
        for(int sum = 10000; sum >= 1; sum--)
            for(int j = 1; j <= cnt[i]; j++)
                for(int k = j + 1; k <= 100; k++)
                    if (sum >= i * j) {
                        if (f[sum - i * j][k - j][0] == 1 || f[sum - i * j][k - j][1] == 1)
                            f[sum][k][1] = 1;
                    }
        for(int j = 1; j <= cnt[i]; j++)
            f[i * j][j][0] = 1;
    }
    //cout << f[150][3][1] << endl;
    //cout << f[97][2][0] << " " << f[97][2][1] << endl;
    //cout << f[200][1] << " " << f[120][1] << " " << f[120 - 96][0] << endl;
    for(int i = 1; i <= 100; i++)
        for(int j = 1; j <= cnt[i]; j++) {
            int sum = i * j;
            if (f[sum][j][1] == 0) {
                int ans = j;
                if (j == n) {
                    res = n;
                    break;
                }
                //cout << sum << " " << tot << " " << i << endl;
                if (n - j == cnt[(tot - sum) / (n - j)] && (tot - sum) % (n - j) == 0) {
                    res = n;
                    break;
                }
                //if (ans == n)
                //    cout << i << " " << sum << " " << (tot - sum) / (n - sum / i) << " " << endl;
                res = max(res, j);
            }
        }
    cout << res;
    return 0;
}