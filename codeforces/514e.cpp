#include<bits/stdc++.h>

using namespace std;

const int LIM = 105;
const int MOD = 1e9 + 7;

struct matrix {
    long long mat[LIM][LIM];
    matrix operator * (const matrix & a) {
        matrix res;
        for(int i = 0; i < LIM; i++) {
            for(int j = 0; j < LIM; j++) {
                res.mat[i][j] = 0;
                for(int k = 0; k < LIM; k++)
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * a.mat[k][j]) % MOD; 
            }
        }
        return res;
    }
};

void calcPow(matrix a, matrix & res, int n) {
    while (n > 0) {
        if (n & 1)
            res = res * a;
        a = (a * a);
        n /= 2;
    }
}

long long a[100005];
int n, k;
matrix mat, res;

int main() {
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        mat.mat[0][a[i] - 1]++;
    for(int i = 1; i < LIM - 1; i++)
        mat.mat[i][i - 1] = 1;
    mat.mat[LIM - 1][0] = mat.mat[LIM - 1][LIM - 1] = 1;
    for(int i = 0; i < LIM; i++)
        res.mat[i][i] = 1;
    calcPow(mat, res, k);
    cout << (res.mat[0][0] + res.mat[LIM - 1][0]) % MOD;
	return 0;
}