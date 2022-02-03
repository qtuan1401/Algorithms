#include <bits/stdc++.h>

using namespace std;

int n, q, block;
int a[5][100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        if (a[x][y] == 1) {
            a[x][y] = 0;
            block -= (a[x ^ 1][y]) + (a[x ^ 1][y - 1]) + (a[x ^ 1][y + 1]);
        } else {
            a[x][y] = 1;
            block += (a[x ^ 1][y]) + (a[x ^ 1][y - 1]) + (a[x ^ 1][y + 1]);
        }
        if (block)
            cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}