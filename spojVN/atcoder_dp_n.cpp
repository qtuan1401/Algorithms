#include <bits/stdc++.h>

using namespace std;

vector < vector < long long > > sum, dp;
vector < int > a;

long long memo(int l, int r) {
    // cout << l << " * " << r << endl;
    if (l + 1 == r) 
        return dp[l][r] = sum[l][r] = a[l] + a[r];
    if (l == r) {
        sum[l][r] = a[l];
        return 0;
    }
    if (l > r) return 0;
    if (sum[l][r] != -1) return dp[l][r];

    long long res = 1e18;
    for (int i = l; i < r; i++) {
        long long dpL = memo(l, i);
        long long dpR = memo(i + 1, r);
        long long val = sum[l][i] + sum[i + 1][r] + dp[l][i] + dp[i + 1][r];
        if (res > val) {
            res = val;
            sum[l][r] = sum[l][i] + sum[i + 1][r];
        }
        // cout << l << " " << i << " " << r << " " << memo(l, i) << " " << memo(i + 1, r) << endl;
    }

    return dp[l][r] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    sum.resize(n, vector < long long > (n, - 1));
    dp.resize(n, vector < long long > (n));

    cout << memo(0, n - 1) << '\n';
    return 0;
}