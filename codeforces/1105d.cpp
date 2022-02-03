#include<bits/stdc++.h>

using namespace std;
 
typedef pair < int, int > II;
 
const int MXN = 1e3 + 10;
 
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
 
int n, m, p;
int speed[10], ans[10], dst[10][MXN][MXN];
bool vis[MXN][MXN];
string s[MXN];
queue < II > q[10];

void bfs() {
    //cout << "checking";
    for(int turn = 0; turn <= n * m; turn++) {
        for(int i = 1; i <= p; i++) {
            //cout << q[i].size() << endl;
            while (q[i].size()) {
                II cur = q[i].front(); 
                int x = cur.first, y = cur.second;
                //cout << x << " " << y << " " << i << " " << turn << " " << dst[i][x][y]  << " " << turn <<  endl;
                //cout << s[x][y] << endl;
                if (vis[x][y] || s[x][y] == '#') {
                    q[i].pop();
                    continue;
                }
                if (dst[i][x][y] / speed[i] + (dst[i][x][y] % speed[i] != 0) != turn)
                    break;
                //cout << x << " " << y << " " << i << " " << turn << endl;
                q[i].pop();
                //cout << q[i].front().first << " " << q[i].front().second << endl;
                ans[i]++;
                vis[x][y] = true;
                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] != '.' || dst[i][nx][ny] > 0)
                        continue;
                    //cout << i << " " << nx << " " << ny << endl;
                    dst[i][nx][ny] = dst[i][x][y] + 1;
                    q[i].push(II(nx, ny));
                }
            }
        }
    }
    for(int i = 1; i <= p; i++){
        cout << ans[i] << " ";
    }
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> p;
    for(int i = 1; i <= p; i++)
        cin >> speed[i];
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++) {
            if (isdigit(s[i][j])) {
                int num = s[i][j] - '0';
                q[num].push(II(i, j));
                //s[i][j] = '.';
                //cout << num << " " << i << " " << j << endl;
            }
        }
    }
    bfs();
}
