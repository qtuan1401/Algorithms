#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum < k) {
        cout << 0 << '\n';
        return 0;
    }

    vector < vector < int > > dp(n, vector < int > (k + 2));

    for (int j = 0; j <= a[0]; j++)
        dp[0][j] = 1;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= k; j++) {
            int l = j;
            int r = min(k + 1, j + a[i + 1] + 1);
            dp[i + 1][l] = (dp[i + 1][l] + dp[i][j]) % MOD;
            dp[i + 1][r] = (1ll * dp[i + 1][r] - dp[i][j] + MOD) % MOD;
        }
        for (int j = 1; j <= k; j++)
            dp[i + 1][j] = (dp[i + 1][j] + dp[i + 1][j - 1]) % MOD;
    }
    
    cout << dp[n - 1][k];
    return 0;
}