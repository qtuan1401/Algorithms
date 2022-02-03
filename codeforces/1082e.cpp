#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;

typedef pair < int, int > II;

int n, c, res;
int f[MAXN], a[MAXN], pNum[MAXN], prePos[MAXN], sum[MAXN];

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> c;
    for(int i = 0; i < MAXN; i++)
        pNum[i] = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i] = (a[i] == c);
        if (i > 0)
            sum[i] += sum[i - 1];
        if (a[i] != c) {
            prePos[i] = pNum[a[i]];
            pNum[a[i]] = i;
            if (prePos[i] == -1) 
                f[i] = 1;
            else 
                f[i] = max(f[prePos[i]] + 1 - (sum[i] - sum[prePos[i]]), 1);
            res = max(res, f[i]);
        }
    }
    cout << sum[n - 1] + res;
    return 0;
}