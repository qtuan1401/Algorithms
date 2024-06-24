#include <bits/stdc++.h>

using namespace std;

vector < string > s;
vector < vector < bool > > vst;

const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, -1, 0, 1, -1, 1, 1, -1};

int n, m;

void dfs(int u, int v) {
    vst[u][v] = 1;
    for (int dir = 0; dir < 8; dir++) {
        int nu = u + dx[dir];
        int nv = v + dy[dir];
        if (nu < 0 || nu >= n || nv < 0 || nv >= m) continue;
        if (vst[nu][nv] || s[nu][nv] == '.') continue;
        dfs(nu, nv);
    } 
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("../test.in", "r", stdin);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tests = 1;
    while (tests--) {
        cin >> n >> m;
        s.resize(n);
        vst.resize(n, vector < bool > (m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) vst[i][j] = false;
        }
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == '.') continue;
                if (!vst[i][j]) {
                    ans++;
                    dfs(i, j);
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}