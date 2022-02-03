#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int calc( int a, int b, int c ) {
    int res = ( a != b ) + ( a != c ) + ( b != c );
    return res + !res - !a;
}

string zz(char c) {
    if (c == 1)
        return "1";
    if (c == 2)
        return "2";
    if (c == 3)
        return "3";
}

string s;
LL f[2][5][5][5][5];
int now, pre, n;

int main() {
   // freopen("test.in", "r", stdin);
    //freopen("test1.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    LL res = 0;
    s = '#' + s;
    for(int i = 1; i <= n; i++) {
   //     cout << s[i];
        if (s[i] == 'M') 
            s[i] = 1;
        if (s[i] == 'F')
            s[i] = 2;
        if (s[i] == 'B')
            s[i] = 3;
    }
    memset(f[1], -1, sizeof f[1]);
    memset(f[0], -1, sizeof f[0]);
    f[0][0][0][0][0] = 0;
    int now = 1, pre = 0;
    for(int i = 1; i <= n; i++) {
     //   if (i == 4) return 0;
        //memset(f[1], -1, sizeof f[1]);
        for(int a = 0; a <= 3; a++)
            for(int b = 0; b <= 3; b++)
                for(int c = 0; c <= 3; c++)
                    for(int d = 0; d <= 3; d++) {
                        int val = f[pre][a][b][c][d];
                        if (val == -1)
                            continue;
                    //    cout << val << endl;
                        LL r1 = val + calc(b, a, s[i]);
                        LL r2 = val + calc(d, c, s[i]);
                        LL & t1 = f[now][s[i]][a][c][d];
                        t1 = (t1 == -1 ? r1 : max(t1, r1));
                        LL & t2 = f[now][a][b][s[i]][c];
                        t2 = (t2 == -1 ? r2 : max(t2, r2));
                        res = max(res, max(t1, t2));

                    //    cout << val <<" "<< r1 <<" " << r2 << " " << zz(s[i]) <<" " << a << " " << b <<" " << c <<" " << d << endl;
                    } 
        pre = now; now = now ^ 1;
    }
    cout << res;
    return 0;
}