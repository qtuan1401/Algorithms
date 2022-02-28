#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++)
                cout << i << '\n';
        } else if (n % 2 == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < k; j++)
                    cout << i + j * n << " ";
                cout << '\n';
            }
        }
    }
    return 0;
}