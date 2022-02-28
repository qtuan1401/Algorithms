#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        vector < int > marked(n, 0);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--; c--;
            marked[b] = 1;
        }

        for (int i = 0; i < n; i++)
            if (!marked[i]) {
                for (int j = 0; j < n; j++)
                    if (i != j) cout << i + 1 << " " << j + 1 << '\n';
                break;
            }
    }
    return 0;
}