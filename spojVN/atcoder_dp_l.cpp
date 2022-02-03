#include <bits/stdc++.h>

using namespace std;

vector < vector < long long > > dp;
int n;
vector < int > a;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    dp.resize(n, vector < long long > (n));

    for (int i = 0; i < n; i++)
        dp[i][i] = a[i];
    
    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);

    cout << dp[0][n - 1];
    return 0;
}