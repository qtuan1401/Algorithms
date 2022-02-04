#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main () {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < vector < int > > a(n, vector < int > (n, 0)), cnt(n, vector < int > (n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        int ans = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (cnt[i - 1][j] % 2 == 0) {
                    ans ^= a[i][j];
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                        cnt[ni][nj]++;
                    }
                }
            }
        cout << ans << '\n';
    }
    return 0;
}