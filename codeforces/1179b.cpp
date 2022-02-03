#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
    freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n / 2; i++) {
        for(int j = 1; j <= m; j++) {
            cout << i << " " << j << '\n';
            cout << n - i + 1  << " " << m - j + 1 << '\n';
        }
    }
    if (n & 1) {
        int x = (n + 1) / 2;

        for(int i = 1; i <= (m + 1) / 2; i++) {
            cout << x << " " << i << '\n'; 
            if (i != m - i + 1)
                cout << x << " " << m - i + 1 << '\n';
        }
    }
    return 0;
}