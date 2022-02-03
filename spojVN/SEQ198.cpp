#include <bits/stdc++.h>

using namespace std;

const int md = 2e3 + 10;

int ans[30], mask[30], a[md], num[md], b[md], f[md][(1 << 10) + 5];
int n, res = -1, r;

bool check(int i, int j) {
    return (i - j == 1 || i - j == 8 || i - j == 9);
}

void solve(int i) {
    if (i > min(r, 10)) {
        int rr = 0, len = 0, state = 0;
        for(int i=1;i<=min(r, 10);i++) {
            if (mask[i] == 1)
                ans[++rr] = b[i], len += num[i];
            state = state * 2 + mask[i];
        }
        /*for(int i=1;i<=min(r, 10);i++)
            cout << mask[i] <<" ";
        cout << endl;*/
        for(int i=1;i<=rr;i++)
            for(int j=1;j<i;j++)
                if (check(ans[i], ans[j]))
                    return ;
        res = (res == -1) ? len : max(res, len);
        f[10][state] = len;
        //cout << res <<" " << state << endl;
        //cout << res << endl;
        return ;
    }
    for(int j=0;j<=1;j++) {
        mask[i] = j;
        solve(i + 1);
    }
}

void sub1() {
    solve(1);
    if (n <= 10) {
        cout << n - res;
        exit(0);
    }
}

inline int getbit(int x, int i) {
    return ((x >> i) & 1);
}

bool ok(int x, int state) {
    for(int i=0;i<=8;i++) {
        if (getbit(state, i))
            if (check(b[x], b[x - i - 1]))
                return true;
    }
    return false;
}

void sub2() {
    sub1();
    for(int i=10;i<r;i++)
        for(int j=0;j<=1023;j++) {
            int now = (j * 2) % 1024;
            f[i + 1][now] = max(f[i + 1][now], f[i][j]);
            now = (j * 2 + 1) % 1024;
            if (ok(i + 1, j))
                continue ;
            f[i + 1][now] = max(f[i + 1][now], f[i][j] + num[i + 1]);
    }
    for(int i=10;i<=r;i++)
        for(int j=0;j<=2014;j++)
            res = max(res, f[i][j]);
    cout << n - res;
}

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    a[0] = -1;
    for(int i=1;i<=n;i++)
        if (a[i] !=  a[i - 1])
            b[++r] = a[i], num[r] = 1;
        else
            num[r]++;
    sub2();
    return 0;
}
