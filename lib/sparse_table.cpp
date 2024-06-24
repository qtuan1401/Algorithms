// codeforces 1142b

#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 2e5 + 10;
 
int ST[MAXN][25], p[MAXN], a[MAXN], num[MAXN], lastNum[MAXN], l[MAXN], pos[MAXN];
int n, m, q;
 
void createSparseTable() {
    for(int i = 1; i <= m; i++)
        ST[i][0] = num[i];
    for(int k = 1; k <= 20; k++)
        for(int i = 1; i <= m; i++)
            ST[i][k] = ST[ST[i][k - 1]][k - 1];
}
 
int getBit(int x, int i) {
    return (x >> i) & 1;
}
 
int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        int x = pos[a[i]];
        int y = x - 1;
        if (y == 0) 
            y = n;
        num[i] = lastNum[p[y]];
        lastNum[a[i]] = i;
        //cout << i << " " << num[i] << endl;
    }
    createSparseTable();
    for(int i = 1; i <= m; i++) {
        int u = i;
        for(int j = 20; j >= 0; j--) {
            if (u == -1)
                break;
            if (getBit(n - 1, j))
                u = ST[u][j];
        }
        l[i] = u;
    }
    for(int i = 1; i <= m; i++)
        l[i] = max(l[i - 1], l[i]);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (l[v] >= u);
    }
}