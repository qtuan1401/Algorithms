#include <bits/stdc++.h>

using namespace std;

const int MXN = 100 + 5;
const long long oo = 1e15;

int a[MXN];
int n, T;

struct matrix {
    long long mat[MXN][MXN];
    matrix operator * (const matrix & a) {
        matrix res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                res.mat[i][j] = -oo;
                for(int k = 0; k < n; k++)
                    res.mat[i][j] = max(res.mat[i][j], mat[i][k] + a.mat[k][j]); 
            }
        }
        return res;
    }
};

matrix calcPow(matrix a, int n) {
    matrix res = a;
    n--;
    while (n > 0) {
        if (n & 1)
            res = res * a;
        a = (a * a);
        n /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> T;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    matrix f;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] < a[i]) {
                f.mat[i][j] = -oo;
            } else {
                f.mat[i][j] = 1;
                for (int k = 0; k < j; k++)
                    if (a[k] <= a[j])
                        f.mat[i][j] = max(f.mat[i][j], f.mat[i][k] + 1);
            }
        }
    }

    matrix res = calcPow(f, T);
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, res.mat[i][j]);
    cout << ans;
    return 0;
}
