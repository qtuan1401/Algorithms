#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10;

int f[MAXN][MAXN], a[MAXN];
int n;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    n = unique(a + 1, a + 1 + n) - a - 1;

    for(int i = 1; i <= n; i++)
        for(int j = i - 1; j >= 1; j--) {
            f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
            if (a[i] == a[j])
                f[i][j] = min(f[i][j], f[i + 1][j - 1] + 1);
        }
    cout << f[n][1];
    return 0;
}