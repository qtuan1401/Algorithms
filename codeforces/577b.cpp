#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int a[MAXN * MAXN];
bool f[MAXN][MAXN];
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    if (n >= m)
        cout << "YES";
    else {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                f[i][j] = 0;
        f[0][a[0]] = 1; 
        if (a[0] == 0) {
            cout << "YES";
            return 0;
        }
        for(int i = 1; i < n; i++) {
            f[i][a[i]] = 1;
            for(int k = 0; k < m; k++) {
                if (f[i - 1][k] == 1 || f[i - 1][(k - a[i] + m) % m] == 1)
                    f[i][k] = 1;
                if (f[i][0] == 1) {
                    cout << "YES";
                    return 0;
                }
            }
        }
        cout << "NO";
    }
    return 0;
}
