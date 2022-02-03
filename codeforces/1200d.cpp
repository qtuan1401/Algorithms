#include <bits/stdc++.h>

using namespace std;

const int md = 2e3 + 10;

int n, k;
int rowL[md], rowR[md], row[md], colL[md], colR[md], col[md];
int a[md][md], sumRow[md][md], sumCol[md][md];

void calcRow() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            rowL[j] = rowL[j - 1] + a[i][j];
        for(int j = n; j >= 1; j--)
            rowR[j] = rowR[j + 1] + a[i][j];
        row[i] = row[i - 1] + (rowL[n] == n);
        for(int j = 0; j <= n - k; j++) 
            sumRow[i][j] = sumRow[i - 1][j] + (rowL[j] + rowR[j + k + 1] == n - k);
    }
}

void calcCol() {
    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= n; i++)
            colL[i] = colL[i - 1] + a[i][j];
        for(int i = n; i >= 1; i--)
            colR[i] = colR[i + 1] + a[i][j];
        col[j] = col[j - 1] + (colL[n] == n);
        for(int i = 0; i <= n - k; i++) 
            sumCol[i][j] = sumCol[i][j - 1] + (colL[i] + colR[i + k + 1] == n - k);
        
    }
}

int solve() {
    int ans = 0;
    for(int i = 1; i <= n - k + 1; i++) {
        for(int j = 1; j <= n - k + 1; j++) {
            int res = 0;
            res += row[i - 1] + max(0, row[n] - row[i + k - 1]) + col[j - 1] + max(0, col[n] - col[j + k - 1]);
            res += sumRow[i + k - 1][j - 1] - sumRow[i - 1][j - 1] + sumCol[i - 1][j + k - 1] - sumCol[i - 1][j - 1];
            ans = max(ans, res);
            //cout << i << " "  << j << " " << i + k - 1  << " " << j + k - 1 << " " << res << endl;
            //cout << sumRow[i + k - 1][j - 1] - sumRow[i - 1][j - 1] << " " << sumCol[i - 1][j + k - 1] - sumCol[i - 1][j - 1] << endl;
            //cout << row[i - 1] + max(0, row[n] - row[i + k - 1]) << " " << col[j - 1] + max(0, col[n] - col[j + k - 1]) << endl;
        }
    }
    return ans;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            a[i][j] = (c == 'W');
        }
    }
    calcRow(); calcCol();
    cout << solve();
    return 0;
}