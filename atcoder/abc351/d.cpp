#include <bits/stdc++.h>

using namespace std;

template < class T >
void resetVec(vector < T > & a, int sz, T val) {
    a.clear();
    a.resize(sz, val);
}

typedef long double ld;
typedef long long ll;
typedef pair < int, int > pii;

vector < string > s;
vector < vector < int > > marked;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;

void dfs(int u, int v, int & res, int col) {
    marked[u][v] = 1;

    for (int dir = 0; dir < 4; dir++) {
        int nu = u + dx[dir];
        int nv = v + dy[dir];
        if (nu < 0 || nu >= n || nv < 0 || nv >= m) continue;

        if (marked[nu][nv] == 0 || (marked[nu][nv] != 1 && marked[nu][nv] != col)) res++;
        if (marked[nu][nv] != 0) {
            if (marked[nu][nv] != 1) {
                marked[nu][nv] = col;
            }
            continue;
        }

        dfs(nu, nv, res, col);
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
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        resetVec < vector < int > >(marked, n, vector < int > (m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == '.') continue;
                marked[i][j] = 2;
                for (int dir = 0; dir < 4; dir++) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    marked[ni][nj] = 2;
                }
            }
        }

        int ans = 1, col = 3;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (marked[i][j] != 0) continue;
                int tot = 1;
                dfs(i, j, tot, col);
                col++;
                ans = max(ans, tot);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}