#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e3 + 10;
const long long INF = 2e18;

typedef pair < int, int > II;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int n, m, t;
string s[MXN];
queue < II > q;
long long f[MXN][MXN];

void bfs() {
    while (q.size()) {
        II cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        //cout << x << " * " << y << endl;
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            //cout << nx << " " << ny << " " << f[nx][ny] << endl;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || f[nx][ny] < INF)
                continue;
            //cout << nx << " * " << ny << endl;
            f[nx][ny] = f[x][y] + 1;          
            q.push(II(nx, ny));  
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            f[i][j] = INF;
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            for(int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (s[x][y] == s[nx][ny]) {
                    f[x][y] = f[nx][ny] = 0;
                    q.push(II(x, y));
                    q.push(II(nx, ny));
                }
            }
        }
    }

    bfs();

    while (t--) {
        int x, y;
        long long q;
        cin >> x >> y >> q;
        x--; y--;
        q -= f[x][y];
        if (q < 0)
            cout << s[x][y];
        else if (q & 1)
            cout << (1 - (s[x][y] - '0'));
        else
            cout << s[x][y];
        cout << '\n'; 
    }
    return 0;
}