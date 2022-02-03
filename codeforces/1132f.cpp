#include <bits/stdc++.h>

using namespace std;

const int MAXN = 505;

int memo[MAXN][MAXN];
string s;

int f(int l, int r) {
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (memo[l][r] != -1)
        return memo[l][r];
    int res = 1e9;
    res = min(res, f(l + 1, r) + 1);
    for(int i = l + 1; i <= r; i++) 
        if (s[l] == s[i])
            res = min(res, f(l + 1, i - 1) + f(i, r));
    return memo[l][r] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    //freopen("test.in", "r", stdin);
    int n;
    cin >> n;
    cin >> s;
    memset(memo, -1, sizeof memo);
    cout << f(0, n - 1);
    return 0;
}