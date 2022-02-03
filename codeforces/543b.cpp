#include <bits/stdc++.h>

using namespace std;

const int MXN = 3e3 + 10;
const int INF = 1e5;

vector < int > adj[MXN];
queue < int > q;
int n, m;
int dist[MXN][MXN];

void bfs(int s) {
    q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (dist[s][v] < INF)
                continue;
            dist[s][v] = dist[s][u] + 1;
            q.push(v);
        }
    }
}

inline bool check(int u, int x, int y, int v, int val) {
    return (dist[u][x] + dist[x][y] + dist[y][v] <= val);
}

int solve(int s1, int t1, int l1, int i, int j, int s2, int t2, int l2) {
    if (check(s1, i, j, t1, l1) && check(s2, i, j, t2, l2)) 
        return dist[s1][i] + dist[s2][i] + dist[i][j] + dist[j][t1] + dist[j][t2];
    else return INF;
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dist[i][j] = INF;
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        bfs(i);
    }

    int s1, t1, l1, s2, t2, l2;
    cin >> s1 >> t1 >> l1;
    cin >> s2 >> t2 >> l2;

    if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
        cout << "-1";
        return 0;
    }

    int mn = dist[s1][t1] + dist[s2][t2];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            mn = min(mn, solve(s1, t1, l1, i, j, s2, t2, l2));
            mn = min(mn, solve(s1, t1, l1, i, j, t2, s2, l2));
            mn = min(mn, solve(t1, s1, l1, i, j, s2, t2, l2));
            mn = min(mn, solve(s1, t1, l1, i, j, t2, s2, l2));
        }
    //cout << mn << endl;
    cout << m - mn;
    return 0;
}