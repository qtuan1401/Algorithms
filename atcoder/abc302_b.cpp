#include <bits/stdc++.h>

using namespace std;

const string TARGET = "snuke";

const int dx[] = {1, 0, 1, -1, 1, -1, -1, 0};
const int dy[] = {0, 1, 1, -1, -1, 1, 0, -1};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector < string > s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == 's') {
                    for (int id = 0; id < 8; id++) {
                        int ni = i + dx[id] * 4;
                        int nj = j + dy[id] * 4;
                        if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                        string cur = "";
                        cur += s[i][j];
                        int curI = i, curJ = j;
                        for (int k = 0; k < 4; k++) {
                            curI += dx[id];
                            curJ += dy[id];
                            cur += s[curI][curJ];
                        }

                        if (cur == TARGET) {
                            cout << i + 1 << " " << j + 1 << '\n';
                            curI = i; curJ = j;
                            for (int k = 0; k < 4; k++) {
                                curI += dx[id];
                                curJ += dy[id];
                                cout << curI + 1 << " " << curJ + 1 << '\n';
                            }
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}