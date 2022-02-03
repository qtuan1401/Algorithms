#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL c[35][35];
int a[35];
int n, k;

void solve(int n) {
    int len = 0;
    //cout << n <<" " << k << endl;
    while (n) {
        a[++len] = n % 2;
        n /= 2;
    }
    LL res = 0;
    if ((k >= len && k != 1) || k < 0) {
        cout << "0\n";
        return ;
    }
    for(int i = len - 2; i >= k; i--)
        res += c[i][k];
    //cout << res << " ";
    int cnt = 1;
    //cout << c[1][1] << endl;
    for(int i = len - 1; i >= 1; i--) {
    //    cout << a[i] <<" ";
        if (a[i] == 1) {
        //    cout << k - (len - i + 1 - cnt) << " " << i << " " << c[k - (len - i + 1 - cnt)][i - 1]<< endl;
            if (k - (len - i + 1 - cnt) >= 0) {
                res += c[i - 1][k - (len - i + 1 - cnt)];
            }
            cnt++;
        }
    //    cout << res << endl;
    }
    res += (len - cnt == k);
    res += (k == 1);
    cout << res << '\n';
}

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i <= 31; i++) {
        c[i][0] = 1;
        for(int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    while (cin >> n >> k) {
        if (n == 0) {
            if (k == 1)
                cout << "1\n";
            else cout << "0\n";
        } else solve(n);
    }
    return 0;
}