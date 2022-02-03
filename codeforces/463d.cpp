#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 10;

int pos[MAXN][10], a[10][MAXN], f[MAXN];
int n, k;

bool check(int u, int v) {
    for(int id = 0; id < k; id++)
        if (pos[u][id] > pos[v][id])
            return false;
    return true;
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            pos[a[i][j]][i] = j;
            //cout << a[i][j] << " " << j << " " << pos[a[i][j]][k] << endl;
        }
    }
    for(int i = 1; i <= n; i++)
        f[i] = 1;
    int res = 1;
    for(int i = 0; i < n; i++) {
        int v = a[0][i];
        for(int j = i - 1; j >= 0; j--) {
            int u = a[0][j];
            if (check(u, v)) 
                f[v] = max(f[v], f[u] + 1);
        }
        res = max(res, f[v]);
    }

    cout << res;
    return 0;
}