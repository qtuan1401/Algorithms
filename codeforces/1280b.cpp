#include <bits/stdc++.h>

using namespace std;

const int md = 65;

string s[md];
int n, m, T;
int row[md], col[md];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        int tot = 0;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            cin >> s[i];
            s[i] = '#' + s[i];
            for(int j = 1; j <= m; j++)
                tot += (s[i][j] == 'P');
        }
        if (tot == n * m) 
            cout << "MORTAL\n";
        else if (tot == 0)
            cout << "0\n";
        else {
            //horizontal
            for(int i = 1; i <= n; i++) {
                row[i] = 0;
                for(int j = 1; j <= m; j++)
                    if (s[i][j] == 'P')
                        row[i] = 1;
                row[i] += row[i - 1];
            }
            int res = 4;
            for(int i = 1; i <= n; i++) {
                int cnt = 0;
                for(int j = 1; j <= m; j++)
                    cnt += (s[i][j] == 'P');
                if (cnt == m)
                    continue;
                int dir = (row[i - 1] > 0) + (row[n] - row[i] > 0);
                if (cnt == 0)
                    res = min(res, dir);
                else if (s[i][1] == 'A' || s[i][m] == 'A')
                    res = min(res, dir + 1);
                else res = min(res, dir + 2);
            }
            //vertical
            for(int j = 1; j <= m; j++) {
                col[j] = 0;
                for(int i = 1; i <= n; i++)
                    if (s[i][j] == 'P')
                        col[j] = 1;
                col[j] += col[j - 1];
            }
            for(int j = 1; j <= m; j++) {
                int cnt = 0;
                for(int i = 1; i <= n; i++) 
                    cnt += (s[i][j] == 'P');
                if (cnt == n)
                    continue;
                int dir = (col[j - 1] > 0) + (col[m] - col[j] > 0);
                if (cnt == 0)
                    res = min(res, dir);
                else if (s[1][j] == 'A' || s[n][j] == 'A')
                    res = min(res, dir + 1);
                else res = min(res, dir + 2);
            }
            cout << res << '\n';
        }
    }
    return 0;
}