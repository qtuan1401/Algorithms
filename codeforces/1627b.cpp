#include <bits/stdc++.h>

using namespace std;

int calc(int x, int y, int u, int v) {
    return abs(x - u) + abs(y - v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector < int > a(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i * m + j] = max(max(calc(i, j, 0, 0), calc(i, j, 0, m - 1)), max(calc(i, j, n - 1, 0), calc(i, j, n - 1, m - 1)));
                // cout << i * m + j << " " << a[i * m + j] << endl;
            }
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << '\n';
    }
    return 0;
}