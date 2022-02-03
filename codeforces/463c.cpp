#include <bits/stdc++.h>

using namespace std;

int n;
long long a[2005][2005], sum[2][4005], val[2], x[2], y[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            sum[0][i - j + n] += a[i][j];
            sum[1][i + j] += a[i][j];
        }
    x[0] = y[0] = x[1] = 1; y[1] = 2;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) {
            a[i][j] = sum[0][i - j + n] + sum[1][i + j] - a[i][j];
            int pos = (i + j) & 1;
            if (val[pos] < a[i][j]) {
                val[pos] = a[i][j];
                x[pos] = i + 1; y[pos] = j + 1;
            }
        }
    cout << val[0] + val[1] << '\n';
    cout << x[0] << " " << y[0] << " " << x[1] << " " << y[1];
    return 0;
}