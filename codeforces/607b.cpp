#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int memo[MAXN][MAXN], a[MAXN];
int n;

int dp(int l, int r) {
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (l + 1 == r)
        return 1 + (a[l] != a[r]);
    if (memo[l][r] != -1)
        return memo[l][r];
    int res = 1e9;
    res = min(res, 1 + dp(l + 1, r));
    if (a[l] == a[l + 1])
        res = min(res, 1 + dp(l + 2, r));
    for(int i = l + 2; i <= r; i++)
        if (a[i] == a[l])
            res = min(res, dp(l + 1, i - 1) + dp(i + 1, r));
    return memo[l][r] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    memset(memo, -1, sizeof memo);
    cout << dp(0, n - 1);
    return 0;
}

