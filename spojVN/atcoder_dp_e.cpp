#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    long long mw;
    cin >> n >> mw;
    vector < int > w(n), v(n);
    int sumValue = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        sumValue += v[i];
    }
        
    vector < long long > f[n];
    for (int i = 0; i < n; i++) {
        f[i].resize(sumValue + 1);
        fill(f[i].begin(), f[i].end(), mw + 1);
    }

    if (n == 1) {
        cout << v[0];
        return 0;
    }

    f[0][0] = 0;
    f[0][v[0]] = w[0];
    for (int i = 1; i < n; i++) {
        for (int j = sumValue; j >= 0; j--) {
            f[i][j] = f[i - 1][j];
            if (j != sumValue)
                f[i][j] = min(f[i][j], f[i][j + 1]);
            if (j - v[i] >= 0)
                f[i][j] = min(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }

    for (int i = sumValue; i >= 0; i--)
        if (f[n - 1][i] <= mw) {
            cout << i;
            break;
        }
    return 0;
}
