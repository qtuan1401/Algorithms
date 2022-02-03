#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;
const int N = (1 << 8) + 10;

int f[N], a[MAXN], g[N];
int n, m;

int getBit(int x, int i) {
    return ((x >> i) & 1);
}

void calc(int row) {
    for(int mask = 1; mask < (1 << m); mask++) {
        int mn = 1e9;
        for(int i = 0; i < m; i++) {
            if (getBit(mask, i)) {
                mn = min(mn, a[i]);
            }
        }
        if (f[mask] < mn) {
            f[mask] = mn;
            g[mask] = row;
        }
    }
}

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[j];
        }
        calc(i);
    }
    //cout << f[5] << " " << f[26] << endl;
    //return 0;
    //cout << f[1] << " " << g[1] << endl;
    int res1 = 0, res2 = 0, res = 0;
    f[0] = 1e9;
    for(int mask = 0; mask < (1 << m); mask++) {
        
        //cout << f[mask] << " " << g[mask] << endl;
        int temp = min(f[mask], f[mask ^ ((1 << m) - 1)]);
        //cout << f[mask] << " " << f[mask ^ ((1 << m) - 1)] << endl;
        if (res < temp) {
            res = temp;
            res1 = g[mask];
            res2 = g[mask ^ ((1 << m) - 1)];
        }
    }
    //cout << res << endl;
    cout << res1 + 1 << " " << res2 + 1;
    return 0;
}