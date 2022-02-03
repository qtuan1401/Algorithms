#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int findRoot(int * a, int x) {
    if (a[x] < 0)
        return x;
    return a[x] = findRoot(a, a[x]);
}

void merge(int * a, int x, int y) {
    if ((x = findRoot(a, x)) == (y = findRoot(a, y)))
        return ;
    if (a[x] > a[y]) {
        swap(x, y);
    }
    a[x] += a[y];
    a[y] = x;
}

int a[55][55], col[55], row[55];
int n, k;
long long fact[55];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    fact[1] = 1;
    for(int i = 2; i <= 50; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    for(int i = 0; i < n; i++)
        row[i] = col[i] = -1;
    // process row
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            bool check = true;
            for(int t = 0; t < n; t++)
                if (a[i][t] + a[j][t] > k)
                    check = false;
            if (check)
                merge(row, i, j);
            check = true;
            for(int t = 0; t < n; t++)
                if (a[t][i] + a[t][j] > k)
                    check = false;
            if (check)
                merge(col, i, j);
        }
    }
    long long res = 1;
    for(int i = 0; i < n; i++) {
        if (row[i] < 0)
            res = (res * fact[-row[i]]) % MOD;
        if (col[i] < 0)
            res = (res * fact[-col[i]]) % MOD;
    }
    cout << res;
    return 0;
}