#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 1, -1, 0, -1, 0, 0, 1};
const int dy[] = {1, 0, 0, 1, 0, -1, -1, 0};

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector < string > s(n);
        for (int i = 0; i < n; i++) cin >> s[i];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool found = false;
                if (s[i][j] == '.') {
                    for (int k = 0; k < 8; k += 2) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni < 0 || ni == n || nj < 0 || nj == m) continue;
                        if (s[ni][nj] == '.') continue;
                        ni = i + dx[k + 1];
                        nj = j + dy[k + 1];
                        if (ni < 0 || ni == n || nj < 0 || nj == m) continue;
                        if (s[ni][nj] == '.') continue;
                        found = true;
                    }

                    if (found == true) {
                        cout << i + 1 << " " << j + 1;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}