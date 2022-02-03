#include <bits/stdc++.h>

using namespace std;

int k;

void solve(int x) {
    for(int i = 2; i <= k + 1; i++)
        cout << 1 + x << " " << i + x << '\n';
    for(int i = 2; i <= k + 2; i++)
        for(int j = i + 1; j <= k + 2; j++) {
            if (i % 2 == 0 && i + 1 == j)
                continue;
            cout << i + x << " " << j + x << '\n';
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> k;
    if (k % 2 == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    if (k == 1) {
        cout << "2 1\n";
        cout << "1 2";
        return 0;
    }
    cout << k * 2 + 4 << " " << (k + 2) * k << '\n';
    solve(0);
    solve(k + 2);
    cout << k + 2 << " " << k * 2 + 4;
    return 0;
}