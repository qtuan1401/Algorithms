#include <bits/stdc++.h>

using namespace std;

const int md = 5e3 + 10;

pair< int, pair < int, int > > a[md];
int n, f[md][md], res[md], r;
bool check[md];

int main() {
    //freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first;
    for(int i = 1; i <= n; i++)
        cin >> a[i].second.first, a[i].second.second = i;
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i / 2; j++)
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + a[i].second.first);
    int x = n, y = n / 2;
    while (x != 0 && y != 0) {
        if (f[x][y] == f[x - 1][y - 1] + a[x].second.first) {
            res[++r] = x;
            check[x] = true;
            x--; y--;
        } else x--;
    }
    cout << f[n][n / 2] << '\n';
    for(int i = 1; i <= r; i++) {
        for(int j = res[i] - 1; j >= 1; j--)
            if (!check[j]) {
                cout << a[j].second.second << " ";
                check[j] = true;
                break;
            }
        cout << a[res[i]].second.second << '\n';
    }
    return 0;
}
