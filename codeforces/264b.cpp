#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int c[MXN], pos[MXN];
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for(int j = 1; j * j <= x; j++)
            if (x % j == 0) {
                c[i] = max(c[i], c[pos[x / j]] + 1);
                if (j > 1)
                    c[i] = max(c[i], c[pos[j]] + 1);
                res = max(res, c[i]);
                pos[j] = pos[x / j] = i;
            }
    }
    cout << res;
    return 0;
}
