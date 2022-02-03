#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int MAXN = 1e5 + 10;

long long f[5][205][5], sum[MAXN][5];
long long res = 1;
int a[MAXN];
int n;

int main() {
    //freopen("test.in", "r", stdin); 
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if (a[0] == -1) {
        for(int num = 1; num <= 200; num++)
            f[0][num][1] = 1;
    } else 
        f[0][a[0]][1] = 1;
    //return 0;
    int id = 1;
    for(int i = 1; i < n; i++) {    
        if (a[i] == -1) {
            long long sum = 0;
            for(int num = 1; num <= 200; num++) {
                f[id][num][1] = sum;
                sum = (sum + f[id ^ 1][num][0] + f[id ^ 1][num][1]) % MOD; 
            }
            sum = 0;
            for(int num = 200; num >= 1; num--) {
                sum = (sum + f[id ^ 1][num][0]) % MOD;
                f[id][num][0] = (sum + f[id ^ 1][num][1]) % MOD;
            }
        } else {
            for(int num = 1; num < a[i]; num++)
                f[id][a[i]][1] = (f[id][a[i]][1] + f[id ^ 1][num][0] + f[id ^ 1][num][1]) % MOD;
            f[id][a[i]][0] = f[id ^ 1][a[i]][1];
            //return 0;
            for(int num = a[i]; num <= 200; num++)
                f[id][a[i]][0] = (f[id][a[i]][0] + f[id ^ 1][num][0]) % MOD;
        }
        id ^= 1;
        for(int num = 1; num <= 200; num++)
            f[id][num][0] = f[id][num][1] = 0;
        //id ^= 1;
    }
    //return 0;
    long long res = 0;
    if (a[n - 1] == -1) {
        for(int i = 1; i <= 200; i++)
            res = (res + f[id ^ 1][i][0]) % MOD;
    } else 
        res = f[id ^ 1][a[n - 1]][0] % MOD;
    cout << res;
    return 0;
}