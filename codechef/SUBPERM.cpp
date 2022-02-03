#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (n == 1 && k == 1) {
            cout << "1\n";
            continue;
        }
        if (k == 1) {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i < k; i++)
            cout << i << " ";
        for (int i = n; i >= k; i--)
            cout << i << " ";
        cout << '\n';
    }
    return 0;
}