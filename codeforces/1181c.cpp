#include <bits/stdc++.h>

const int md = 1e3 + 10;
int n, m, row[md], f[md][md];
char s[md][md];

int solve() {
    int ans = 0;
    for(int j = 1; j <= m; j++){
        for(int i = 1;i <= n; i++)
            if (s[i][j] == s[i - 1][j])
                row[i] = row[i - 1] + 1;
            else row[i] = 1;

        for(int i = 0; i <= n; i++)
            for(int len = 1; i + len * 3 <= n; len++) {
                if(row[i + len] >= len && row[i + len * 2] == len && row[i + len * 3] == len) {
                    if (s[i + len][j] == s[i + len][j - 1] && s[i + len * 2][j] == s[i + len * 2][j - 1] && s[i + len * 3][j] == s[i + len * 3][j - 1])
                        f[i][i + len * 3]++;
                    else
                        f[i][i + len * 3] = 1;
                }
                else
                    f[i][i + len * 3] = 0;
                ans += f[i][i + len * 3];
            }
    }
    return ans;
}

int main() {
    //freopen("test.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    printf("%d", solve());
}