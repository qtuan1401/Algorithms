#include <bits/stdc++.h>

using namespace std;

const int MXN = 3e4 + 1;

int f[MXN][500], gem[MXN];
int n, d;

int jump(int i, int j) {
    int nj = j - (d - 250);
    if (i >= MXN) 
        return 0;
    if (f[i][nj] != -1) 
        return f[i][nj];
    int res = 0;
    if (j == 1) 
        res = gem[i] + max(jump(i + j, j), jump(i + j + 1, j + 1));
    else
        res = gem[i] + max(max(jump(i + j - 1, j - 1), jump(i + j, j)), jump(i + j + 1, j + 1));
    f[i][nj] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> d;
    for (int i = 0; i < MXN; i++)
        for (int j = 0; j < 500; j++)
            f[i][j] = -1;
            
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        gem[x]++;
    }
    cout << jump(d, d) << '\n';
    return 0;
}