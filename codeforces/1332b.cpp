#include <bits/stdc++.h>

using namespace std;

const int LIM = 1e3 + 10;

vector < int > adj[LIM];
int color[LIM], gcd[LIM][LIM];
bool vst[LIM];

int getGcd(int x, int y) {
    if (y == 0)
        return x;
    return getGcd(y, x % y);
}

void dfs(int u, int c) {
    color[u] = c;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (color[v])
            continue;
        dfs(v, c);
    }
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            gcd[i][j] = getGcd(i, j);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i]; 
        for (int i = 1; i <= 1000; i++)
            color[i] = 0;
        int cnt = 0;
        for (int j = 2; j <= 1000; j++) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (a[i] % j == 0 && !color[a[i]]) {
                    if (!found)
                        cnt++;
                    color[a[i]] = cnt;
                    found = true;
                }
            }
        }
        cout << cnt << '\n';
        for (int i = 0; i < n; i++)
            cout << color[a[i]] << " ";
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < n; j++)
        //         if (color[a[i]] == color[a[j]])
        //             if (gcd[a[i]][a[j]] == 1) {
        //                 cout << "false\n";
        //                 cout << a[i] << " " << a[j] << " " << color[a[i]] << " " << color[a[j]] << endl;
        //             }
        cout << '\n';
    }
    return 0;
}