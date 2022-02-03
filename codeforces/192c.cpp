#include <bits/stdc++.h>

using namespace std;

int f[30][30];
int res;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    res = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = s[0] - 'a';
        int y = s[s.size() - 1] - 'a';
        for (int j = 0; j < 26; j++)
            if (f[j][x] > 0)
                f[j][y] = max(f[j][y], f[j][x] + (int)s.size());
        f[x][y] = max(f[x][y], (int)s.size());
        // cout << f[x][y] << endl;
    }
    for (int i = 0; i < 26; i++)
        res = max(res, f[i][i]);

    cout << res;
    return 0;
}