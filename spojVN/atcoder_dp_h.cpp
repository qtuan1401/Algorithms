#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    int w, h;
    vector < string > a;
    cin >> h >> w;
    a.resize(h);
    for (int i = 0; i < h; i++)
        cin >> a[i];
    vector < vector < int > > f;
    f.resize(h);
    for (int i = 0; i < h; i++) {
        f[i].resize(w);
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') continue;
            if (i == 0 && j == 0)
                f[i][j] = 1;
            if (i > 0 && a[i - 1][j] == '.')
                f[i][j] = (f[i][j] + f[i - 1][j]) % MOD;
            if (j > 0 && a[i][j - 1] == '.')
                f[i][j] = (f[i][j] + f[i][j - 1]) % MOD;
        }
    }
    cout << f[h - 1][w - 1];
    return 0;
}