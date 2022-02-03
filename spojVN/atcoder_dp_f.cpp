#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size();
    int m = t.size();

    vector < vector < int > > f(n, vector < int > (m)); 
    
    for (int i = 0; i < m; i++) {
        if (s[0] == t[i])
            f[0][i] = 1;
        if (i != 0)
            f[0][i] = max(f[0][i], f[0][i - 1]);
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == t[0])
            f[i][0] = 1;
        if (i != 0)
            f[i][0] = max(f[i][0], f[i - 1][0]);
    }
    
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (s[i] == t[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                
    string res = "";
    int x = n - 1, y = m - 1;
    while (x >= 0 && y >= 0) {
        if (s[x] == t[y]) {
            res += s[x];
            x--; y--;
        } else if (x > 0 && f[x - 1][y] == f[x][y]) {
            x--;
        } else 
            y--;
    }
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}