#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0};
int dy[] = {0, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int w, h;
    cin >> w >> h;

    vector < string > s(w);
    for (int i = 0; i < w; i++) 
        cin >> s[i];
    
    vector < vector < int > > f(w, vector < int > (h, -1));
    f[0][0] = 1;
    int res = 1;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (f[i][j] == -1) continue;
            for (int k = 0; k < 2; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= w || nj >= h) continue;
                if (s[ni][nj] == '#') continue;
                f[ni][nj] = max(f[ni][nj], f[i][j] + 1);
                res = max(res, f[ni][nj]);
            }
        }
    }
    cout << res;
    return 0;
}