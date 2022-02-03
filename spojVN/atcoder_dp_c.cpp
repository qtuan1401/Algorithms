#include <bits/stdc++.h>

using namespace std;

void resizeVector(vector < int > (&v)[3], int n, int m) {
    for (int i = 0; i < m; i++)
        v[i].resize(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector < int > happy[3];
    resizeVector(happy, n, 3);
    for (int i = 0; i < n; i++)
        cin >> happy[0][i] >> happy[1][i] >> happy[2][i];

    vector < int > f[3];
    resizeVector(f, n, 3);
    for (int i = 0; i < 3; i++)
        f[i][0] = happy[i][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (k == j) continue;
                f[j][i] = max(f[j][i], f[k][i - 1] + happy[j][i]);
            }
        }
    }

    cout << max(f[0][n - 1], max(f[1][n - 1], f[2][n - 1]));
    return 0;
}