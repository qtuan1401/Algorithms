#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    vector < int > cnt(26, 0);
    for (int i = 0; i < s.size(); i++)
        cnt[s[i] - 'a']++;
    int n = s.size();
    vector < vector < int > > nck (n + 1, vector < int > (n + 1, 0));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0)
                nck[i][j] = 1;
            if (i > 0 && j == 0)
                nck[i][j] = nck[i - 1][j];
            if (i > 0 && j > 0)
                nck[i][j] = (nck[i - 1][j - 1] + nck[i - 1][j]) % MOD;
        }
        
    vector < int > f(n + 1);
    int sum = 0;
    f[0] = 1;
    for (int i = 0; i < 26; i++) {
        for (int j = sum + cnt[i]; j >= 1; j--)
            for (int k = 1; k <= cnt[i]; k++) {
                // cout << i << " " << j + k << " " << endl;
                f[j] += (1ll * f[j - k] * nck[j][k]) % MOD;
                f[j] %= MOD;
            }
        sum += cnt[i];
        // for (int j = 0; j <= 3; j++)
        //     cout << f[i][j] << " ";
        // cout << endl;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = (res + f[i]) % MOD;
    cout << res;
    return 0;
}