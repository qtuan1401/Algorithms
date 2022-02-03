#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10;

int f[MAXN][MAXN][5], a[MAXN], ans[MAXN];
int n;

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 0; i <= n + 1; i++)
        for(int k = 0; k <= (n + 1) / 2; k++)
            f[i][k][0] = f[i][k][1] = 1e9;
    for(int i = 0; i <= n + 1; i++)
        f[i][0][0] = 0;
    for(int k = 1; k <= (n + 1) / 2; k++) {
        ans[k] = 1e9;
        for(int i = 1; i <= n; i++) {
            f[i][k][0] = min(f[i - 1][k][0], f[i - 1][k][1]);
            //cout << f[2][0][0] << "*" << endl;
            ans[k] = min(ans[k], f[i][k][0]);
            if (i == 1) {
                f[2][k][1] = f[0][k - 1][0] + max(0, a[2] - a[1] + 1);
            //    cout << f[2][1][1] << endl;
                ans[k] = min(ans[k], f[2][k][1]);
                continue;
            }
            //f[i][k][0] = min(f[i][k][0], min(f[i - 2][k][1], f[i - 2][k][0]));
            //ans[k] = min(ans[k], f[i][k][0]);
            //cout << ans[k] << endl;
            f[i + 1][k][1] = min(f[i - 2][k - 1][0], f[i - 2][k - 1][1]) + max(0, a[i - 1] - a[i] + 1) + max(0, a[i + 1] - a[i] + 1);
            //cout << f[i - 1][k - 1][1] << endl;
            f[i + 1][k][1] = min(f[i + 1][k][1], f[i - 1][k - 1][1] + max(0, a[i + 1] - a[i] + 1) + max(0, min(a[i - 2] - 1, a[i - 1]) - a[i] + 1)); 
            //cout << f[i + 1][k][1] << endl;
            ans[k] = min(ans[k], f[i + 1][k][1]);
            //cout << "(" << ans[k] << " " << i << ") ";
        }
        //cout << endl;
    }
    //cout << f[5][2][1] << endl;
    for(int i = 1; i <= (n + 1) / 2; i++)
        cout << ans[i] << " ";
    return 0;
}