#include <bits/stdc++.h>

using namespace std;

const int MXN = 105;

int a[MXN][MXN], w[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < (n * (n - 1)) / 2 - 1; i++) {
        int x, y;
        cin >> x >> y;
        a[max(x, y)][min(x, y)]++;
        w[x]++;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++)
            if (a[i][j] == 0) {
                if (w[i] > w[j])
                    cout << i << " " << j;
                else cout << j << " " << i;
            }
    return 0;
}