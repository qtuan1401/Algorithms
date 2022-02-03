#include <bits/stdc++.h>

using namespace std;

const int md = 1e6 + 10;

typedef pair < int, int > II;

int dx[] = {0, 1};
int dy[] = {1, 0};

char a[md];
int vis[md], cnt[md], id[md];
II trace[md];
int n, m, now;
queue < II > q;

int getId(int i, int j) {
    return (i - 1) * m + j;
}

void bfs() {
    q.push(II(1, 1));
    while (q.size()) {
        II cur = q.front(); q.pop();
        int x = cur.first, y = cur.second;
        for(int i = 0; i < 2; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || a[getId(nx, ny)] == '#')
                continue;
            if (vis[getId(nx, ny)])
                continue;
            vis[getId(nx, ny)] = true;
            trace[getId(nx, ny)] = II(x, y);
            q.push(II(nx, ny));
        }
    }
}

int check() {
    while (q.size()) {
        II cur = q.front(); q.pop();
        //cout << cur.first << " " << cur.second << endl;
        int x = cur.first, y = cur.second;
        for(int i = 0; i < 2; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || vis[getId(nx, ny)] || a[getId(nx, ny)] == '#')
                continue;
            vis[getId(nx, ny)] = true;
            int temp = id[getId(nx, ny)];
            if (temp > 0)
                now = max(now, temp);
            else q.push(II(nx, ny));
        }
    }
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            cin >> a[getId(i, j)];
    
    bfs();

    if (!vis[getId(n, m)])
        cout << 0;
    else {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                vis[getId(i, j)] = false;
        vector < II > path;
        II cur = II(n, m);
        path.push_back(cur);
        do {
            II np = trace[getId(cur.first, cur.second)];
            path.push_back(np);
            cur = np; 
        } while (cur != II(1, 1));
        reverse(path.begin(), path.end());
        for(int i = 0; i < path.size(); i++)
            id[getId(path[i].first, path[i].second)] = i + 1;
        int res = 2;
        now = 0;
        for(int i = 0; i < path.size() - 1; i++) {
            //cout << "(" << path[i].first << " " << path[i].second << " " << now << ") ";
            II cur = path[i];
            if (cur != II(1, 1) && now <= id[getId(cur.first, cur.second)]) {
                cout << 1;
                return 0;
            }
            q.push(cur);
            check();
        }

        cout << res;
    }
    return 0;
}