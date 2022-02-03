#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e6 + 10;

int a[MXN];
int dp[2][MXN][20];
 
int cmp(int k, int i, int j) {
    if (k) {
        if (a[i] > a[j])
            return i;
        return j;
    }
    if (a[i] < a[j])
        return i;
    return j;
}
 
int query(int k, int l, int r) {
    int lvl = log2(r - l + 1);
    return cmp(k, dp[k][l][lvl], dp[k][r - (1 << lvl) + 1][lvl]);
}
 
long long solve(int k, int l, int r) {  
    if (l > r) 
        return 0;
    int mid = query(k, l, r);
    int nl = mid - l + 1;
    int nr = r - mid + 1;
    long long res = 1ll * nl * nr * a[mid];
    res += solve(k, l, mid - 1);
    res += solve(k, mid + 1, r);
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[0][i][0] = dp[1][i][0] = i;
    }

    for (int j = 1; (1 << j) <= n; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            for (int k = 0; k < 2; ++k)
                dp[k][i][j] = cmp(k, dp[k][i][j - 1], dp[k][i + (1 << (j - 1))][j - 1]);  

    cout << solve(1, 1, n) - solve(0, 1, n);
} 
